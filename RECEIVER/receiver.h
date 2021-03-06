#include <stdio.h>

/*Assuming no negative values in the stream*/
#define MIN_TEMP_VALUE 0
#define MAX_TEMP_VALUE 100
#define MIN_SOC_VALUE 0
#define MAX_SOC_VALUE 100
#define NO_OF_VALUES 50

struct batteryParameter
{
  float temperature[NO_OF_VALUES];
  float SOC[NO_OF_VALUES];
};

extern float* structToTempArray(batteryParameter* tempSocValuesInBAtt);
extern float* structToSOCArray(batteryParameter* tempSocValuesInBAtt);
extern float getMinimumTempValue(float* temp, int noOfValues);
extern float getMinimumSOCValue(float* soc, int noOfValues);
extern float getMaximumTempValue(float* temp, int noOfValues);
extern float getMaximumSOCValue(float* soc, int noOfValues);
extern float getAverageOfLastFive(float* array, int noOfValues);
