#include "MyForm.h"
#include "Elec.h"
#include "Tree.h"
#include "Input_form.h"
#include "Change_form.h"
#include <array>
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Fact::MyForm form;
	Application::Run(% form);
}

