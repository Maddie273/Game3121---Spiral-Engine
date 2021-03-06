#pragma once
#include <Windows.h>
#include<iostream>

void cpuSpeed()
{
	char Buffer[_MAX_PATH];
	DWORD BufSize = _MAX_PATH;
	DWORD dwMHz = _MAX_PATH;
	HKEY hKey;

	// open the key where the proc speed is hidden:
	long lError = RegOpenKeyEx(HKEY_LOCAL_MACHINE,
		L"HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0",
		0,
		KEY_READ,
		&hKey);

	// query the key:
	RegQueryValueEx(hKey, L"~MHz", NULL, NULL, (LPBYTE)&dwMHz, &BufSize);

	// convert the DWORD to a CString:
	std::cout <<"CPU Frequency: "<< dwMHz << "MHz" << std::endl;
}
