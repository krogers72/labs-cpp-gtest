#ifndef PHOTONWEAPON_H
#define PHOTONWEAPON_H

#include "Weapon.h"
#include "Galaxy.h"

namespace StarTrek {

class PhotonWeapon : public Weapon
{
public:
    PhotonWeapon(Galaxy &galaxy);

    virtual void fire() override;
    virtual int calculateDamage() override;
    virtual std::string weaponType() override;
};

}

#endif // PHOTONWEAPON_H
