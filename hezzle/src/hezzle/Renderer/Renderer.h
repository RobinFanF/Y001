#pragma once


namespace hezzle
{
	enum class RendererAPI
	{
		None = 0,OpenGL = 1
	};

	class Renderer
	{
	public:
		 inline static RendererAPI GetAPI() { return m_RenderAPI; }

	private:
		static RendererAPI m_RenderAPI;

	};
}

