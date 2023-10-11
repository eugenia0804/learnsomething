#include <gtest/gtest.h>
#include "pricingutil.h"

TEST(calcValTest, simple) {
    // simple
    PricingUtil pricingUtil;
    float res = pricingUtil.calcVal(10,0.1,2);
    EXPECT_NEAR(pricingUtil.getVal(), 20, 1e-4);

}
TEST(calcValTest, zero_preprice) {
    // zero previous_price
    PricingUtil pricingUtil;
    float res2 = pricingUtil.calcVal(0,0.2,2);
    EXPECT_NEAR(pricingUtil.getVal(), 0, 1e-4);
}
TEST(calcValTest, zero_cons) {
    PricingUtil pricingUtil;
    // zero constant
    float res3 = pricingUtil.calcVal(2,0.2,0);
    EXPECT_NEAR(pricingUtil.getVal(), 0, 1e-4);
}
TEST(calcValTest, neg_interest) {
    PricingUtil pricingUtil;
    // negative interest
    float res4 = pricingUtil.calcVal(3,-0.4,2);
    EXPECT_NEAR(pricingUtil.getVal(), 3, 1e-4);
}
TEST(calcValTest, zero_interest) {
    PricingUtil pricingUtil;
    // zero interest
    float res5 = pricingUtil.calcVal(3,0,2);
    EXPECT_NEAR(pricingUtil.getVal(), 5.4, 1e-4);
}