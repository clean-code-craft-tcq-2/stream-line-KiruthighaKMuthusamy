#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct compuFormulaCoEfficient
{
    float resolution;
    float offset;
}compuFormulaCoEfficient;

typedef struct batteryParameter
{
    int temp;
    int soc;
}batteryParameter;


float convertRawToPhy(int rawValue, compuFormulaCoEfficient coefficients);
int* getAndConvertValues(int noOfReadings,int(*fpGetRawValues)(void),compuFormulaCoEfficient coEfficient,int* phyValueArray);
batteryParameter* storeTheValues(int* tempPhyValueArray,int* socPhyValueArray,batteryParameter* tempSocValuesInBAtt,int noOfReadings);
batteryParameter* printOnConsole(batteryParameter* tempSocValuesInBAtt,int noOfReadings);
batteryParameter* getFromSensorSendToConsole(int noOfReadings,int(*fpGetTempValues)(void),int(*fpGetSocValues)(void),compuFormulaCoEfficient tempFormula,compuFormulaCoEfficient socFormula,batteryParameter* (*fpprintOnConsole)(batteryParameter* ,int ));

//Global Formulae declaration q:quotient ; p:point  ;o:offset
const compuFormulaCoEfficient q1p0_o40 = {1,-40};    // Internal-To-Physical:(Internal-40) 
const compuFormulaCoEfficient q0p5_o0 = {0.5,0};     // Internal-To-Physical:(Internal*0.5) 