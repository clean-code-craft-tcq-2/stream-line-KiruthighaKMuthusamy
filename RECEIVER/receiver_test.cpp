#include <stdio.h>
#include <iostream>
#include "receiver.h"
#include"test/catch.hpp"

TEST_CASE("Check for minimum temperature value")
{
  float result;
  result = getMinimumTempValue(tempSocValuesInBAtt,noOfValues);
  REQUIRE(result==expectedTemp);
}

