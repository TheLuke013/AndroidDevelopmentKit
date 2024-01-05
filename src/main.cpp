#include "CheckDependencies.h"

int main()
{
	//verifica as dependencias
	if (!CheckDependencies())
	{
		system("pause");
		return 1;
	}

	system("pause");

	return 0;
}