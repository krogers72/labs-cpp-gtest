#ifndef WEAPON_H
#define WEAPON_H

#include "Klingon.h"
#include "string"
#include "sstream"

namespace StarTrek {

class Galaxy;

typedef int(*Random)(void);

class Weapon
{

protected:
    static int rnd(int maximum) {
        return generator() % maximum;
    }

public:
    Weapon(Galaxy &Galaxy);
    virtual ~Weapon();

    virtual void fire() = 0;
    virtual int calculateDamage() = 0;
    virtual std::string weaponType() = 0;
    virtual void damageEnemy(const int damage,const std::string &weapon_type);

    static Random generator;

protected:
    Klingon* m_enemy;
    Galaxy* m_galaxy;
};

}

#endif // WEAPON_H
