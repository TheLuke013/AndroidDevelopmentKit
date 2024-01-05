#include <iostream>
#include <cstdlib>
#include <Windows.h>

#define SCRIPTS_FOLDER "..\\scripts"
#define INSTALL_JDK_SCRIPT_PATH "..\\scripts\\install_jdk.bat"
#define INSTALL_CMAKE_SCRIPT_PATH "..\\scripts\\install_cmake.bat"
#define DEPENDENCIES_FOLDER "..\\dependencies"
#define CMAKE_FOLDER "..\\dependencies\\cmake"
#define JDK_FOLDER "..\\dependencies\\jdk"

bool DirectoryExists(const std::string& directoryPath);
bool IsDirectoryEmpty(const std::string& directoryPath);
bool CreateNewDirectory(const std::string& directoryPath);
bool RunScript(const std::string& scriptPath);

bool CheckDependencies();