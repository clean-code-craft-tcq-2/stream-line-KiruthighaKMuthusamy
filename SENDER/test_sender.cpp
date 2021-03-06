#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include"test/catch.hpp"
#include"sender.h"

int stubSensorSimulation()
{  
   static int value;
   value++;
   return value;
}


TEST_CASE("Checks the sender output Temperature and SOC physical value which is printed in a structure")
 {
	batteryParameter expectedOutput[2] = {{-39,2} ,{-38,2}};
	batteryParameter* actualOutput = getFromSensorSendToConsole(2,&stubSensorSimulation,&stubSensorSimulation,q1p0_o40,q0p5_o0,&printOnConsole);
	for (int i=0;i<2;i++)
	{
		REQUIRE(expectedOutput[i].temp == actualOutput[i].temp);
		REQUIRE(expectedOutput[i].soc == actualOutput[i].soc);
	}
	free(actualOutput);
		
}
