#pragma once

#include "hezzle/Input.h"
#include "hezzle/Application.h"
#include <GLFW/glfw3.h>

namespace hezzle
{
	class HEZZLE_API WindowsInput : public Input
	{	
	protected:
		virtual bool IsKeyPressedImpl(int keycode) override;

		virtual bool IsMousebuttonPressedImpl(int button);
		virtual std::pair<float, float> GetMousePositionImpl();
		virtual float GetMouseXImpl() ;
		virtual float GetMouseYImpl() ;


	};
}
