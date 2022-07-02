/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-abdoulaye.doucoure
** File description:
** Engine
*/

#ifndef ENGINE_HPP_
#define ENGINE_HPP_

#include <string.h>
#include <assert.h>
#include <queue>
#include <random>
#include <iomanip>
#include <ios>
#include <ostream>
#include "raylib.h"
#include <vector>

#include "Player.hpp"
#include "Map.hpp"
#include "BombManager.hpp"
// #include "Cpu.hpp"
#include "Menu.hpp"

class Engine {
    public:
        Engine();
        ~Engine();
        void runGame(void);

        void SaveGame(void);
        void LoadGame(int *nbPlayer);

        bool getbLoad();
        void setbLoad(bool _b_loaded);

        std::string getFilename();
        void setFilename(std::string _filename);

    protected:
    private:
        uVector<Player> _players;
        // Display _display;
        Map _map;
        BombManager _bombManager;
        // Cpu _cpu;
        Menu _menu;
        Camera _camera;
        void startDrawing(void);
        void endDrawing(int nbPlayers);
        void createPlayers(int nbPlayers);
        void createPlayer(int index);
        void updatePlayers();
        void drawPlayers();
        bool _startDrawing;
        void winCondition(int nbPlayers, uVector<Player>&_players);

        bool _isLoad = false;

        std::string filename = "restore.bin";
        bool b_loaded = false;
        std::vector<Vector3> _brickPos;
};

#endif /* !ENGINE_HPP_ */