#ifndef GAME_HEADER 
#define GAME_HEADER 

#include <cstdlib>
#include "WebGadget.h"


namespace StarTrek {

class Klingon;
class Galaxy;

typedef int(*Random)(void);


class Game {
private:
    int m_energy;
    int m_torpedoes;

    void firePhaser(Galaxy &galaxy);
    void firePhoton(Galaxy& galaxy);

public:
    Game();
    void fireWeapon(Untouchables::WebGadget* wg);
    void fireWeapon(Galaxy& galaxy);
    int energyRemaining(void);
    void torpedoes(int value);
    int torpedoes(void);

    static Random generator;
};

}

#endif
