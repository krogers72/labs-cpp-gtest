#ifndef GAME_HEADER 
#define GAME_HEADER 

#include <cstdlib>
#include "WebGadget.h"
#include "WebGadgetProxy.h"


namespace StarTrek {


class Game {
private:
	int e_;
	int t_;

	static int randomWithinLimitOf(int maximum) {
		return rand() % maximum; 
	}

public:
	Game();
    void fireWeapon(WebGadgetProxy& wg);
};

}

#endif
