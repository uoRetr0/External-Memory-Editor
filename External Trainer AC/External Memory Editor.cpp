#include <iostream>
#include <vector>
#include <windows.h>
#include "proc.h"

int main() {
    //Get Process ID
    DWORD procId = GetProcId(L"ac_client.exe");

    //Get Module Base Address
    uintptr_t moduleBase = GetModuleBaseAddress(procId, L"ac_client.exe");

    //Get Handle to the Process
    HANDLE hProcess = 0;
    hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, procId);

    //Base address of ptr chain
    uintptr_t dynamicPtrBaseAddr = moduleBase + 0x10F4F4;

    std::cout << "Base Address = 0x" << std::hex << dynamicPtrBaseAddr << std::endl;

    //Ammo ptr chain
    std::vector<unsigned int> ammoOffsets = {0x374, 0x14, 0x0};
    uintptr_t ammoAddr = FindDMAAddress(hProcess, dynamicPtrBaseAddr, ammoOffsets);

    std::cout << "Ammo Address = 0x" << std::hex << ammoAddr << std::endl;
    
    //Read ammo value
    int ammoValue = 0;
    ReadProcessMemory(hProcess, (BYTE*)ammoAddr, &ammoValue, sizeof(ammoValue), nullptr);

    std::cout << "Ammo Value = " << std::dec << ammoValue << std::endl;

    //Write to ammo address
    int newAmmo = 9999999;
    WriteProcessMemory(hProcess, (BYTE*)ammoAddr, &newAmmo, sizeof(newAmmo), nullptr);

    //Read ammo value again
    ReadProcessMemory(hProcess, (BYTE*)ammoAddr, &ammoValue, sizeof(ammoValue), nullptr);

    std::cout << "New Ammo Value = " << std::dec << ammoValue << std::endl;

    //End
    getchar();
    return 0;   
}