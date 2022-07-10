
#include "hzpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace hezzle
{

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		:m_WindowHandle(windowHandle)
	{
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		HZ_CORE_ASSERT(status, "glad initialize failed!");
		HZ_CORE_INFO("OpenGL Info :");
		HZ_CORE_INFO("Vendor : {0}", glGetString(GL_VENDOR));
		HZ_CORE_INFO("Render : {0}", glGetString(GL_RENDERER));
		HZ_CORE_INFO("Version : {0}", glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}

}
