#include <stdio.h>
#include "receiver.h"

float getMinimumTempValue(batteryParameter* tempSocValuesInBAtt) /* tempSocValuesInBAtt are available from the printconsole from the sender*/
{
  int i;
  float temp_min = MAX_TEMP_VALUE;
  for(i=0; i<noOfValues; i++)
  {
    if(tempSocValuesInBAtt[i].temperature < temp_min)
    {
      temp_min = tempSocValuesInBAtt[i].temperature;
    }    
  }
  return temp_min;
}

float getMinimumSOCValue(batteryParameter* tempSocValuesInBAtt) /* tempSocValuesInBAtt are available from the printconsole from the sender*/
{
  int i;
  float SOC_min = MAX_SOC_VALUE;
  for(i=0; i<noOfValues; i++)
  {
    if(tempSocValuesInBAtt[i].SOC < SOC_min)
    {
      SOC_min = tempSocValuesInBAtt[i].SOC;
    }    
  }
  return SOC_min;
}

float getMaximumTempValue(batteryParameter* tempSocValuesInBAtt) /* tempSocValuesInBAtt are available from the printconsole from the sender*/
{
  int i;
  float temp_max = MIN_TEMP_VALUE;
  for(i=0; i<noOfValues; i++)
  {
    if(tempSocValuesInBAtt[i].temperature > temp_max)
    {
      temp_max = tempSocValuesInBAtt[i].temperature;
    }    
  }
  return temp_max;
}

float getMaximumSOCValue(batteryParameter* tempSocValuesInBAtt) /* tempSocValuesInBAtt are available from the printconsole from the sender*/
{
  int i;
  float SOC_max = MIN_SOC_VALUE;
  for(i=0; i<noOfValues; i++)
  {
    if(tempSocValuesInBAtt[i].SOC > SOC_max)
    {
      SOC_max = tempSocValuesInBAtt[i].SOC;
    }    
  }
  return SOC_max;
}
