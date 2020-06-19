#include "Shield.h"

namespace StarTrek
{

const int Shield::MAX_STRENGTH{10000};
const int Shield::MIN_STRENGTH{};

Shield::Shield(int start_energy) :
    m_strength{start_energy}
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

int Shield::takeDamageAndReturnOverflow(const int damage)
{
    if(!m_status)
        return damage;
    else if(damage >= m_strength)
    {
        int overflow = damage - m_strength;
        m_strength = 0;
        m_status = false;

        return overflow;
    }
    else
        m_strength -= damage;

    return 0;

}

}
