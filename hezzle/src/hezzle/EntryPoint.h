#pragma once


#ifdef HZ_PLATFORM_WINDOWS

extern hezzle::Application* hezzle::CreateApplication();

int  main(int argc,char ** argv)
{
	auto app = hezzle::CreateApplication();
	app->Run();
	delete app;
}

#endif