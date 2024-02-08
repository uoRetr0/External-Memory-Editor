#include <vector>
#include <windows.h>
#include <TlHelp32.h>

//Takes a process name as input and returns its process ID (procId)
DWORD GetProcId(const wchar_t* procName);

uintptr_t GetModuleBaseAddress(DWORD GetProcId, const wchar_t* modName);

//Track down address from base using ptrs
uintptr_t FindDMAAddress(HANDLE hProc, uintptr_t ptr, std::vector<unsigned int> offsets);
