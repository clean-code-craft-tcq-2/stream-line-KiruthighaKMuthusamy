#include <stdio.h>
#include "receiver.h"

/*Interface functions to fetch from sender output structure to receiver input array*/
float* structToTempArray(batteryParameter* tempSocValuesInBAtt)/* tempSocValuesInBAtt is available from the printconsole from the sender*/
{
  int i;
  float temp[NO_OF_VALUES] = {0};
  for(i=0; i<NO_OF_VALUES; i++)
  {
    temp[i] = tempSocValuesInBAtt->temperature[i];    
  }
  return temp;
}

float* structToSOCArray(batteryParameter* tempSocValuesInBAtt)/* tempSocValuesInBAtt is available from the printconsole from the sender*/
{
  int i;
  float soc[NO_OF_VALUES] = {0};
  for(i=0; i<NO_OF_VALUES; i++)
  {
    soc[i] = tempSocValuesInBAtt->SOC[i];    
  }
  return soc;
}

float getMinimumTempValue(float* temp, int noOfValues) 
{
  int i;
  float temp_min = MAX_TEMP_VALUE;
  for(i=0; i<noOfValues; i++)
  {
    if(temp[i] < temp_min)
    {
      temp_min = temp[i];
    }    
  }
  return temp_min;
}

float getMinimumSOCValue(float* soc, int noOfValues) 
{
  int i;
  float SOC_min = MAX_SOC_VALUE;
  for(i=0; i<noOfValues; i++)
  {
    if(soc[i] < SOC_min)
    {
      SOC_min = soc[i];
    }    
  }
  return SOC_min;
}

float getMaximumTempValue(float* temp, int noOfValues) 
{
  int i;
  float temp_max = MIN_TEMP_VALUE;
  for(i=0; i<noOfValues; i++)
  {
    if(temp[i] > temp_max)
    {
      temp_max = temp[i];
    }    
  }
  return temp_max;
}

float getMaximumSOCValue(float* soc, int noOfValues) 
{
  int i;
  float SOC_max = MIN_SOC_VALUE;
  for(i=0; i<noOfValues; i++)
  {
    if(soc[i] > SOC_max)
    {
      SOC_max = soc[i];
    }    
  }
  return SOC_max;
}

float getAverageOfLastFive(float* array, int noOfValues)
{
  int i;
  float average = 0;
  for(i=0; i<5; i++)
  {
    average = *(array + (noOfValues-5));
    array++;
  }
  average = average/5;
  return average;
}
}
