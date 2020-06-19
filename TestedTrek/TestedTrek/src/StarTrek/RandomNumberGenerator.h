#ifndef RANDOMNUMBERGENERATOR_H
#define RANDOMNUMBERGENERATOR_H

namespace StarTrek
{

class RandomNumberGenerator
{
public:
    RandomNumberGenerator();
    virtual ~RandomNumberGenerator() = default;

    virtual int generate(int maximum) = 0;
};

}

#endif // RANDOMNUMBERGENERATOR_H
