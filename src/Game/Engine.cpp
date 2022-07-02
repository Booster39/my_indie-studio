/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-abdoulaye.doucoure
** File description:
** Engine
*/

#include "Engine.hpp"
#include "Serialize.hpp"

Engine::Engine()
{
    // _display
    _camera = { { 0.0f, 20.0f, 5.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f }, 45.0f, 0 };

    _startDrawing = false;
    _map.initMap();
    _bombManager.initBombManager();
    // _menu.initMenu();

    // l'appelle pas ici mais dans le menu avec le bon nb player
}

Engine::~Engine()
{
}

bool Engine::getbLoad()
{
    return b_loaded;
}

void Engine::setbLoad(bool _b_loaded)
{
    b_loaded = _b_loaded;
};

std::string Engine::getFilename()
{
    return filename;
}

void Engine::setFilename(std::string _filename)
{
    filename = _filename;
}

void Engine::SaveGame() {

    std::vector < Vector3 > brick = _map.getMapBrick();
    Vector3 BlockSize = _map.getBlockSize();

    std::vector < PositionClass > m_brick;

    for (int i = 0; i < brick.size(); i++) {
        PositionClass p(brick[i].x, brick[i].y, brick[i].z);
        m_brick.push_back(p);
    }
    int nbPlayer = 4;

    ofstream file(getFilename(), ios::binary);
    std::array < int, 195 > myMap = _map.getMap();

    std::vector<Vector3> myV;

    for (int i = 0; i < _players.size(); i++) {
        myV.push_back(_players[i]->getPlayerPos());
    }

    GameLoader s(myV, m_brick);
    s.setMap(_map.getMap());

    file << s;

    file.close();
}

void Engine::LoadGame(int *nbPlayer)
{
    GameLoader s2;

    ifstream file_read(getFilename(), ios::binary);

    if (file_read.is_open()) {
        file_read >> s2;
        file_read.close();

        _map.setMap(s2.m_intArray);
        int i = 0;

        _players.erase(_players.begin() + 1);

        int playerNb = 0;
        for (auto p: s2.m_pos) {
            playerNb++;
        }
        *nbPlayer = playerNb;
        std::cout << nbPlayer;
        createPlayers(playerNb);

        for (auto p: s2.m_pos) {
            Vector3 newPos;
            newPos.x = p.x;
            newPos.y = p.y;
            newPos.z = p.z;
            _players[i++]->setPlayerPos(newPos);
            std::cout << "hnfoafboiaebf" << std::endl;
            std::cout << newPos.x << " Z :" << newPos.z << std::endl;
        }

        for (auto p: s2.m_brick) {
            Vector3 newPos;
            newPos.x = p.x;
            newPos.y = p.y;
            newPos.z = p.z;
            _brickPos.push_back(newPos);
        }
        _map.setMapBrick(_brickPos);
    }
}


void Engine::runGame(void)
{
    Vector3 BombPos = { 0 };
    int nbPlayers = 0;

    SetTargetFPS(60);
    InitAudioDevice();
    while (!WindowShouldClose()) {
        UpdateCamera(&_camera);
        if (!_startDrawing) {
            _menu.runMenu(&_startDrawing, &_isLoad, &nbPlayers);
            createPlayers(nbPlayers);
        }

        if (IsKeyPressed(KEY_ENTER)) {
            SaveGame();
        }

        if (_isLoad == true) {
            if (getbLoad() == false) {
                LoadGame(&nbPlayers);
                setbLoad(true);
            }
        }

        updatePlayers();
        if (_startDrawing) {
            startDrawing();
            _map.drawMap();
            _bombManager.draw(_map, _players);
            drawPlayers();
            endDrawing(nbPlayers);
        }
    }
    CloseAudioDevice();
    CloseWindow();
}

void Engine::winCondition(int nbPlayers, uVector<Player> &player)
{
    int count = nbPlayers;
    int index = 0;

    for (int i = 0; i < nbPlayers; i++) {
        if (player[i]->getPlayerLife() == false) count--;
        else index = i + 1;
    }

    if (count == 1 && nbPlayers != 1) {
        DrawText(TextFormat("PLAYER %d WON !", index),  550, 400, 100, RED);
    }
}

void Engine::startDrawing(void)
{
    BeginDrawing();
    ClearBackground(WHITE);
    BeginMode3D(_camera);
}

void Engine::endDrawing(int nbPlayers)
{
    //Unload
    EndMode3D();
    winCondition(nbPlayers, _players);
    DrawFPS(10, 10);
    EndDrawing();
    // UnloadTexture(texture);
}

void Engine::createPlayers(int nbPlayers)
{
    const char *modelPaths[4] = {
        "assets/Models/textures/WhiteBomberMan.png",
        "assets/Models/textures/BlackBomberMan.png",
        "assets/Models/textures/GreenBomberMan.png",
        "assets/Models/textures/OrangeBomberMan.png"
    };
    Vector3 positions[4] = {
        { -6.0f, 1.0f, -5.5f },
        { 6.0f, 1.0f, 4.5f },
        { 6.0f, 1.0f, -5.5f },
        { -6.0f, 1.0f, 4.5f }
    };
    KeyboardKey keybindings[3][5] = {
        { KEY_E, KEY_Q, KEY_W, KEY_TWO, KEY_R },
        { KEY_K, KEY_H, KEY_J, KEY_U, KEY_L },
        { KEY_C, KEY_Z, KEY_X, KEY_S, KEY_V },
    };

    for (int i = 0; i < nbPlayers; i++) {
        std::unique_ptr<Player> player = std::make_unique<Player>();

        player->initPlayer(modelPaths[i]);
        player->setPlayerPos(positions[i]);
        if (i > 0) {
            player->setPlayerKey(keybindings[i - 1][0], keybindings[i - 1][1], keybindings[i - 1][2], keybindings[i - 1][3], keybindings[i - 1][4]);
        }
        _players.push_back(std::move(player));
    }
}

void Engine::updatePlayers()
{
    for (size_t i = 0; i < _players.size(); i++) {
            _players[i]->update(_map, _bombManager);
    }
}

void Engine::drawPlayers()
{
    for (size_t i = 0; i < _players.size(); i++) {
        if (_players[i]->getPlayerLife()) _players[i]->draw();
    }
}