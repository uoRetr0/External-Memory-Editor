# External Memory Editor

![Demo](https://github.com/uoRetr0/External-Memory-Editor/blob/main/demo.gif)

# Description

This project, Game Memory Editor, is a C++ application designed to demonstrate advanced memory manipulation techniques within Windows processes. It specifically interacts with "Assault Cube", a lightweight multiplayer FPS game emphasizing tactical gameplay in realistic settings, supported by a strong modding community. Utilizing [Windows API](https://learn.microsoft.com/en-us/windows/win32/apiindex/windows-api-list) and process handling capabilities, the application showcases how to:

- Acquire the process ID (procId) for "ac_client.exe" through system snapshots
- Derive the module base address of the game's executable within its process space
- Open and interact with the process to read and modify specific memory addresses
- Employ direct memory access (DMA) techniques to navigate complex pointer chains and alter game state values in real-time

This utility serves as an educational tool to explore process manipulation, memory reading/writing, and the use of Windows system calls to interact with other software at a low level. While it demonstrates powerful capabilities, it's crucial to use such techniques responsibly and ethically, respecting software terms of service and copyright laws.
