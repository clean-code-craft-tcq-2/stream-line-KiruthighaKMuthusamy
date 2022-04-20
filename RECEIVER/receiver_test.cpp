#include <stdio.h>
#include "receiver.h"
#include"test/catch.hpp"

TEST_CASE("Check for minimum temperature value")
{
  float expectedTemp;
  float result;
  batteryParameter* tempSocValuesInBAtt = {{23,25.5},
                                           {92.6,96},
                                           {2, 2.1}};
  expectedTemp = 2;
  int noOfValues = 3;
  result = getMinimumTempValue(tempSocValuesInBAtt, noOfValues);
  REQUIRE(result==expectedTemp);
}

