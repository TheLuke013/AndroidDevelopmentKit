#include "Application.h"

#ifdef _WIN32
#pragma comment(linker, "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
#endif

int main()
{
	Application app;
	app.InitApp();
	app.RunApp();

	return 0;
}