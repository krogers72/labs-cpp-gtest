#ifndef ZERONUMBERGENERATOR_H
#define ZERONUMBERGENERATOR_H

#include "RandomNumberGenerator.h"

class ZeroNumberGenerator : public StarTrek::RandomNumberGenerator
{
public:
    ZeroNumberGenerator();

    int generate(int maximum) override;
};

#endif // ZERONUMBERGENERATOR_H
