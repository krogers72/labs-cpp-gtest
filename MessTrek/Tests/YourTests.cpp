

#include "gtest/gtest.h"

#include "StarTrek/Game.h"
#include "StarTrek/WebGadgetProxy.h"

TEST(StarTrekCharacterization, SomeAsYetUnknownScenario) {
	EXPECT_TRUE(false);
}

class MockWebGadgetProxy(WebGadget* gadget) : WebGadgetProxy(gadget)
{
    public:
        MOCK_METHOD(void, writeLine, (string message), (override));
        MOCK_METHOD(string, parameter, (string parameterName), (override));
        MOCK_METHOD(void*, variable, (variableName), (override));
}

TEST(StarTrekCharacterization, FirePhaserWeapon)
{

}

int main(int argc, char** argv)
{
	StarTrek::Game game;
	// run all tests
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
