#include "Shield.h"

namespace StarTrek
{

const int Shield::MAX_STRENGTH{10000};
const int Shield::MIN_STRENGTH{};

Shield::Shield()
{

}

int Shield::transferIn(const int energy)
{
    int transferred = energy;
    if(energy + m_strength > MAX_STRENGTH)
    {
        transferred = MAX_STRENGTH - m_strength;
        m_strength = MAX_STRENGTH;
    }
    else
        m_strength += energy;

    return transferred;
}

}
