#pragma once

using namespace System::Windows::Forms;
using namespace System::Collections;

ref class Input
{

public:

	enum class Direction
	{
		None, Up, Down, Right, Left
	};

	static void ChangeState(Keys key, bool state);

	static bool Pressed(Keys key);

	Input();

private:

	static Hashtable^ keys = gcnew Hashtable();

};

