//--------------------------------------------------
//----------HEADERS---------------------------------
//--------------------------------------------------

//custom
#include "system.hpp"

//third party
#include <SDL.h>

//--------------------------------------------------
//----------SYSTEM CLASS----------------------------
//--------------------------------------------------

System::System()
{
    mWindow = nullptr;
    mRenderer = nullptr;

    mRunning = true;

    mCurrentState = nullptr;
    mNextState = nullptr;
    mChangeState = false;
}

System::~System()
{
}

//--------------------------------------------------

bool System::Startup()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        return false;

    mWindow = SDL_CreateWindow("",
                               SDL_WINDOWPOS_CENTERED,
                               SDL_WINDOWPOS_CENTERED,
                               800,
                               600,
                               0);

    if (mWindow == nullptr)
        return false;

    mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);

    if (mRenderer == nullptr)
        return false;

    return true;
}

void System::Cleanup()
{
    SDL_DestroyRenderer(mRenderer);

    SDL_DestroyWindow(mWindow);

    SDL_Quit();
}

//--------------------------------------------------

void System::_Run(State *state)
{
    if (Startup())
    {
        ChangeState(state);

        while (mRunning)
        {
            if (mChangeState)
            {
                if (mCurrentState != nullptr)
                {
                    mCurrentState->Cleanup();
                    delete mCurrentState;
                }

                mCurrentState = mNextState;
                mCurrentState->mSystem = this;
                mCurrentState->Startup();

                mChangeState = false;
            }
        }

        mCurrentState->Cleanup();
        delete mCurrentState;
    }

    Cleanup();
}

//--------------------------------------------------

void System::Run(State *state)
{
    System *system = new System;

    system->_Run(state);

    delete system;
}

//--------------------------------------------------

void System::ChangeState(State *state)
{
    mNextState = state;
    mChangeState = true;
}

//--------------------------------------------------

void System::Quit()
{
    mRunning = false;
}