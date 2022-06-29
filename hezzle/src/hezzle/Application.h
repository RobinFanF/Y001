#pragma once
#include "core.h"

namespace hezzle
{	 
	class HEZZLE_API Application
	{
	public:
		Application();
	virtual	~Application();

		void Run();

	};
	
	Application* CreateApplication();

}
