#include "Application.h"

Application::~Application()
{
	CloseWindow();
}

void Application::InitApp()
{
	CreateOpengGlContext();
	CreateWindow();
	InitGUI();
}

void Application::InitGUI()
{
	ImGui::CreateContext();
	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init();
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}

void Application::CreateWindow()
{
	window = glfwCreateWindow(1024, 600, "Android Prompt Kit", nullptr, nullptr);
	//verifica se a janela foi criada com sucesso
	if (window == NULL)
	{
		CloseWindow();
	}

	glfwMakeContextCurrent(window);
}

void Application::CloseWindow()
{
	glfwDestroyWindow(window);
}

void Application::CreateOpengGlContext()
{
	if (!glfwInit())
	{
		return;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void Application::RunApp()
{
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
	}
}
