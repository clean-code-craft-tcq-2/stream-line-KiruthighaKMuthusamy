#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include"sender.h"

stubSensorSimulationint stubSensorSimulation()
{  
   static int value;
   value++;
   return value;
}


TEST_CASE("Checks the sender output Temperature and SOC physical value which is printed in a structure)
 {
	batteryParameter* expectedOutput = {{-39,1} ,{-38,1},{-37,2},{-36,2},{-35,2},{-34,2},{-33,2},{-32,2} }
	batteryParameter* actualOutput = getFromSensorSendToConsole(8,&stubSensorSimulation,&stubSensorSimulation,q1p0_o40,q0p5_o0,&printOnConsole);
	for (int i=1;i<5;i++)
	{
		REQUIRE(expectedOutput[i].temp = actualOutput[i].temp);
		REQUIRE(expectedOutput[i].soc = actualOutput[i].soc);
	}
	free(actualOutput);
	free(expectedOutput);
	
}
