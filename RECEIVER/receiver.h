#include <stdio.h>

struct batteryParameter
{
  float temperature;
  float SOC;
};

void getStreamOfValues(batteryParameter* tempSocValuesInBAtt, int noOfValues);
void getMinimumValue(batteryParameter* tempSocValuesInBAtt, int noOfValues);
void getMaximumValue(batteryParameter* tempSocValuesInBAtt, int noOfValues);
