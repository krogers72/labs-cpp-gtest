/**
 * UNTOUCHABLE!  You cannot change this file.
 *
 */

#include "ITC/SecurityExchangeTransmissionInterface.h"

class LunExServices : public ITC::SecurityExchangeTransmissionInterface {
public:
	LunExServices(); 
	long currentPrice(const char* symbol); 

private:
	void pauseToEmulateSendReceive(); 
};
