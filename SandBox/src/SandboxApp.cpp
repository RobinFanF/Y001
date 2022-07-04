#include <Hezzle.h>

class Sandbox : public hezzle::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};

hezzle::Application* hezzle::CreateApplication()
{
	return new Sandbox();
}