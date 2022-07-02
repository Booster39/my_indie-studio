/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-abdoulaye.doucoure
** File description:
** Menu
*/

#include "Menu.hpp"

using namespace std;

Menu::Menu()
{
}

Menu::~Menu()
{
     UnloadTexture(texture);
    UnloadTexture(tex);
    UnloadTexture(ExitButton);
    UnloadTexture(LoadButton);
    UnloadTexture(NewGameButton);
    UnloadTexture(ContinueButton);
    UnloadTexture(SaveButton);
    UnloadTexture(MusicButton);
    UnloadTexture(GameSoundButton);
    UnloadTexture(ContinueButtonPause);
    UnloadTexture(SaveButtonPause);
    UnloadTexture(ExitButtonPause);
    UnloadTexture(ReplayButtonWin);
    UnloadTexture(ExitButtonWin);
    UnloadTexture(rightFlecheButton);
    UnloadTexture(leftFlecheButton);
    UnloadTexture(continueChoiceButton);
}
void Menu::initButton()
{
    ExitButton = LoadTexture("src/bomberelement/ExitButton.png");
    LoadButton = LoadTexture("src/bomberelement/LoadButton.png");
    NewGameButton = LoadTexture("src/bomberelement/NewGame.png");
    ContinueButton = LoadTexture("src/bomberelement/ContinueButton.png");
    SaveButton = LoadTexture("src/bomberelement/SaveButton.png");
    MusicButton = LoadTexture("src/bomberelement/MusicButton.png");
    GameSoundButton = LoadTexture("src/bomberelement/GameSound.png");
    ContinueButtonPause = LoadTexture("src/bomberelement/ContinueButton.png");
    SaveButtonPause = LoadTexture("src/bomberelement/SaveButton.png");
    ExitButtonPause = LoadTexture("src/bomberelement/ExitButton.png");
    ReplayButtonWin = LoadTexture("src/bomberelement/NewGame.png");
    ExitButtonWin = LoadTexture("src/bomberelement/ExitButton.png");
    rightFlecheButton = LoadTexture("assets/Menu/fBDroite.png");
    leftFlecheButton = LoadTexture("assets/Menu/fBGauche.png");
    continueChoiceButton = LoadTexture("src/bomberelement/ContinueButton.png");
}

void Menu::initHeightAndWidthButton()
{
    ExitButton.height = 300;
    ExitButton.width = 300;
    ExitButtonPause.height = 300;
    ExitButtonPause.width = 300;
    ExitButtonWin.height = 300;
    ExitButtonWin.width = 300;
    LoadButton.height = 300;
    LoadButton.width = 300;
    SaveButton.height = 300;
    SaveButton.width = 300;
    SaveButtonPause.height = 300;
    SaveButtonPause.width = 300;
    ReplayButtonWin.height = 300;
    ReplayButtonWin.width = 300;
    ContinueButton.height = 300;
    ContinueButton.width = 300;
    ContinueButtonPause.height = 300;
    ContinueButtonPause.width = 300;
    MusicButton.height = 200;
    MusicButton.width = 100;
    GameSoundButton.height = 200;
    GameSoundButton.width = 100;
    NewGameButton.height = 300;
    NewGameButton.width = 300;
    leftFlecheButton.height = 20;
    rightFlecheButton.height = 20;
    leftFlecheButton.width = 20;
    rightFlecheButton.width = 20;
    continueChoiceButton.width = 300;
    continueChoiceButton.height = 300;
}

void Menu::initFrame()
{
    frameExit = (float)ExitButton.height/3;
    frameLoad = (float)LoadButton.height/3;
    frameContinue = (float)ContinueButton.height/3;
    frameNewGame = (float)NewGameButton.height/3;
    frameGameSound = (float)GameSoundButton.height/3;
    frameMusic = (float)MusicButton.height/3;
    frameSave = (float)SaveButton.height/3;
    frameContinuePause = (float)ContinueButtonPause.height/3;
    frameExitPause = (float)ExitButtonPause.height/3;
    frameReplayPause = (float)SaveButtonPause.height/3;
    frameExitWin = (float)ExitButtonWin.height/3;
    frameReplayWin = (float)ReplayButtonWin.height/3;
    frameContinueChoice = (float)continueChoiceButton.height/3;
    frameLeft = (float)leftFlecheButton.height;
    frameRight = (float)rightFlecheButton.height;
}

void Menu::initSource()
{
    sourceExit = { 0, 0, (float)ExitButton.width, frameExit };
    sourceLoad = { 0, 0, (float)LoadButton.width, frameLoad};
    sourceContinue = { 0, 0, (float)ContinueButton.width, frameContinue };
    sourceSave = { 0, 0, (float)SaveButton.width, frameSave};
    sourceMusic = { 0, 0, (float)MusicButton.width, frameMusic };
    sourceGameSound = { 0, 0, (float)GameSoundButton.width, frameGameSound };
    sourceNewGame = { 0, 0, (float)NewGameButton.width, frameNewGame };
    sourceExitPause = { 0, 0, (float)ExitButtonPause.width, frameExitPause };
    sourceContinuePause = { 0, 0, (float)ContinueButtonPause.width, frameContinuePause };
    sourceSavePause = { 0, 0, (float)SaveButtonPause.width, frameReplayPause };
    sourceExitWin = { 0, 0, (float)ExitButtonWin.width, frameExitWin };
    sourceReplayWin = { 0, 0, (float)ReplayButtonWin.width, frameReplayWin };
    sourceContinueChoice = { 0, 0, (float)continueChoiceButton.width, frameContinueChoice};
    sourceLeft = { 0, 0, (float)leftFlecheButton.width, frameLeft};
    sourceRight = { 0, 0, (float)rightFlecheButton.width, frameRight};
}

void Menu::initButtonPosition()
{
    btnExit = { getscreenWidth()/2.0f - ExitButton.width/2.0f - 100, getscreenHeight()/2.0f - ExitButton.height/3/2.0f + 150, (float)ExitButton.width, frameExit };
    btnNewGame = { getscreenWidth()/2.0f - NewGameButton.width/2.0f - 250, getscreenHeight()/2.0f - NewGameButton.height/3/2.0f, (float)NewGameButton.width, frameNewGame };
    btnLoad = { getscreenWidth()/2.0f - LoadButton.width/2.0f + 50, getscreenHeight()/2.0f - LoadButton.height/3/2.0f, (float)LoadButton.width, frameLoad };
    btnContinue = { getscreenWidth()/2.0f - ContinueButton.width/2.0f, getscreenHeight()/2.0f - ContinueButton.height/3/2.0f, (float)ContinueButton.width, frameContinue };
    btnSave = { getscreenWidth()/2.0f - SaveButton.width/2.0f, getscreenHeight()/2.0f - SaveButton.height/3/2.0f, (float)SaveButton.width, frameSave };
    btnMusic = { getscreenWidth()/2.0f - MusicButton.width/2.0f - 450, getscreenHeight()/2.0f - MusicButton.height/3/2.0f + 300, (float)MusicButton.width, frameMusic };
    btnGameSound = { getscreenWidth()/2.0f - GameSoundButton.width/2.0f - 350, getscreenHeight()/2.0f - GameSoundButton.height/3/2.0f + 300, (float)GameSoundButton.width, frameGameSound };
    btnExitPause = { getscreenWidth()/2.0f - ExitButtonPause.width/2.0f, getscreenHeight()/2.0f - ExitButtonPause.height/3/2.0f + 150, (float)ExitButtonPause.width, frameExitPause };
    btnContinuePause = { getscreenWidth()/2.0f - ContinueButtonPause.width/2.0f, getscreenHeight()/2.0f - ContinueButtonPause.height/3/2.0f + 50, (float)ContinueButtonPause.width, frameContinuePause };
    btnSavePause = { getscreenWidth()/2.0f - SaveButtonPause.width/2.0f, getscreenHeight()/2.0f - SaveButtonPause.height/3/2.0f - 50, (float)SaveButtonPause.width, frameReplayPause };
    btnExitWin = { getscreenWidth()/2.0f - ExitButtonWin.width/2.0f, getscreenHeight()/2.0f - ExitButtonWin.height/3/2.0f + 150, (float)ExitButtonWin.width, frameExitWin };
    btnReplayWin = { getscreenWidth()/2.0f - ReplayButtonWin.width/2.0f, getscreenHeight()/2.0f - ReplayButtonWin.height/3/2.0f - 50, (float)ReplayButtonWin.width, frameReplayWin };
    btnContinueChoice = { getscreenWidth()/2.0f - continueChoiceButton.width/2.0f - 50, getscreenHeight()/2.0f+150 - continueChoiceButton.height/3/2.0f, (float)continueChoiceButton.width, frameContinueChoice };
    btnRightPl = { getscreenWidth()/2.0f - rightFlecheButton.width - 375/2.0f, getscreenHeight()/2.0f +55- rightFlecheButton.height/3/2.0f, (float)rightFlecheButton.width, frameRight };
    btnLeftPl = { getscreenWidth()/2.0f - leftFlecheButton.width + 225/2.0f, getscreenHeight()/2.0f +55 - leftFlecheButton.height/3/2.0f, (float)leftFlecheButton.width, frameLeft };

}

void Menu::initState()
{
    ExitState = 0;
    ExitStatePause = 0;
    ExitStateWin = 0;
    LoadState = 0;
    ContinueState = 0;
    ContinueStatePause = 0;
    SaveState = 0;
    MusicState = 0;
    GameSoundState = 0;   
    NewGameState = 0;
    SaveStatePause = 0;
    ReplayStateWin = 0;
    leftState = 0;
    rightState = 0;
    continueChoiceState = 0;
}

void Menu::initAction()
{
    ExitAction = false;
    ExitActionPause = false;
    ExitActionWin = false;
    LoadAction = false;       // Button action should be activated
    SaveAction = false;
    NewGameAction = false;
    GameSoundAction = false;
    ContinueAction = false;
    ContinueActionPause = false;
    SaveActionPause = false;
    ReplayActionWin = false;
    MusicAction = false;
    leftAction = false;
    rightAction = false;
    continueChoiceAction = false;
    nbPlayer = 1;
}

void Menu::initMenu()
{
    initButton();
    initHeightAndWidthButton();
    initFrame();
    initSource();
    initButtonPosition();
    initState();
    initAction();
}

void Menu::initScreen()
{
    setscreenHeight(1080);
    setscreenWidth(1920);
        // InitWindow(getscreenWidth(), getscreenHeight(), "Bomberman");
}

void Menu::setscreenHeight(int s)
{
    screenHeight = s;
}

int Menu::getscreenHeight()
{
    return screenHeight;
}

void Menu::setscreenWidth(int w)
{
    screenWidth = w;
}

int Menu::getscreenWidth()
{
    return screenWidth;
}

void Menu::initSound()
{
    fxButton = LoadSound("src/bomberelement/buttonfx.mp3");
    music = LoadMusicStream("src/bomberelement/2.mp3");
}

void Menu::initMouse()
{
    mouse = { 0.0f, 0.0f };
}

void Menu::initImage()
{
    game = LoadImage("src/bomberelement/backgroundBomberman.png");
    ImageResize(&game, getscreenWidth(), getscreenHeight() + 50);
    pause = LoadImage("src/bomberelement/pauseBomberman.png");
    ImageResize(&pause, getscreenWidth(), getscreenHeight() + 50);
}

void Menu::initTexture()
{
    texture = LoadTextureFromImage(pause);
    tex = LoadTextureFromImage(game);
}

void Menu::unloadImage()
{
    UnloadImage(pause);
    UnloadImage(game);
}

void Menu::initVect()
{
    vec = {(float)(getscreenWidth() / 2 - texture.width / 2 ), (float)(getscreenHeight() / 2 - texture.height / 2 - 20)};
    vect = {(float)(getscreenWidth() / 2 - tex.width / 2 ), (float)(getscreenHeight() / 2 - tex.height / 2 - 20)};
}

void Menu::initCountScreen()
{
    currentScreen = LOGO;
    framesCounter = 0;
}

void Menu::startIntro()
{
    framesCounter++;
            if (framesCounter > 120)
            {
                currentScreen = TITLE;
            }
}

void Menu::setAction()
{
    LoadAction = false;
        ExitAction = false;
        SaveAction = false;
        NewGameAction = false;
        GameSoundAction = false;
        ContinueAction = false;
        MusicAction = false;
}

void Menu::pressButton()
{

            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) 
            {
            LoadState = 2;
            PlaySound(fxButton);
            }
            else LoadState = 1;

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) 
            {
            LoadAction = true;
            currentScreen = PAUSE;
            }
}

static float *delayBuffer = NULL;
static unsigned int delayBufferSize = 0;
static unsigned int delayReadIndex = 2;
static unsigned int delayWriteIndex = 0;

// Audio effect: delay


void Menu::runMenu(bool *startDrawing, bool *isLoad, int *setNbPlayers)
{
    srand(time(0));
    int randomn = (rand() % 10) + 1;
    //randomMusic();

    initScreen();
    // InitAudioDevice();      // Initialize audio device
    initSound();
    initMenu();
    initMouse();
    initImage();
    initTexture();
    unloadImage();
    initVect();
    initCountScreen();

    PlayMusicStream(music);

    bool Pause = false;
    bool fxButtonOff = true;
    startGame = false;

    SetTargetFPS(60);


    while (!*startDrawing)
    {
        UpdateMusicStream(music);
        switch (currentScreen)
        {
        case LOGO:
        {
            startIntro();
        }
        break;
        case TITLE:
        {
        //    if (IsKeyPressed(KEY_SPACE))
        //{
        //    StopMusicStream(music);
        //    PlayMusicStream(music);
        //}

        mouse = GetMousePosition();


        setAction();

        if (CheckCollisionPointRec(mouse, btnLoad))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            {
            LoadState = 2;
            PlaySound(fxButton);
            }
            else LoadState = 1;

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            {
            LoadAction = true;
            currentScreen = LOAD;
            }
        }
        else LoadState = 0;
//pressButton();

if (CheckCollisionPointRec(mouse, btnExit))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) 
            {
                ExitState = 2;
                exit(ExitState);
                PlaySound(fxButton);
            }
            else ExitState = 1;

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            {
                 ExitAction = true;
                PlaySound(fxButton);
            }
        }
        else ExitState = 0;
//pressButton()

        if (CheckCollisionPointRec(mouse, btnNewGame))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) 
            {
            NewGameState = 2;
            }
            else NewGameState = 1;

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) 
            {
            NewGameAction = true;
            currentScreen = CHOICEPLAY;
            }
        }
        else NewGameState = 0;
//pressButton()

if (CheckCollisionPointRec(mouse, btnMusic))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) 
            {
            
                MusicState = 2;
                Pause = !Pause;

            if (Pause) PauseMusicStream(music);
            else ResumeMusicStream(music);
            }
            else MusicState = 1;

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            {
                 MusicAction = true;
                PlaySound(fxButton);
            }
        }
        else MusicState = 0;
//pressButton()

if (CheckCollisionPointRec(mouse, btnGameSound))
        {
            if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
            {
                GameSoundState = 2;
                fxButtonOff = !fxButtonOff;

            }
            else GameSoundState = 1;

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            {
                 GameSoundAction = true;
            }
        }
        else GameSoundState = 0;

//pressButton()

            if (fxButtonOff) PauseSound(fxButton);
            else ResumeSound(fxButton);

        if (fxButtonOff && (LoadAction || ExitAction || NewGameAction || MusicAction || GameSoundAction))
        {
            PlaySound(fxButton);
        }

        // Calculate button frame rectangle to draw depending on button state
        sourceExit.y = ExitState*frameExit;
        sourceLoad.y = LoadState*frameLoad;
        sourceNewGame.y = NewGameState*frameNewGame;
        sourceGameSound.y = GameSoundState*frameGameSound;
        sourceMusic.y = MusicState*frameMusic;
//setButtonFrame()
        }
        break;
        case PAUSE:
        {
            mouse = GetMousePosition();
            ExitActionPause = false;
            SaveActionPause = false;
            ContinueActionPause = false;
            MusicAction = false;
            GameSoundAction = false;

            if (CheckCollisionPointRec(mouse, btnSavePause))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            {
            SaveStatePause = 2;
            //SaveGame();
            }
            else SaveStatePause = 1;

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) 
            {
            SaveActionPause = true;
            }
        }
        else SaveStatePause = 0;

if (CheckCollisionPointRec(mouse, btnContinuePause))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) 
            {
                ContinueStatePause = 2;
                currentScreen = GAMEPLAY;
            }
            else ContinueStatePause = 1;

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            {
                 ContinueActionPause = true;
            }
        }
        else ContinueStatePause = 0;

        if (CheckCollisionPointRec(mouse, btnMusic))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) 
            {
                MusicState = 2;

            //if (Pause) PauseMusicStream(music);
            //else ResumeMusicStream(music);
            }
            else MusicState = 1;

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            {
                 MusicAction = true;
                 Pause = !Pause;
                PlaySound(fxButton);
            }
        }
        else MusicState = 0;

if (Pause) PauseMusicStream(music);
            else ResumeMusicStream(music);

if (CheckCollisionPointRec(mouse, btnGameSound))
        {
            if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
            {
                GameSoundState = 2;
            }
            else GameSoundState = 1;

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            {
                 GameSoundAction = true;
            }
        }
        else GameSoundState = 0;

if (CheckCollisionPointRec(mouse, btnExitPause))
        {
            if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
            {
                ExitStatePause = 2;
                exit(ExitStatePause);
            }
            else ExitStatePause = 1;

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            {
                 ExitActionPause = true;
            }
        }
        else ExitStatePause = 0;

        if (fxButtonOff && MusicAction || GameSoundAction || ContinueActionPause || ExitActionPause || SaveActionPause)
        {
            PlaySound(fxButton);

            // TODO: Any desired action
        }

        sourceContinuePause.y = ContinueStatePause*frameContinuePause;
        sourceSavePause.y = SaveStatePause*frameReplayPause;
        sourceMusic.y = MusicState*frameMusic;
        sourceExitPause.y = ExitStatePause*frameExitPause;
        sourceGameSound.y = GameSoundState*frameGameSound;
        }
        break;
        case GAMEPLAY:
        {
            if (IsKeyPressed(KEY_SPACE))
                currentScreen = PAUSE;
            _camera = { { 0.0f, 20.0f, 5.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f }, 45.0f, 0 };
            UpdateCamera(&_camera);
            *setNbPlayers = nbPlayer;
            *startDrawing = true;
            break;

    //  for (size_t i = 0; i < nbPlayer; i++)
    //  {
    //     _player[i].getRotation();
    //      _player[i].animate();
    //      _player[i].move(map);
    //      _player[i].plantBomb(_bombManager, map);
    //  }
            //if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
            //{
            //    currentScreen = ENDING;
            //}
        }
        break;
        case LOAD:
        {
            *isLoad = true;
            if (IsKeyPressed(KEY_SPACE))
                currentScreen = PAUSE;
            _camera = { { 0.0f, 20.0f, 5.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f }, 45.0f, 0 };
            UpdateCamera(&_camera);
            *setNbPlayers = nbPlayer;
            *startDrawing = true;
            break;
        }
        break;
        case ENDING:
        {

            mouse = GetMousePosition();

        ReplayActionWin = false;
        ExitActionWin = false;


if (CheckCollisionPointRec(mouse, btnExitWin))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            {
            
                ExitStateWin = 2;
                exit(ExitStateWin);
            }
            else ExitStateWin = 1;

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            {
                 ExitActionWin = true;
                PlaySound(fxButton);
            }
        }
        else ExitStateWin = 0;

if (CheckCollisionPointRec(mouse, btnReplayWin))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) 
            {
            
                ReplayStateWin = 2;
                currentScreen = TITLE;
            }
            else ReplayStateWin = 1;

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            {
                 ReplayActionWin = true;
                PlaySound(fxButton);
            }
        }
        else ReplayStateWin = 0;

        if (ExitActionWin || ReplayActionWin)
        {
            PlaySound(fxButton);
            // TODO: Any desired action
        }

        sourceExitWin.y = ExitStateWin*frameExitWin;
        sourceReplayWin.y = ReplayStateWin*frameReplayWin;
        }
        break;
        case CHOICEPLAY:
        {
            mouse = GetMousePosition();
            continueChoiceAction = false;
            leftAction = false;
            rightAction = false;

            if (CheckCollisionPointRec(mouse, btnLeftPl)) {
                if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
                    leftState = 2;
                    //currentScreen = GAMEPLAY;
                } else leftState = 1;

                if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
                    leftAction = true;
                    if (nbPlayer < 4)
                        nbPlayer++;
                    else nbPlayer = 4;
                }
            }
        else leftState = 0;

    if (CheckCollisionPointRec(mouse, btnRightPl))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            {
            rightState = 2;
            //currentScreen = GAMEPLAY;
            }
            else rightState = 1;

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            {
            rightAction = true;
            if (nbPlayer > 1)
                nbPlayer--;
            else nbPlayer = 1;

            }
        }
        else rightState = 0;


if (CheckCollisionPointRec(mouse, btnContinueChoice))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) 
            {
            
                continueChoiceState = 2;
                
            }
            else continueChoiceState = 1;

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            {
                 continueChoiceAction = true;
                 currentScreen = GAMEPLAY;
            }
        }
        else continueChoiceState = 0;

        if (CheckCollisionPointRec(mouse, btnMusic))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) 
            {
            
                MusicState = 2;

            //if (Pause) PauseMusicStream(music);
            //else ResumeMusicStream(music);
            }
            else MusicState = 1;

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            {
                MusicAction = true;
                Pause = !Pause;
                PlaySound(fxButton);
            }
        }
        else MusicState = 0;


if (Pause) PauseMusicStream(music);
            else ResumeMusicStream(music);

if (CheckCollisionPointRec(mouse, btnGameSound))
        {
            if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
            {
                GameSoundState = 2;
                
            }
            else GameSoundState = 1;

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            {
                 GameSoundAction = true;
            }
        }
        else GameSoundState = 0;

        if (fxButtonOff && MusicAction || leftAction || continueChoiceAction || rightAction)
        {
            PlaySound(fxButton);

            // TODO: Any desired action
        }
        sourceContinueChoice.y = continueChoiceState*frameContinueChoice;
        sourceSavePause.y = SaveStatePause*frameReplayPause;
        sourceMusic.y = MusicState*frameMusic;
        sourceGameSound.y = GameSoundState*frameGameSound;
        sourceLeft.y = leftState*frameLeft;
        sourceRight.y = rightState*frameRight;
        }
        break;
        default:
            break;
        }

        BeginDrawing();

        ClearBackground(DARKGRAY);

        switch (currentScreen)
        {
        case LOGO:
        {
            DrawText("WAIT for 2 SECONDS...", 290, 220, 20, GRAY);
        }
        break;
        case TITLE:
        {
            DrawTextureV(tex, vect, WHITE);

            DrawTextureRec(ExitButton, sourceExit, (Vector2){ btnExit.x, btnExit.y}, WHITE);
            DrawTextureRec(LoadButton, sourceLoad, (Vector2){ btnLoad.x, btnLoad.y}, WHITE);
            DrawTextureRec(NewGameButton, sourceNewGame, (Vector2){ btnNewGame.x, btnNewGame.y}, WHITE);
            DrawTextureRec(MusicButton, sourceMusic, (Vector2){ btnMusic.x, btnMusic.y}, WHITE);
            DrawTextureRec(GameSoundButton, sourceGameSound, (Vector2){ btnGameSound.x, btnGameSound.y}, WHITE);

        }
        break;
        case PAUSE:
        {
            DrawTextureV(texture, vec, WHITE);
            DrawTextureRec(MusicButton, sourceMusic, (Vector2){ btnMusic.x, btnMusic.y}, WHITE);
            DrawTextureRec(SaveButtonPause, sourceSavePause, (Vector2){ btnSavePause.x, btnSavePause.y}, WHITE);
            DrawTextureRec(GameSoundButton, sourceGameSound, (Vector2){ btnGameSound.x, btnGameSound.y}, WHITE);
            DrawTextureRec(ContinueButtonPause, sourceContinuePause, (Vector2){ btnContinuePause.x, btnContinuePause.y}, WHITE);
            DrawTextureRec(ExitButtonPause, sourceExitPause, (Vector2){ btnExitPause.x, btnExitPause.y}, WHITE);
        }
        break;
        case GAMEPLAY:
        {
            // BeginMode3D(_camera);
            // map.drawMap();
            // for (size_t i = 0; i < nbPlayer; i++) {
            //     _player[i].draw();
            // }
            // _bombManager.draw(map, _players);
            //DrawRectangle(0, 0, getscreenWidth(), getscreenHeight(), PURPLE);
            //DrawText("GAMEPLAY SCREEN", 20, 20, 40, MAROON);
            //DrawText("PRESS ENTER or TAP to JUMP to ENDING SCREEN", 130, 220, 20, MAROON);
            // EndMode3D();
        //DrawFPS(10, 10);
        }
        break;
        case LOAD:
        {
        }
        break;
        case ENDING:
        {
            DrawRectangle(0, 0, getscreenWidth(), getscreenHeight(), BLUE);
            DrawTextureRec(ReplayButtonWin, sourceReplayWin, (Vector2){ btnReplayWin.x, btnReplayWin.y}, WHITE);
            DrawTextureRec(ExitButtonWin, sourceExitWin, (Vector2){ btnExitWin.x, btnExitWin.y}, WHITE);
        }
        break;
        case CHOICEPLAY:
        {
            DrawText(TextFormat("Nb of Player: %d", nbPlayer), 805, 585, 30, DARKBLUE);
            DrawText(TextFormat("Nb of IA : "), 805, 500, 30, DARKGREEN);
            DrawTextureRec(leftFlecheButton, sourceLeft, (Vector2){ btnLeftPl.x, btnLeftPl.y}, WHITE);
            DrawTextureRec(rightFlecheButton, sourceRight, (Vector2){ btnRightPl.x, btnRightPl.y}, WHITE);
            DrawTextureRec(continueChoiceButton, sourceContinueChoice, (Vector2){ btnContinueChoice.x, btnContinueChoice.y}, WHITE);
            DrawTextureRec(MusicButton, sourceMusic, (Vector2){ btnMusic.x, btnMusic.y}, WHITE);
            DrawTextureRec(GameSoundButton, sourceGameSound, (Vector2){ btnGameSound.x, btnGameSound.y}, WHITE);

        }
        default:
            break;
        }
        EndDrawing();

    }
}