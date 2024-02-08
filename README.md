# External Memory Editor

![Demo](https://github.com/uoRetr0/External-Memory-Editor/blob/main/demo.gif)

# Description

This project, External Memory Editor, is a C++ application designed to demonstrate advanced memory manipulation techniques within Windows processes. It specifically interacts with [Assault Cube](https://assault.cubers.net/), a lightweight multiplayer FPS game emphasizing tactical gameplay in realistic settings, supported by a strong modding community. Utilizing [Windows API](https://learn.microsoft.com/en-us/windows/win32/apiindex/windows-api-list) and process handling capabilities, the application showcases how to:

- Acquire the process ID (procId) for "ac_client.exe" through system snapshots
- Derive the module base address of the game's executable within its process space
- Open and interact with the process to read and modify specific memory addresses
- Employ direct memory access (DMA) techniques to navigate complex pointer chains and alter game state values in real-time

This utility serves as an educational tool to explore process manipulation, memory reading/writing, and the use of Windows system calls to interact with other software at a low level. While it demonstrates powerful capabilities, it's crucial to use such techniques responsibly and ethically, respecting software terms of service and copyright laws.

# Requirements

- Assault Cube version 1.2.0.2 for targeted memory manipulation
- Visual Studio for compiling and running the code

# Usage Instructions

This tool is designed to demonstrate advanced memory manipulation techniques on the "Assault Cube" game, specifically targeting version 1.2.0.2. To ensure successful operation, please adhere to the following usage instructions:

### Prerequisites

- **Visual Studio**: Required for compiling and running the code.
- **Assault Cube 1.2.0.2**: The specific game version targeted by this tool.

### Setup

1. Clone the repository to your local machine using Git:
    ```
    git clone https://github.com/uoRetr0/External-Memory-Editor
    ```
   Alternatively, you can download the ZIP file and extract it to your preferred location.

### Compilation

1. Open the solution file `External Memory Editor.sln` with Visual Studio.
2. **Architecture Compatibility**: Ensure the project's architecture matches that of the "Assault Cube" game. This can be configured in Visual Studio's toolbar, where you'll find a dropdown for architecture selection:
   - For 64-bit, select `x64`.
   - For 32-bit, select `x86`.
3. **Administrator Rights**: To run the compiled program with necessary permissions, you must set it to run as an administrator:
   - Open project properties by right-clicking on the solution in Solution Explorer and selecting Properties, or by pressing Alt+Enter.
   - Navigate to `Linker > Manifest File`, and set the `UAC Execution Level` to `requireAdministrator`.
4. Compile the project by building it within Visual Studio, or press `F5` to run without debugging, generating the executable.

## Running the Tool

- Make sure to run Visual Studio as an administrator to compile and execute the tool, ensuring it has the required permissions to modify process memory.
- Execute the compiled project, while "Assault Cube" is open and running, then boom, your ammo value should change.

# Future Improvements and Roadmap

While the current version of the External Memory Editor successfully demonstrates basic memory manipulation techniques within "Assault Cube", I am always looking to enhance its functionality and user experience. Here are some potential improvements I'm considering for future versions:

- **User Interface (UI)**: Develop a graphical user interface (GUI) to make the tool more accessible and user-friendly, allowing users to modify game values without needing to interact with the command line.
- **Advanced Memory Editing Features**: Introduce more complex memory editing capabilities, such as real-time memory scanning for values, and editing more game aspects beyond ammunition counts.

# Disclaimer

This project is intended for educational purposes, aiming to illustrate programming techniques for research and learning. It is not endorsed for cheating or any unethical use. Users are expected to comply with all relevant software terms of service, copyright laws, and ethical guidelines.
