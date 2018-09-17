// SpiralEngine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

#define APPLICATION_INSTANCE_MUTEX_NAME "{SpiralEngineTesting}"
HANDLE gameRunning;


void getCPUSpeed()
{
    CPUinfo * pInfo = this;
    LARGE_INTEGER qwWait, qwStart, qwCurrent;
    QueryPerformanceCounter(&qwStart);
    QueryPerformanceFrequency(&qwWait);
    qwWait.QuadPart >>= 5;
    unsigned _int64 Start = _rdtsc();
    do
    {
        QueryPerformanceCounter(&qwCurrent);
    }while (qwCurrent.QuadPart - qwStart.QuadPart < qwWait.QuadPart);
    pInfo->dCPUSpeedMHz = ((_rdtsc() - Start) << 5) / 1000000.0;
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
    
    cout << getCPUSpeed << endl;
    
    
    
    
    
    
    return 0;
}
