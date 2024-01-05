#include <iostream>
#include <Shlwapi.h>

#define SCRIPTS_FOLDER "..\\..\\..\\scripts"
#define DEPENDENCIES_FOLDER "..\\..\\..\\dependencies"
#define INSTALL_JDK_SCRIPT_PATH "install_jdk.bat"
#define INSTALL_CMAKE_SCRIPT_PATH "install_cmake.bat"

bool DirectoryExists(const std::string& directoryPath);
bool IsDirectoryEmpty(const std::string& directoryPath);
bool CreateNewDirectory(const std::string& directoryPath);

bool CheckDependencies();