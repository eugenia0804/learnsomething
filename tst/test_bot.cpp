#include <gtest/gtest.h>
#include "action.h"
#include "hackathonbot.h"
#include <iostream>

TEST(HackathonTests, BasicAssertion) {
    EXPECT_NEAR(4, 4, 1e-4);
}

TEST(HackathonTests, BasicAssertion2) {
  EXPECT_NEAR(5, 5, 1e-4);
}

TEST(ActionTest, PleaseWork) {
  Action action;
  float a = action.getBalance();
  //bool b = action.buy(500);
  //EXPECT_EQ(b,false);
  EXPECT_NEAR(a,0,1e-4);
}

TEST(HackathonbotTest, basicFucntions) {
  HackathonBot hackathonbot;

  hackathonbot.execute(52);
  ASSERT_EQ(hackathonbot.isHold(), false);
  hackathonbot.execute(51);
  ASSERT_EQ(hackathonbot.isHold(), true);
  hackathonbot.execute(600);
  hackathonbot.execute(500);
  hackathonbot.execute(400);
  hackathonbot.execute(300);
  hackathonbot.execute(200);
  hackathonbot.execute(100);
  hackathonbot.execute(0);
  ASSERT_EQ(hackathonbot.isHold(), false);
  ASSERT_NEAR(hackathonbot.getBalance(),-51, 1e-4);


}