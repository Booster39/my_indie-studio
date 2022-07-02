/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-abdoulaye.doucoure
** File description:
** Main
*/

#ifndef MAIN_HPP_
#define MAIN_HPP_

#include <iostream>
#include <raylib.h>
#include <atomic>
#include "pthread.h"
#include <time.h>
#include "Map.hpp"
#include "BombManager.hpp"
#include "Player.hpp"

typedef enum GameScreen
{
    LOGO,
    TITLE,
    PAUSE,
    GAMEPLAY,
    ENDING,
    CHOICEPLAY,
    LOAD
} GameScreen;

class Menu {
    public:
        Menu();
        ~Menu();
        void setscreenWidth(int);
        int getscreenWidth();
        void setscreenHeight(int);
        int getscreenHeight();
        void initMenu();
        Map map;
        Camera _camera;

    void initButton();
    void initHeightAndWidthButton();
    void initFrame();
    void initSource();
    void initButtonPosition();
    void initState();
    void initAction();
    void initScreen();
    void initSound();
    void initMouse();
    void initImage();
    void initTexture();
    void unloadImage();
    void initVect();
    void initCountScreen();
    void startIntro();
    void setAction();
    void pressButton();
    void setNbPlayer(int nbPlayer);
    int getNbPlayer();
    void runMenu(bool *startDrawing, bool *isLoad, int *nbPlayer);
        //const char link[16] = "src/parrots.png";

    private:

    uVector<Player> _players;
    int screenWidth;
    int screenHeight;
    GameScreen currentScreen;
    int framesCounter;
    bool startGame;
    Image pause;
    Image game;
    Sound fxButton;
    Music music;
    Vector2 mouse;
    Texture2D tex;
    Texture2D texture;
    Texture2D texturep;
    Texture2D textureg;
    Vector2 positionp;
    Vector2 positiong;
    Vector2 vec;
    Vector2 vect;
    Texture2D ExitButton;
    Texture2D LoadButton;
    Texture2D NewGameButton;
    Texture2D ContinueButton;
    Texture2D SaveButton;
    Texture2D MusicButton;
    Texture2D GameSoundButton;
    Texture2D ContinueButtonPause;
    Texture2D SaveButtonPause;
    Texture2D ExitButtonPause;
    Texture2D ReplayButtonWin;
    Texture2D ExitButtonWin;
    Texture2D rightFlecheButton;
    Texture2D leftFlecheButton;
    Texture2D continueChoiceButton;

    int nbPlayer;

    float frameExit;
    float frameLoad;
    float frameContinue;
    float frameNewGame;
    float frameGameSound;
    float frameMusic;
    float frameSave;
    float frameContinuePause;
    float frameExitPause;
    float frameReplayPause;
    float frameExitWin;
    float frameReplayWin;
    float frameRight;
    float frameLeft;
    float frameContinueChoice;

    Rectangle sourceExit;
    Rectangle sourceLoad;
    Rectangle sourceContinue;
    Rectangle sourceSave;
    Rectangle sourceMusic;
    Rectangle sourceGameSound;
    Rectangle sourceNewGame;
    Rectangle sourceExitPause;
    Rectangle sourceContinuePause;
    Rectangle sourceSavePause;
    Rectangle sourceExitWin;
    Rectangle sourceReplayWin;
    Rectangle sourceRight;
    Rectangle sourceLeft;
    Rectangle sourceContinueChoice;


    Rectangle btnExit;
    Rectangle btnNewGame;
    Rectangle btnLoad;
    Rectangle btnContinue;
    Rectangle btnSave;
    Rectangle btnMusic;
    Rectangle btnGameSound;
    Rectangle btnExitPause;
    Rectangle btnContinuePause;
    Rectangle btnSavePause;
    Rectangle btnExitWin;
    Rectangle btnReplayWin;
    Rectangle btnRightPl;
    Rectangle btnLeftPl;
    Rectangle btnContinueChoice;

    int ExitState;
    int ExitStatePause;
    int ExitStateWin;
    int LoadState;
    int ContinueState;
    int ContinueStatePause;
    int SaveState;
    int MusicState;
    int GameSoundState;   
    int NewGameState;
    int SaveStatePause;
    int ReplayStateWin;
    int rightState;
    int leftState;
    int continueChoiceState;
             // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
    
    bool ExitAction;
    bool ExitActionPause;
    bool ExitActionWin;
    bool LoadAction;       // Button action should be activated
    bool SaveAction;
    bool NewGameAction;
    bool GameSoundAction;
    bool ContinueAction;
    bool ContinueActionPause;
    bool SaveActionPause;
    bool ReplayActionWin;
    bool MusicAction;
    bool rightAction;
    bool leftAction;
    bool continueChoiceAction;
};

#endif /* !MAIN_HPP_ */
