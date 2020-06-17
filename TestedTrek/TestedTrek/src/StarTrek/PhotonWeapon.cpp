#include "PhotonWeapon.h"
#include "sstream"
#include "string"

namespace StarTrek {

PhotonWeapon::PhotonWeapon(Galaxy &galaxy) : Weapon(galaxy)
{

}

void PhotonWeapon::fire()
{
    int distance = m_enemy->distance();
    if ((rnd(4) + ((distance / 500) + 1) > 7)) {
        stringstream message;
        message << "Torpedo missed Klingon at " << distance << " sectors...";
        m_galaxy->writeLine(message.str());
    } else {
        damageEnemy(calculateDamage(), weaponType());
    }
}

int PhotonWeapon::calculateDamage()
{
    return int(800 + rnd(50));
}

std::string PhotonWeapon::weaponType()
{
    return std::string("Photons");
}

}
