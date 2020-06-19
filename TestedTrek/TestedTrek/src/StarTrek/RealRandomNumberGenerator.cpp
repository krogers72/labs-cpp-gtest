#include "RealRandomNumberGenerator.h"

#include <cstdlib>

using namespace StarTrek;

RealRandomNumberGenerator::RealRandomNumberGenerator()
{

}

int RealRandomNumberGenerator::generate(int maximum)
{
    return std::rand() % maximum;
}
