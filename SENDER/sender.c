#include"sender.h"

float convertRawToPhy(int rawValue, compuFormulaCoEfficient coefficients)
{
    return ((rawValue*coefficients.resolution)+coefficients.offset);
}

int* getAndConvertValues(int noOfReadings,int(*fpGetRawValues)(void),compuFormulaCoEfficient coEfficient,int* phyValueArray)
{
    
    for(int i=0;i<noOfReadings;i++)
    {       
       phyValueArray[i] = round(convertRawToPhy(fpGetRawValues(),coEfficient));
    }
    return phyValueArray;
}

batteryParameter* storeTheValues(int* tempPhyValueArray,int* socPhyValueArray,batteryParameter* tempSocValuesInBAtt,int noOfReadings)
{
    for(int i=0;i<noOfReadings;i++)
    {       
       tempSocValuesInBAtt[i].temp = tempPhyValueArray[i];
       tempSocValuesInBAtt[i].soc = socPhyValueArray[i] ;
    }
    return tempSocValuesInBAtt;
}

batteryParameter* printOnConsole(batteryParameter* tempSocValuesInBAtt,int noOfReadings)    // This function has return statement so that the receiver can replace the function with their function to get the values of tempSocValuesInBAtt
{
      for(int i=0;i<noOfReadings;i++)
    {
      printf("Temp:%d   SOC:%d\n", tempSocValuesInBAtt[i].temp ,tempSocValuesInBAtt[i].soc) ;
    }
	return tempSocValuesInBAtt;
}
batteryParameter* getFromSensorSendToConsole(int noOfReadings,int(*fpGetTempValues)(void),int(*fpGetSocValues)(void),compuFormulaCoEfficient tempFormula,compuFormulaCoEfficient socFormula,batteryParameter* (*fpprintOnConsole)(batteryParameter* ,int ))
{   
    //Memory creation
    int* tempPhyValueArray = (int*)calloc(noOfReadings,sizeof(int*));
    int* socPhyValueArray = (int*)calloc(noOfReadings,sizeof(int*));
   batteryParameter* tempSocValuesInBAtt = (batteryParameter*)calloc(noOfReadings,sizeof(batteryParameter*));
       
  tempPhyValueArray =  getAndConvertValues(noOfReadings,fpGetTempValues,tempFormula, tempPhyValueArray);
  socPhyValueArray = getAndConvertValues(noOfReadings,fpGetSocValues,socFormula,socPhyValueArray);
  
 tempSocValuesInBAtt = storeTheValues(tempPhyValueArray,socPhyValueArray,tempSocValuesInBAtt,noOfReadings);
 
 fpprintOnConsole(tempSocValuesInBAtt,noOfReadings);
    
  //Memory clear
  free(tempPhyValueArray);
  free(socPhyValueArray);
  
  return tempSocValuesInBAtt;
}
