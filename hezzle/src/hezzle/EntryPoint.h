#pragma once


#ifdef HZ_PLATFORM_WINDOWS

extern hezzle::Application* hezzle::CreateApplication();

int  main(int argc,char ** argv)
{
	hezzle::Log::Init();
	HZ_CORE_WARN("Initialized Log!");

	int a = 5;
	HZ_CLIENT_INFO("Helloe engine{0}",a);
	auto app = hezzle::CreateApplication();
	app->Run();
	delete app;
}

#endif