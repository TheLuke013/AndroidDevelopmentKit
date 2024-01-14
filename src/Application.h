#ifndef GUI_CLASS_H
#define GUI_CLASS_H

#include <GLFW/glfw3.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

class Application
{
private:
	GLFWwindow* window;

public:
	~Application();

	void InitApp();
	void InitGUI();
	void CreateWindow();
	void CloseWindow();
	void CreateOpengGlContext();
	void RunApp();
};

#endif
