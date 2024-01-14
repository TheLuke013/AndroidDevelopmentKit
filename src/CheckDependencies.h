#include <Windows.h>
#include <iostream>
#include <string>
#include <cstdlib>

#define INSTALL_JDK_SCRIPT_PATH "..\\scripts\\install_jdk.bat"
#define INSTALL_ANDROID_SDK_SCRIPT_PATH "..\\scripts\\install_android_sdk.bat"
#define INSTALL_COMMAND_LINE_TOOLS_SCRIPT_PATH "..\\scripts\\command_line_tools.bat"

#define SCRIPTS_FOLDER "..\\scripts"
#define DEPENDENCIES_FOLDER "..\\dependencies"
#define ANDROID_SDK_FOLDER "..\\dependencies\\AndroidSDK"
#define JDK_FOLDER "..\\dependencies\\jdk"
#define COMMAND_LINE_TOOLS_FOLDER "..\\dependencies\\AndroidSDK\\cmdline-tools"

//funcao auxiliar que verifica se um diretorio existe
bool DirectoryExists(const std::string& directoryPath);
//funcao auxiliar que verifica se um diretorio esta vazio
bool IsDirectoryEmpty(const std::string& directoryPath);
//funcao auxiliar que cria um novo diretorio
bool CreateNewDirectory(const std::string& directoryPath);
//funcao auxiliar que executa um script batch
bool RunScript(const std::string& scriptPath);
//se determinada dependencia nao estiver diponivel instale-a
bool CheckDependencie(const std::string& name, const std::string& scriptFolder, const std::string& scriptInstallFile);
//verifica todas dependencias necessarias
bool CheckDependencies();