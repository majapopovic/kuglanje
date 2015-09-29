#include "../../unity/unity_fixture.h"
#include "../src/player.h"


PLAYER* player;


TEST_GROUP(PlayerTest);

TEST_GROUP_RUNNER(PlayerTest)
{
RUN_TEST_CASE(PlayerTest, Allocated);
RUN_TEST_CASE(PlayerTest, TestName);
RUN_TEST_CASE(PlayerTest, TestLongerName);
RUN_TEST_CASE(PlayerTest, TestEmptyName);
RUN_TEST_CASE(PlayerTest, TestQuality);
RUN_TEST_CASE(PlayerTest, TestQualityBounds);
RUN_TEST_CASE(PlayerTest, TestHand);
RUN_TEST_CASE(PlayerTest, TestHandBounds);
RUN_TEST_CASE(PlayerTest, TestIncreaseQuality);
RUN_TEST_CASE(PlayerTest, TestIncreaseQualityBounds);
RUN_TEST_CASE(PlayerTest, TestDecreaseQuality);
RUN_TEST_CASE(PlayerTest, TestDecreaseQualityBounds);
}



TEST_SETUP(PlayerTest)
{
player=playerCreate();
}


TEST_TEAR_DOWN(PlayerTest)
{
}


TEST(PlayerTest, Allocated)
{
TEST_ASSERT_TRUE(player!=NULL);
}

TEST(PlayerTest,TestName)
{
setName(player,"bbc");
STRCMP_EQUAL("bbc",player->name);
}

TEST(PlayerTest,TestLongerName)
{
setName(player,"bbcadjafkurjlvgfreg8trgfeiurgvf");
STRCMP_EQUAL("bbcadjafkurjlvgfreg8",player->name);
}

TEST(PlayerTest,TestEmptyName)
{
setName(player,"");
STRCMP_EQUAL("Player",player->name);
}

TEST(PlayerTest,TestQuality)
{
setQuality(player,-10);
TEST_ASSERT_EQUAL(1,player->quality);
}

TEST(PlayerTest,TestQualityBounds)
{
setQuality(player,-10);
TEST_ASSERT_EQUAL(1,player->quality);
}

TEST(PlayerTest,TestIncreaseQuality)
{
setQuality(player,5);
increaseQuality(player);
TEST_ASSERT_EQUAL(6,player->quality);
}

TEST(PlayerTest,TestIncreaseQualityBounds)
{
setQuality(player,MAX_QUALITY);
increaseQuality(player);
TEST_ASSERT_EQUAL(10,player->quality);
}

TEST(PlayerTest,TestDecreaseQuality)
{
setQuality(player,5);
decreaseQuality(player);
TEST_ASSERT_EQUAL(4,player->quality);
}


TEST(PlayerTest,TestDecreaseQualityBounds)
{
setQuality(player,MIN_QUALITY);
decreaseQuality(player);
TEST_ASSERT_EQUAL(MIN_QUALITY,player->quality);
}


TEST(PlayerTest,TestHand)
{
setHand(player,LEFT_HAND);
TEST_ASSERT_EQUAL(LEFT_HAND,player->hand);
}


TEST(PlayerTest,TestHandBounds)
{
setHand(player,12);
TEST_ASSERT_EQUAL(RIGHT_HAND,player->hand);
}
