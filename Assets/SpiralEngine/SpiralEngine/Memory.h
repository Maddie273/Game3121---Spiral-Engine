#pragma once

void memTest()
{
	MEMORYSTATUSEX statex;

	statex.dwLength = sizeof(statex);

	GlobalMemoryStatusEx(&statex);

	std::cout << "There is " << statex.dwMemoryLoad << " percent of memory in use.\n";
	std::cout << "There are " << statex.ullTotalPhys / 1024 << " total KB of physical memory.\n";
	std::cout << "There are " << statex.ullAvailPhys / 1024 << " free  KB of physical memory.\n";
	std::cout << "There are " << statex.ullTotalVirtual / 1024 << " total KB of virtual memory.\n";
	std::cout << "There are " << statex.ullAvailVirtual / 1024 << " free  KB of virtual memory.\n";

}
