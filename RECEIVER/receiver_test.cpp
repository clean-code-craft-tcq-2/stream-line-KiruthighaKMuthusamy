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
  int noOfValues = (sizeof(tempSocValuesInBAtt->temperature[3]))/(sizeof(int));  
  float expectedTemp = 2.3;
  result = getMinimumTempValue(tempSocValuesInBAtt,noOfValues);
  REQUIRE(result==expectedTemp);
}

