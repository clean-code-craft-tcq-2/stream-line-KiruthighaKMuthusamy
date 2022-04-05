#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include"test/catch.hpp"
#include"SENDER/sender.h"

int stubSensorSimulation()
{  
   static int value;
   value++;
   return value;
}


TEST_CASE("Checks the sender output Temperature and SOC physical value which is printed in a structure")
 {
	batteryParameter expectedOutput[4] = {{-39,3} ,{-38,3},{-37,4},{-36,4}};
	batteryParameter* actualOutput = getFromSensorSendToConsole(4,&stubSensorSimulation,&stubSensorSimulation,q1p0_o40,q0p5_o0,&printOnConsole);
	for (int i=1;i<5;i++)
	{
		REQUIRE(expectedOutput[i].temp == actualOutput[i].temp);
		REQUIRE(expectedOutput[i].soc == actualOutput[i].soc);
	}
	free(actualOutput);
		
}
