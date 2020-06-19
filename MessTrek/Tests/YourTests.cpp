

#include "gtest/gtest.h"

#include "Game.h"

TEST(StarTrekCharacterization, SomeAsYetUnknownScenario) {
	EXPECT_TRUE(false);
}

int main(int argc, char** argv)
{
	StarTrek::Game game;
	// run all tests
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
