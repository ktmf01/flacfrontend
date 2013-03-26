// FLAC frontend.cpp : main project file.

#include <windows.h>
#undef GetTempPath
#include "Form1.h"

using namespace FLACfrontend;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew Form1());
	return 0;
}
