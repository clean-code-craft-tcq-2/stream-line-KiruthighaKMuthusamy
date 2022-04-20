#include <stdio.h>
#include <iostream>
#include "receiver.h"
#include"test/catch.hpp"

TEST_CASE("Check for minimum temperature value")
{
  float result;
  float temp[] = {1.2, 1.1, 15.6, 89.2};
  float expectedTemp = 1.1;
  int noOfValues = (sizeof(temp[]))/(sizeof(int));
  result = getMinimumTempValue(tempSocValuesInBAtt,noOfValues);
  REQUIRE(result==expectedTemp);
}

