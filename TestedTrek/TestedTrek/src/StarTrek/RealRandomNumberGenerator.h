#ifndef REALRANDOMNUMBERGENERATOR_H
#define REALRANDOMNUMBERGENERATOR_H

#include "RandomNumberGenerator.h"

namespace StarTrek
{

class RealRandomNumberGenerator : public RandomNumberGenerator
{
public:
    RealRandomNumberGenerator();
    ~RealRandomNumberGenerator() = default;

    int generate(int maximum) override;
};

}

#endif // REALRANDOMNUMBERGENERATOR_H
