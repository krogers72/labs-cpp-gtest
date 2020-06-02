#include <stdlib.h>
#include <time.h>
#ifdef _WIN32
#  include <Windows.h>
#else
#  include <unistd.h>
#endif

#include "LunExServices.h"
#include "LunExServiceUnavailableException.h"


LunExServices::LunExServices() {
	srand(time(0));
}

long LunExServices::currentPrice(const char* symbol) {
	(void)symbol; 
	pauseToEmulateSendReceive();
	if (rand() % 100 > 77) {
		throw LunExServiceUnavailableException();
	}

	return 42 + (rand() % 21);
}

void LunExServices::pauseToEmulateSendReceive() {
	try {
#ifdef _WIN32
		Sleep(5000);
#else
		sleep(5);
#endif
	} catch (std::exception& e) {
		// lucky client!
	}
}

