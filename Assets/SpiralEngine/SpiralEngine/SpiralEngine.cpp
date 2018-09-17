// SpiralEngine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include "StorageCheck.h"
#include "SingleInstance.h"
#include "CPUCheck.h"
#include "CPUSpeed.h"

using namespace std;

int main()
{
	if (singleInstance)
		cout << "Just one!\n";
	else
		cout << "Multiple?\n";

	if (storage())
		cout << "You've got enough space!" << endl;
	else
		cout << "Not enough space!" << endl;
	
		GetArchitectureInfo();
		cpuSpeed();
    cout << "Hello World!\n"; 
	return 0;
}
