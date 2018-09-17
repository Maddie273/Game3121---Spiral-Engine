// SpiralEngine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <stdint.h>
#include <string>
#include <Windows.h>

using namespace std;

#define APPLICATION_INSTANCE_MUTEX_NAME "{SpiralEngineTesting}"
HANDLE gameRunning;

#ifdef _WIN32
#include <intrin.h>
uint64_t rdtsc() {
    return _rdtsc
}


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
    //////////////////////////////////////////
    
    uint64_t tick = rdtsc();
    for (int i =1; i <argc; ++i) {
        system(argv[i]);
    }
    cout << rdtsc() - tick << endl;
    
    
    
    
    
    
    
    return 0;
}
