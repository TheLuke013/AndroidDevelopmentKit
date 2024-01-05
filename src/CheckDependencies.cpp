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
		std::cout << "pasta criada" << std::endl;
		return true;
	}
	else
	{
		std::cerr << "Error creating directory. Error code: " << GetLastError() << std::endl;
		return false;
	}
}

bool CheckDependencies()
{
	/*verificacao dos scripts para garantir que tudo seja executado com sucesso*/

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
	if (!DirectoryExists(DEPENDENCIES_FOLDER))
	{
		if (!CreateNewDirectory(DEPENDENCIES_FOLDER))
		{
			return false;
		}
	}

	return true;
}
