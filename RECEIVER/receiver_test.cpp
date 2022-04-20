#include <stdio.h>
#include <iostream>
#include "receiver.h"
#include"test/catch.hpp"

TEST_CASE("Check for minimum temperature value")
{
  float result;
  struct batteryParameter tempSocValuesInBAtt = 
  {
    {1.2, 26.6, 2.3};
    {36, 2.6, 2.3};
  }    
  //tempSocValuesInBAtt->SOC[3] = {36, 2.6, 2.3};
  int noOfValues = 3;  
  float expectedTemp = 1.2;
  result = getMinimumTempValue(tempSocValuesInBAtt,noOfValues);
  REQUIRE(result==expectedTemp);
}

