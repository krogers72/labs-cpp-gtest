#ifndef NOTARANDOMNUMBERGENERATOR_H
#define NOTARANDOMNUMBERGENERATOR_H

#include "RandomNumberGenerator.h"

namespace StarTrek
{

class NotARandomNumberGenerator : public RandomNumberGenerator
{
public:
    NotARandomNumberGenerator(int always_generate_this_value);

    int generate(int) override;

private:
    int m_value;
};

}

#endif // NOTARANDOMNUMBERGENERATOR_H
