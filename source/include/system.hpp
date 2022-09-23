//--------------------------------------------------
//----------HEADERS---------------------------------
//--------------------------------------------------

//custom
#include "types.hpp"

//--------------------------------------------------
//----------SYSTEM CLASS----------------------------
//--------------------------------------------------

class State;

class System
{
private:
    SDL_Window *mWindow;
    SDL_Renderer *mRenderer;

    bool mRunning;

    State *mCurrentState;
    State *mNextState;
    bool mChangeState;

private:
    System();
    ~System();

    bool Startup();
    void Cleanup();

    void _Run(State *state);

public:
    static void Run(State *state);

    void ChangeState(State *state);

    void Quit();
};

//--------------------------------------------------
//----------STATE CLASS-----------------------------
//--------------------------------------------------

class State
{
    friend class System;

protected:
    System *mSystem;

public:
    virtual void Startup() = 0;
    virtual void Cleanup() = 0;

    virtual void Update(uint8 timeStep) = 0;
    virtual void Render(real4 interpolation) = 0;
};