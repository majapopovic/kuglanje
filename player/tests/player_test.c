#include "../../unity/unity_fixture.h"
#include "../src/player.h"


PLAYER* player;


TEST_GROUP(PlayerTest);

TEST_GROUP_RUNNER(PlayerTest)
{
RUN_TEST_CASE(PlayerTest, Allocated);
}



TEST_SETUP(PlayerTest)
{

}


TEST_TEAR_DOWN(PlayerTest)
{
}


TEST(PlayerTest, Allocated)
{
player=playerCreate();
TEST_ASSERT_TRUE(player!=NULL);
}
