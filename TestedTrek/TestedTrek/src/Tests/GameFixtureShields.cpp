#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Shield.h"

using namespace testing;

class GameFixtureShields : public Test
{
public:
    StarTrek::Shield shield_zero;
    StarTrek::Shield shield_1000{1000};
};

TEST_F(GameFixtureShields, ShieldIsDownByDefault)
{
    EXPECT_FALSE(shield_zero.isUp());
}

TEST_F(GameFixtureShields, CanRaiseShield)
{
    shield_zero.raise();
    EXPECT_TRUE(shield_zero.isUp());
}

TEST_F(GameFixtureShields, TransferEnergyToShield)
{
    int start_energy = shield_zero.getStrength();
    shield_zero.transferIn(500);
    EXPECT_EQ(start_energy + 500, shield_zero.getStrength());
}

TEST_F(GameFixtureShields, ShieldDefaultStrengthIsZero)
{
    EXPECT_EQ(shield_zero.getStrength(), 0);
}

TEST_F(GameFixtureShields, DoNotTransferOverMaxStrength)
{
    shield_zero.transferIn(StarTrek::Shield::MAX_STRENGTH + 1);
    EXPECT_EQ(StarTrek::Shield::MAX_STRENGTH, shield_zero.getStrength());
}

TEST_F(GameFixtureShields, ReturnAppropriateTransferAmount)
{
    int initial_amount = 1;
    EXPECT_EQ(initial_amount, shield_zero.transferIn(initial_amount));
}

TEST_F(GameFixtureShields, ShieldTakesCorrectAmountOfDamage)
{
    int damage = 600;
    shield_1000.raise();
    shield_1000.takeDamageAndReturnOverflow(damage);
    EXPECT_EQ(400, shield_1000.getStrength());
}

TEST_F(GameFixtureShields, ShieldReturnsCorrectOverflow)
{
    int damage = shield_1000.getStrength() + 1;
    shield_1000.raise();
    EXPECT_EQ(1, shield_1000.takeDamageAndReturnOverflow(damage));
}

TEST_F(GameFixtureShields, ShieldDoesNotAbsorbEnergyWhenDown)
{
    shield_1000.lower();
    EXPECT_EQ(600, shield_1000.takeDamageAndReturnOverflow(600));
}

TEST_F(GameFixtureShields, ShieldBucklesWhenDepleted)
{
    shield_1000.raise();
    shield_1000.takeDamageAndReturnOverflow(shield_1000.getStrength());
    EXPECT_EQ(0, shield_1000.getStrength());
    EXPECT_EQ(false, shield_1000.isUp());
}
