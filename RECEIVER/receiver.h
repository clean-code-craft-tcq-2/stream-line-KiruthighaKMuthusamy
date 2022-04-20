#include <stdio.h>

/*Assuming no negative values in the stream*/
#define MIN_TEMP_VALUE 0
#define MAX_TEMP_VALUE 100
#define MIN_SOC_VALUE 0
#define MAX_SOC_VALUE 100
#define noOfValues 50

struct batteryParameter
{
  float temperature[noOfValues];
  float SOC[noOfValues];
};

extern float getMinimumTempValue(batteryParameter* tempSocValuesInBAtt);
extern float getMinimumSOCValue(batteryParameter* tempSocValuesInBAtt);
extern float getMaximumTempValue(batteryParameter* tempSocValuesInBAtt);
extern float getMaximumSOCValue(batteryParameter* tempSocValuesInBAtt);

