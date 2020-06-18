#ifndef PHASERWEAPON_H
#define PHASERWEAPON_H

#include "Weapon.h"
#include "Galaxy.h"

namespace StarTrek {

class PhaserWeapon : public Weapon
{
public:
    PhaserWeapon(Galaxy &galaxy);

    virtual void fire() override;
    virtual int calculateDamage() override;
    virtual std::string weaponType() override;
};

}

#endif // PHASERWEAPON_H