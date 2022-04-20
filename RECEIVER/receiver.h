#include <stdio.h>

/*Assuming no negative values in the stream*/
#define MIN_TEMP_VALUE 0
#define MAX_TEMP_VALUE 100
#define MIN_SOC_VALUE 0
#define MAX_SOC_VALUE 100
#define NO_OF_VALUES 50

typedef struct 
{
  float temperature[NO_OF_VALUES];
  float SOC[NO_OF_VALUES];
}batteryParameter;

extern float getMinimumTempValue(batteryParameter* tempSocValuesInBAtt, int noOfValues);
extern float getMinimumSOCValue(batteryParameter* tempSocValuesInBAtt, int noOfValues);
extern float getMaximumTempValue(batteryParameter* tempSocValuesInBAtt, int noOfValues);
extern float getMaximumSOCValue(batteryParameter* tempSocValuesInBAtt, int noOfValues);

