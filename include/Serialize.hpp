#pragma once

#ifndef SERIALIZE_HPP_
#define SERIALIZE_HPP_

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <array>
#include <fstream>
#include <sstream>
#include <cassert>
#include "Map.hpp"
#include "Player.hpp"

using namespace std;

typedef unsigned char byte_t;
typedef std::vector<byte_t> buffer;

std::size_t object_size(const char* s) {
    return strlen(s);
};

template<typename T>
std::size_t object_size(T const& obj) {
    return sizeof(obj);
};

template<typename StreamType,typename T>
void  serializeA(StreamType& s,const T& obj) {
    std::size_t size = object_size(obj);
    buffer buf(size);

    byte_t const* obj_begin = reinterpret_cast<byte_t const*>(&obj);
    std::copy(obj_begin, obj_begin + size, ostreambuf_iterator<char>(s));

};

template<typename StreamType,typename T, size_t size>
void  deserializeA(StreamType& s,std::array<T,size>& data) {

    s.read(
		reinterpret_cast<char*>(&data),
		sizeof(T) * size
	);
}

template<typename StreamType>
void serialise(StreamType& s, const int& t)
{
    
    s.write(reinterpret_cast<char const*>(&t), sizeof(t));
}

template<typename StreamType>
void serialiseFloat(StreamType& s, const float& t)
{
    
    s.write(reinterpret_cast<char const*>(&t), sizeof(t));
}

template<typename StreamType>
void deserialise(StreamType& s, int& t)
{
    s.read(reinterpret_cast<char*>(&t), sizeof(t));
}

template<typename StreamType>
void deserialiseFloat(StreamType& s, float& t)
{
    s.read(reinterpret_cast<char*>(&t), sizeof(t));
}

template<typename StreamType, typename T, typename Alloc>
void serialise(StreamType& s, const T& t)
{
    s << t.size() << " " << t;
}

template<typename StreamType, typename T, typename Alloc>
void deserialise(StreamType& s, T& t)
{
    t = "";

    typename T::size_type len;
    s >> len;

    for(std::size_t i = 0; i < len; ++i)
    {
        typename T::value_type c;
        s >> c;
        t += c;
    }
}

template<typename StreamType, typename T, typename Alloc>
void serialise(StreamType& s, const std::vector<T, Alloc>& t)
{
    s << t.size() << " ";
    for(const T& tt : t)
    {
        s << tt << " ";
    }
}

template<typename StreamType, typename T>
void _serialise(StreamType& s, T t)
{
    serialise(s,t.x);
    serialise(s,t.y);
    serialise(s,t.z);
}

template<typename StreamType, typename T, typename Alloc>
void deserialise(StreamType& s, std::vector<T, Alloc>& t)
{
    using VecType = std::vector<T, Alloc>;
    t.clear();

    typename VecType::size_type len;
    s >> len;
    for(std::size_t i = 0; i < len; ++i)
    {
        typename VecType::value_type c;
        s >> c;
        t.push_back(c);
    }
}

template<typename StreamType,typename POD>
void serialize2(StreamType& s, std::vector<POD> const& v)
{
    auto size = v.size();
    
    s.write(reinterpret_cast<char const*>(&size), sizeof(size));
    s.write(reinterpret_cast<char const*>(v.data()), v.size() * sizeof(POD));
}

template<typename StreamType,typename POD>
void deserialize2(StreamType& s,  std::vector<POD>& v)
{
    decltype(v.size()) size;
    s.read(reinterpret_cast<char*>(&size), sizeof(size));
    v.resize(size);
    s.read(reinterpret_cast<char*>(v.data()), v.size() * sizeof(POD));
}

class PositionClass {       
    public: 
    PositionClass(float _x,float _y,float _z): x(_x),y(_y),z(_z){}
    PositionClass(Vector3 v): x(v.x), y(v.y), z(v.z) {}
    PositionClass(): x(0),y(0),z(0){}
    float x;   
    float y;  
    float z;  
    
    friend std::ostream& operator<<(std::ostream& outputStream, const PositionClass& instance) 
    { 
        serialiseFloat(outputStream, instance.x);
        serialiseFloat(outputStream, instance.y);
        serialiseFloat(outputStream, instance.z); 
        return outputStream; 
    } 

    friend std::istream& operator>>(std::istream& inputStream, PositionClass& instance) 
    { 
        deserialiseFloat(inputStream, instance.x);
        deserialiseFloat(inputStream, instance.y);
        deserialiseFloat(inputStream, instance.z); 
        return inputStream; 
    }
};

class GameLoader
{
public:
    GameLoader();

    GameLoader(std::vector<Vector3> v, std::vector<PositionClass> _m_brick);

    GameLoader(std::array<int, 195> _map, std::vector<Vector3> v):
    m_intArray (_map)
    {
        arrayToVector(v);
    }

    std::vector<PositionClass> m_pos;
    std::vector<PositionClass> m_brick;
    std::array<int, 195> m_intArray;

    void arrayToVector(std::vector<Vector3> v) {
        m_pos.clear();
        for (auto c: v) {
            PositionClass p(c);
            m_pos.push_back(p);
        }
    }

    void setMap(std::array<int, 195> _map) {
        m_intArray = _map;
    }

    friend std::ostream& operator<<(std::ostream& outputStream, const GameLoader& instance) 
    {
        serialize2(outputStream, instance.m_pos); 
        serializeA(outputStream, instance.m_intArray);
        serialize2(outputStream, instance.m_brick);
        return outputStream; 
    } 

    friend std::istream& operator>>(std::istream& inputStream, GameLoader& instance) 
    {
        deserialize2(inputStream, instance.m_pos); 
        deserializeA(inputStream, instance.m_intArray);
        deserialize2(inputStream, instance.m_brick); 
        return inputStream; 
    }
};

GameLoader::GameLoader()
{

}

GameLoader::GameLoader(std::vector<Vector3> v, std::vector<PositionClass> _m_brick)
{
    m_brick = _m_brick;
    arrayToVector(v);
}

#endif