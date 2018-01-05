#include "Input.h"

Input::Input()
{}

void Input::ChangeState(Keys key, bool state)
{
	keys[key] = state;
}

bool Input::Pressed(Keys key)
{
	if (keys[key] == nullptr)
	{
		keys[key] = false;
	}
	return (bool)keys[key];
}