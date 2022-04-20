#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <stdio.h>

#include "receiver.h"
#include"test/catch.hpp"

TEST_CASE("Check for minimum temperature value")
{
  float result;
  float temp[] = {1.2, 1.1, 15.6, 89.2};
  float expectedTemp = 1.1;
  int noOfValues = (sizeof(temp))/(sizeof(int));
  result = getMinimumTempValue(temp,noOfValues);
  REQUIRE(result==expectedTemp);
}

TEST_CASE("Check for minimum SOC value")
{
  float result;
  float SOC[] = {36.0, 31.1, 15, 89};
  float expectedSOC = 15;
  int noOfValues = (sizeof(SOC))/(sizeof(int));
  result = getMinimumSOCValue(SOC,noOfValues);
  REQUIRE(result==expectedSOC);
}
TEST_CASE("Check for maximum temperature value")
{
  float result;
  float temp[] = {1.2, 1.1, 15.6, 89.2};
  float expectedTemp = 89.2;
  int noOfValues = (sizeof(temp))/(sizeof(int));
  result = getMaximumTempValue(temp,noOfValues);
  REQUIRE(result==expectedTemp);
}
TEST_CASE("Check for maximum SOC value")
{
  float result;
  float SOC[] = {36.0, 31.1, 15, 89};
  float expectedSOC = 89;
  int noOfValues = (sizeof(SOC))/(sizeof(int));
  result = getMaximumSOCValue(SOC,noOfValues);
  REQUIRE(result==expectedSOC);
}
