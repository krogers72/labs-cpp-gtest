#ifndef KLINGON_HEADER
#define KLINGON_HEADER


#include <cstdlib>
#include <time.h>

namespace StarTrek {

class Klingon {
private:
	int distance_;
	int energy_;

public:	
	Klingon() {
		srand(time(NULL));
		distance_ = (100 + rand() % 4000);
		energy_ = (1000+ rand() % 2000);
	}

	int distance() {
		return distance_;
	}

	int energy() {
		return energy_;
	}

	void energy(int value) {
		energy_ = value;
	}

	void destroy() {
        energy_ = -1;
	}

};
}

#endif
