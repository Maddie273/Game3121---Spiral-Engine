#pragma once

void processPrint(int a)
{
	std::cout << "Processor Architecture: ";
	switch (a) {
	case 0: std::cout << "Intel x86" << std::endl;
		break;
	case 5: std::cout << "ARM" << std::endl;
		break;
	case 6: std::cout << "Intel Itanium-based" << std::endl;
		break;
	case 9: std::cout << "AMD x64" << std::endl;
		break;
	case 12: std::cout << "ARM64" << std::endl;
		break;
	default: std::cout << "Unknown" << std::endl;
		break;
	}
}

void GetArchitectureInfo() {

	SYSTEM_INFO siSysInfo;

	::GetSystemInfo(&siSysInfo);
	processPrint(siSysInfo.wProcessorArchitecture);
}