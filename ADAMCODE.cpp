#include "ADAMCODE.h"
#include <Windows.h>
using namespace Project3; // Название проекта
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) 
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
	return 0;
}
