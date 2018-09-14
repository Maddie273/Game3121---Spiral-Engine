// SpiralEngine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

#define APPLICATION_INSTANCE_MUTEX_NAME "{SpiralEngineTesting}"
HANDLE gameRunning;

bool singleInstance(LPCWSTR spiralEngine)
{
	gameRunning = CreateMutex(NULL, true, spiralEngine);

	HWND window = FindWindow(spiralEngine, NULL);

	if (window) 
	{
		return false;
	}
	return true;
}

int main()
{
	if (singleInstance)
		cout << "Just one!\n";
	else
		cout << "Multiple?\n";
    std::cout << "Hello World!\n"; 
	return 0;
}
