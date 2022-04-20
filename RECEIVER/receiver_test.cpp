#include <stdio.h>
#include "receiver.h"
#include"test/catch.hpp"

TEST_CASE("Check for minimum temperature value")
{
  float result;
  batteryParameter* tempSocValuesInBAtt;
  tempSocValuesInBAtt->temperature[3] = {2.3, 3.9, 68.2};
  int noOfValues = (sizeof(tempSocValuesInBAtt->temperature[3]))/(sizeof(int));
  //tempSocValuesInBAtt->SOC[3] = {36,2.6,2.3};
  float expectedTemp = 2.3;
  result = getMinimumTempValue(tempSocValuesInBAtt,noOfValues);
  REQUIRE(result==expectedTemp);
}

