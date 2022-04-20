#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <stdio.h>

#include "receiver.h"
#include"test/catch.hpp"

TEST_CASE("Check for minimum temperature value")
{
  float result;
  float temp[] = {1.2, 1.1, 15.6, 89.2};
  float expectedTemp = 1.1;
  int noOfValues = (sizeof(temp))/(sizeof(temp[0]));
  result = getMinimumTempValue(temp,noOfValues);
  REQUIRE(result==expectedTemp);
}

TEST_CASE("Check for minimum SOC value")
{
  float result;
  float SOC[] = {36.0, 31.1, 15, 89};
  float expectedSOC = 15;
  int noOfValues = (sizeof(SOC))/(sizeof(SOC[0]));
  result = getMinimumSOCValue(SOC,noOfValues);
  REQUIRE(result==expectedSOC);
}
TEST_CASE("Check for maximum temperature value")
{
  float result;
  float temp[] = {1.2, 1.1, 15.6, 89.2};
  float expectedTemp = 89.2;
  int noOfValues = (sizeof(temp))/(sizeof(temp[0]));
  result = getMaximumTempValue(temp,noOfValues);
  REQUIRE(result==expectedTemp);
}
TEST_CASE("Check for maximum SOC value")
{
  float result;
  float SOC[] = {36.0, 31.1, 15, 89};
  float expectedSOC = 89;
  int noOfValues = (sizeof(SOC))/(sizeof(SOC[0]));
  result = getMaximumSOCValue(SOC,noOfValues);
  REQUIRE(result==expectedSOC);
}
TEST_CASE("Check for average of last 5 temp values")
{
  float average_temp;
  float Temp[] = {22.1, 21.6, 20.9, 0.6, 0.5, 9.6, 2.3, 4.2, 99.6, 6.2};
  float expectedavg_temp = 24.38;
  int noOfValues_temp = (sizeof(Temp))/(sizeof(Temp[0]));
  average_temp = getAverageOfLastFive(Temp, noOfValues_temp);
  REQUIRE(average_temp == expectedavg_temp );  
}
/*TEST_CASE("Check for average of last 5 SOC values")
{
  float average_SOC;
  float SOC[] = {9.6, 2.3, 4.2, 99.6, 6.2, 22.1, 21.6, 20.9, 0.6, 0.5};
  float expectedavg_SOC = 13.14;
  int noOfValues_SOC = (sizeof(SOC))/(sizeof(SOC[0]));
  average_SOC = getAverageOfLastFive(SOC, noOfValues_SOC);
  REQUIRE(average_SOC == expectedavg_SOC);
}*/
