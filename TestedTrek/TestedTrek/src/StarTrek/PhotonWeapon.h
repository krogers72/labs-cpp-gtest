#ifndef PHOTONWEAPON_H
#define PHOTONWEAPON_H

#include "Weapon.h"
#include "Galaxy.h"

namespace StarTrek {

class PhotonWeapon : public Weapon
{
public:
    PhotonWeapon(Galaxy &galaxy, RandomNumberGenerator& generator);

    virtual void fire() override;
    virtual int calculateDamage() override;
    virtual std::string weaponType() override;
};

}

#endif // PHOTONWEAPON_H
