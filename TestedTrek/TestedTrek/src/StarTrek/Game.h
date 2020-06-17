#ifndef GAME_HEADER 
#define GAME_HEADER 

#include <cstdlib>
#include "WebGadget.h"


namespace StarTrek {

class Galaxy;
class Klingon;

typedef int(*Random)(void);


class Game {
private:
    int m_energy;  // Amount of energy
    int m_torpedoes;  // Number of torpedoes

	static int rnd(int maximum) {
		return generator() % maximum; 
	}

    void damageEnemy(Galaxy& galaxy,
                     const std::string& weapon_type,
                     int damage,
                     int distance,
                     Klingon* enemy);

public:
    Game();
    void fireWeapon(Untouchables::WebGadget* wg);
    void fireWeapon(Galaxy& galaxy);
    void firePhaser(Galaxy& galaxy);
    void firePhotonTorpedo(Galaxy& galaxy);
    int energyRemaining(void);
    void torpedoes(int value);
    int torpedoes(void);

    static Random generator;
};

}

#endif
