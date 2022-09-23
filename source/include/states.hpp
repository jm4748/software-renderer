//--------------------------------------------------
//----------HEADERS---------------------------------
//--------------------------------------------------

//custom
#include "system.hpp"

//--------------------------------------------------
//----------MAIN STATE CLASS------------------------
//--------------------------------------------------

class MainState : public State
{
public:
    MainState();
    ~MainState();

    void Startup();
    void Cleanup();

    void Update(uint8 timeStep);
    void Render(real4 interpolation);
};