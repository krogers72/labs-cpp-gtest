#ifndef WEAPON_H
#define WEAPON_H

#include "Klingon.h"
#include "RandomNumberGenerator.h"
#include "string"
#include "sstream"
#include <memory>

namespace StarTrek {

class Galaxy;

typedef int(*Random)(void);

class Weapon
{

protected:
    int rnd(int maximum)
    {
        return m_generator.generate(maximum);
    }

public:
    Weapon(Galaxy &Galaxy,
           RandomNumberGenerator& generator);
    virtual ~Weapon();

    virtual void fire() = 0;
    virtual int calculateDamage() = 0;
    virtual std::string weaponType() = 0;
    virtual void damageEnemy(const int damage,const std::string &weapon_type);

//    static Random generator;

protected:
    RandomNumberGenerator& m_generator;
    Klingon* m_enemy;
    Galaxy* m_galaxy;
};

}

#endif // WEAPON_H
