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

	static int rnd(int maximum) {
		return generator() % maximum; 
	}

    void firePhaser(Galaxy &galaxy);

    void firePhoton(Galaxy& galaxy);

    void damageEnemy(int damage, Klingon* enemy, int distance, Galaxy& galaxy, std::string &weapon_type);

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
