#include "PhaserWeapon.h"

namespace StarTrek {

PhaserWeapon::PhaserWeapon(Galaxy &galaxy, RandomNumberGenerator &generator)
    : Weapon(galaxy, generator)
{

}

void PhaserWeapon::fire()
{
    int distance = m_enemy->distance();
    if (distance > 4000) {
        stringstream message;
        message << "Klingon out of range of phasers at " << distance << " sectors...";
        m_galaxy->writeLine(message.str());
    } else {
        damageEnemy(calculateDamage(), weaponType());
    }
}

int PhaserWeapon::calculateDamage()
{
    int amount = atoi(m_galaxy->parameter("amount").c_str());
    int damage = amount - (((amount /20)* m_enemy->distance() /200) + rnd(200));
    if(damage < 1)
        damage = 1;

    return damage;
}

std::string PhaserWeapon::weaponType()
{
    return std::string("Phasers");
}

}
