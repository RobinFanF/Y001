#include <Hezzle.h>

class ExampleLayer : public hezzle::Layer
{
public:
	ExampleLayer()
		:Layer("example")
	{
	}

	void OnUpdate() override
	{
		//HZ_CLIENT_INFO("ExampleLayer::update");
		if(hezzle::Input::IsKeyPressed(HZ_KEY_TAB))
			HZ_CLIENT_TRACE("Tab key is pressed!");
	}

	void OnEvent(hezzle::Event& event) override
	{
		//HZ_CLIENT_TRACE("{0}", event);
	}
};

class Sandbox : public hezzle::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}

};

hezzle::Application* hezzle::CreateApplication()
{
	return new Sandbox();
}