#include <sstream>

#include "Game.h"
#include "Klingon.h"
#include "Galaxy.h"

namespace StarTrek {

Random Game::generator;

Game::Game() : m_energy(10000), m_torpedoes(8) {
    Game::generator = &rand;
}

void Game::firePhaser(Galaxy& galaxy)
{
    int amount = atoi(galaxy.parameter("amount").c_str());
    Klingon* enemy = (Klingon*)galaxy.variable("target");
    if (m_energy >= amount) {
        int distance = enemy->distance();
        if (distance > 4000) {
            stringstream message;
            message << "Klingon out of range of phasers at " << distance << " sectors...";
            galaxy.writeLine(message.str());
        } else {
            int damage = amount - (((amount /20)* distance /200) + rnd(200));
            if (damage < 1)
                damage = 1;
            damageEnemy(galaxy, "Phasers", damage, distance, enemy);
        }
        m_energy -= amount;

    } else {
        galaxy.writeLine("Insufficient energy to fire phasers!");
    }
}

void Game::firePhotonTorpedo(Galaxy& galaxy)
{
    Klingon* enemy = (Klingon*)galaxy.variable("target");
    if (m_torpedoes > 0) {
        int distance = enemy->distance();
        if ((rnd(4) + ((distance / 500) + 1) > 7)) {
            stringstream message;
            message << "Torpedo missed Klingon at " << distance << " sectors...";
            galaxy.writeLine(message.str());
        } else {
            int damage = 800 + rnd(50);
            damageEnemy(galaxy, "Photons", damage, distance, enemy);
        }
        m_torpedoes--;

    } else {
        galaxy.writeLine("No more photon torpedoes!");
    }
}

void Game::fireWeapon(Galaxy& galaxy) {
	if (galaxy.parameter("command") == "phaser") {
        firePhaser(galaxy);
	} else if (galaxy.parameter("command") == "photon") {
        firePhotonTorpedo(galaxy);
	}
}

void Game::fireWeapon(Untouchables::WebGadget* webGadget) {
    Galaxy galaxy(webGadget);
    fireWeapon(galaxy);
}

int Game::energyRemaining(void) {
    return m_energy;
}

int Game::torpedoes(void) {
    return m_torpedoes;
}

void Game::torpedoes(int value) {
    m_torpedoes = value;
}

void Game::damageEnemy(Galaxy &galaxy,
                       const std::string& weapon_type,
                       int damage,
                       int distance,
                       Klingon* enemy)
{
    std::stringstream message;
    message << weapon_type << " hit Klingon at " << distance << " sectors with " << damage << " units";
    galaxy.writeLine(message.str());

    if (damage < enemy->energy()) {
        enemy->energy(enemy->energy() - damage);
        stringstream message;
        message << "Klingon has " << enemy->energy() << " remaining";
        galaxy.writeLine(message.str());
    } else {
        galaxy.writeLine("Klingon destroyed!");
        enemy->destroy();
    }

}

}
