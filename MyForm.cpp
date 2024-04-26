#include "MyForm.h"
#include "Elec.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Fact::MyForm form;
	Application::Run(% form);
}

