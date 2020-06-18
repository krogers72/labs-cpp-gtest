#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Shield.h"

using namespace testing;

class GameFixtureShields : public Test
{
public:
    StarTrek::Shield shield;
};

TEST_F(GameFixtureShields, ShieldIsDownByDefault)
{
    EXPECT_FALSE(shield.isUp());
}

TEST_F(GameFixtureShields, CanRaiseShield)
{
    shield.raise();
    EXPECT_TRUE(shield.isUp());
}

TEST_F(GameFixtureShields, TransferEnergyToShield)
{
    int start_energy = shield.getStrength();
    shield.transferIn(500);
    EXPECT_EQ(start_energy + 500, shield.getStrength());
}

TEST_F(GameFixtureShields, ShieldDefaultStrengthIsZero)
{
    EXPECT_EQ(shield.getStrength(), 0);
}

TEST_F(GameFixtureShields, DoNotTransferOverMaxStrength)
{
    shield.transferIn(StarTrek::Shield::MAX_STRENGTH + 1);
    EXPECT_EQ(StarTrek::Shield::MAX_STRENGTH, shield.getStrength());
}

TEST_F(GameFixtureShields, ReturnAppropriateTransferAmount)
{
    int initial_amount = 8000;
    EXPECT_EQ(initial_amount, shield.transferIn(initial_amount));

    int over_max = initial_amount + StarTrek::Shield::MAX_STRENGTH;
    EXPECT_EQ(StarTrek::Shield::MAX_STRENGTH - initial_amount, shield.transferIn(over_max));
}
