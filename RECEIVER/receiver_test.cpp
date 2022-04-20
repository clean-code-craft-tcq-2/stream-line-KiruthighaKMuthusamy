#include <stdio.h>
#include "receiver.h"
#include"test/catch.hpp"

TEST_CASE("Check for minimum temperature value")
{
  float result;
  batteryParameter* tempSocValuesInBAtt->temperature[3] = {23,25.5,99.9};
  //tempSocValuesInBAtt->SOC[3] = {36,2.6,2.3};
  float expectedTemp = 23;
  result = getMinimumTempValue(tempSocValuesInBAtt);
  REQUIRE(result==expectedTemp);
}

