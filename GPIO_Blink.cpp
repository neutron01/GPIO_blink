/*
  GPIO_Blink.cpp, turn on LED on GPIO pin 8  
  rocampo 4/27/2016
  adapted from gpio.cpp
 */

#include "stdafx.h"
#include "dln_generic.h"
#include "dln_gpio.h"
#include <iostream>
#pragma comment(lib, "dln.lib")

int main(int argc, _TCHAR* argv[])
{
	int d;  // dummy variable for wait

	// Open device
	HDLN device;
	DlnOpenUsbDevice(&device);

	// Configure pin 0 to input with pullup
	DlnGpioPinPullupEnable(device, 0);
	DlnGpioPinSetDirection(device, 0, 0);
	DlnGpioPinEnable(device, 0);

	// Configure pin 8 to output
	// DlnGpioPinSetDirection(device, 1, 1);
	// DlnGpioPinEnable(device, 1);
	DlnGpioPinSetDirection(device, 8, 1);
	DlnGpioPinEnable(device, 8);

	// Read pin 0 and set its iverted value on pin 1
	uint8_t value;
	DlnGpioPinGetVal(device, 0, &value);
	// DlnGpioPinSetOutVal(device, 8, value ^ 1);
	DlnGpioPinSetOutVal(device, 8, 1);

	std::cin >> d;  // pause until entered
	DlnGpioPinSetOutVal(device, 8, 0);

	// Disable gpio
	DlnGpioPinDisable(device, 0);
	DlnGpioPinDisable(device, 8);
	// Close device
	DlnCloseHandle(device);
	return 0;
}
