#include "PadalecForm.h"

using namespace Padalec;


// usuwanie okna konsoli w finalnej wersji prorgramu
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

[STAThreadAttribute]
int main()
{

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew PadalecForm());

	return 0;
}