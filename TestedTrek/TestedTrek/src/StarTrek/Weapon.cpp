#include "Weapon.h"
#include "Galaxy.h"

namespace StarTrek {

Random Weapon::generator;

Weapon::Weapon(Galaxy &galaxy) :
    m_enemy((Klingon*)galaxy.variable("target")),
    m_galaxy(&galaxy)
{
    Weapon::generator = &rand;
}

Weapon::~Weapon()
{
    if(m_enemy)
        m_enemy = nullptr;

    if(m_galaxy)
        m_galaxy = nullptr;
}

void Weapon::damageEnemy(const int damage, const std::string &weapon_type)
{
    stringstream message;
    message << weapon_type << " hit Klingon at " << m_enemy->distance() << " sectors with " << damage << " units";
    m_galaxy->writeLine(message.str());
    if (damage < m_enemy->energy()) {
        m_enemy->energy(m_enemy->energy() - damage);
        stringstream message;
        message << "Klingon has " << m_enemy->energy() << " remaining";
        m_galaxy->writeLine(message.str());
    } else {
        m_galaxy->writeLine("Klingon destroyed!");
        m_enemy->destroy();
    }
}

}
