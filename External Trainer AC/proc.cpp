#include "proc.h"

DWORD GetProcId(const wchar_t* procName) {
	
	DWORD procId = 0;
	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0); //CreateToolhelp32Snapshot takes a snapshot of all procs and adding TH32CS_SBAPPROCESS to the parameter lets the procs be more specific (include procId, etc..), adding 0 lets it inlcude info about all proc

	if (hSnap != INVALID_HANDLE_VALUE) { //if CreateToolHelp32Snapshot() fails it returns INVALID_HANDLE_VALUE
		
		PROCESSENTRY32 procEntry;
		procEntry.dwSize = sizeof(procEntry);

		if (Process32First(hSnap, &procEntry)) { //Get the first process in the snapshot and store its information in procEntry

			do {
				if (!_wcsicmp(procEntry.szExeFile, procName)) { //Check if the current process matches the input process name
					
					procId = procEntry.th32ProcessID;
					break;
				}
			} while (Process32Next(hSnap, &procEntry));
		}
	}
	CloseHandle(hSnap); //Close the snapshot handle (prevent memory leak)
	return procId;
}

uintptr_t GetModuleBaseAddress(DWORD procId, const wchar_t* modName) {

	uintptr_t modBaseAddr = 0;
	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, procId);

	if (hSnap != INVALID_HANDLE_VALUE) {
		
		MODULEENTRY32 modEntry;
		modEntry.dwSize = sizeof(modEntry);

		if (Module32First(hSnap, &modEntry)) {
		
			do {
				
				if (!_wcsicmp(modEntry.szModule, modName)) {
					
					modBaseAddr = (uintptr_t)modEntry.modBaseAddr;
					break;
				}
			} while (Module32Next(hSnap, &modEntry));
		}
	}
	CloseHandle(hSnap);
	return modBaseAddr;
}

uintptr_t FindDMAAddress(HANDLE hProc, uintptr_t ptr, std::vector<unsigned int> offsets) { //DMA = Dyanmic Memory Allocation

	uintptr_t addr = ptr;
	for (unsigned int i = 0; i < offsets.size(); ++i) {
	
		ReadProcessMemory(hProc, (BYTE*)addr, &addr, sizeof(addr), 0);
		addr += offsets[i];
	}
	return addr;
}