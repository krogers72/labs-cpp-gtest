

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Game.h"
#include "WebGadgetProxy.h"
#include "Klingon.h"

using ::testing::Return;
using ::testing::Throw;

using namespace Untouchables;
using namespace StarTrek;

class MockWebGadgetProxy : public WebGadgetProxy
{

public:
    MockWebGadgetProxy() : WebGadgetProxy(nullptr)
    {}

    MOCK_METHOD1(writeLine, void(string message));
    MOCK_METHOD1(parameter, string(string parameterName));
    MOCK_METHOD1(variable, void*(string variableName));
};

TEST(StarTrekCharacterization, FirePhaserWeapon)
{
    Klingon enemy{};
    int start_energy = enemy.energy();
    Game game;
    MockWebGadgetProxy mock_gadget;
    EXPECT_CALL(mock_gadget, parameter("command")).WillOnce(Return("phaser"));
    EXPECT_CALL(mock_gadget, parameter("amount")).WillOnce(Return("1000"));
    EXPECT_CALL(mock_gadget, variable("target")).WillOnce(Return((void*)&enemy));
    game.fireWeapon(mock_gadget);
    EXPECT_LT(enemy.energy(), start_energy);
}

int main(int argc, char** argv)
{
	StarTrek::Game game;
	// run all tests
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
