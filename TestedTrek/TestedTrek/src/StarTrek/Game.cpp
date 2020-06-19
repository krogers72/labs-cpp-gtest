#include <sstream>

#include "Game.h"
#include "Klingon.h"
#include "Galaxy.h"
#include "PhotonWeapon.h"
#include "PhaserWeapon.h"
#include "RealRandomNumberGenerator.h"

namespace StarTrek {

//Random Game::generator;

Game::Game()
    : m_generator(std::make_unique<RealRandomNumberGenerator>()),
      m_energy(10000),
      m_torpedoes(8)
{ }

Game::Game(std::unique_ptr<RandomNumberGenerator> generator)
    : m_generator(std::move(generator)),
      m_energy(10000),
      m_torpedoes(8)
{
//    Game::generator = &rand;
}

void Game::firePhaser(Galaxy &galaxy)
{
    PhaserWeapon weapon(galaxy, *m_generator);
    int amount = atoi(galaxy.parameter("amount").c_str());
    if (m_energy >= amount) {
        weapon.fire();
        m_energy -= amount;
    } else {
        galaxy.writeLine("Insufficient energy to fire phasers!");
    }
}

void Game::firePhoton(Galaxy& galaxy)
{
    PhotonWeapon weapon(galaxy, *m_generator);
    if (m_torpedoes > 0) {
        weapon.fire();
        m_torpedoes--;
    } else {
        galaxy.writeLine("No more photon torpedoes!");
    }
}

void Game::fireWeapon(Galaxy& galaxy) {
	if (galaxy.parameter("command") == "phaser") {
        firePhaser(galaxy);

	} else if (galaxy.parameter("command") == "photon") {
        firePhoton(galaxy);
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
