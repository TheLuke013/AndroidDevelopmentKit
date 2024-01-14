#include "CheckDependencies.h"

//funcao auxiliar que verifica se um diretorio existe
bool DirectoryExists(const std::string& directoryPath)
{
	DWORD attributes = GetFileAttributesA(directoryPath.c_str());
	return (attributes != INVALID_FILE_ATTRIBUTES && (attributes & FILE_ATTRIBUTE_DIRECTORY));
}

//funcao auxiliar que verifica se um diretorio esta vazio
bool IsDirectoryEmpty(const std::string& directoryPath)
{
	WIN32_FIND_DATA findFileData;
	HANDLE hFind = FindFirstFile((directoryPath + "\\*").c_str(), &findFileData);

	if (hFind == INVALID_HANDLE_VALUE)
	{
		return true;
	}

	do
	{
		if (strcmp(findFileData.cFileName, ".") != 0 &&
			strcmp(findFileData.cFileName, "..") != 0)
		{
			FindClose(hFind);
			return false;
		}
	} while (FindNextFile(hFind, &findFileData) != 0);

	FindClose(hFind);

	return true;
}

//funcao auxiliar que cria um novo diretorio
bool CreateNewDirectory(const std::string& directoryPath)
{
	if (CreateDirectory(directoryPath.c_str(), nullptr) || GetLastError() == ERROR_ALREADY_EXISTS)
	{
		return true;
	}
	else
	{
		std::cerr << "Error creating directory. Error code: " << GetLastError() << std::endl;
		return false;
	}
}

//funcao auxiliar que executa um script batch
bool RunScript(const std::string& scriptPath)
{
	//executa o script batch do caminho especificado
	int result = system(scriptPath.c_str());
	//verifica se a execucao foi bem sucedida
	if (result == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//se determinada dependencia nao estiver diponivel instale-a
bool CheckDependencie(const std::string& name, const std::string& scriptFolder, const std::string& scriptInstallFile)
{
	std::cout << "Checking if " + name + " is installed" << std::endl;
	if (!DirectoryExists(scriptFolder))
	{
		if (!RunScript(scriptInstallFile))
		{
			std::cout << "Error: Unable to install " + name << std::endl;
			return false;
		}
	}
	else if (IsDirectoryEmpty(scriptFolder))
	{
		if (!RunScript(scriptInstallFile))
		{
			std::cout << "Error: Unable to install " + name << std::endl;
			return false;
		}
	}

	return true;
}

//verifica todas dependencias necessarias
bool CheckDependencies()
{
	/*verificacao dos scripts para garantir que tudo seja executado com sucesso*/
	std::cout << "Checking scripts folder..." << std::endl;

	//verifica se a pasta de scripts existe e se é um diretorio
	if (!DirectoryExists(SCRIPTS_FOLDER))
	{
		std::cout << "Script directory not found! Try reinstalling the program" << std::endl;
		return false;
	}
	
	//verifica se a pasta de scripts nao esta vazia
	if (IsDirectoryEmpty(SCRIPTS_FOLDER))
	{
		std::cout << "Scripts directory is empty! Try reinstalling the program" << std::endl;
		return false;
	}

	/*verificacao das dependencias do programa*/

	//verifica se a pasta de dependencias existe
	std::cout << "Checking dependencies folder..." << std::endl;
	if (!DirectoryExists(DEPENDENCIES_FOLDER))
	{
		if (!CreateNewDirectory(DEPENDENCIES_FOLDER))
		{
			return false;
		}
	}

	//verifica se o android sdk esta instalado e se o diretorio nao esta vazio
	CheckDependencie("Android SDK", ANDROID_SDK_FOLDER, INSTALL_ANDROID_SDK_SCRIPT_PATH);

	//verifica se o command line tools esta instalado e se o diretorio nao esta vazio
	CheckDependencie("Command Line Tools", COMMAND_LINE_TOOLS_FOLDER, INSTALL_COMMAND_LINE_TOOLS_SCRIPT_PATH);

	RunScript("..\\scripts\\sdk_dependencies.bat");

	return true;
}
