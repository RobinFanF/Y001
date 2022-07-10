#pragma once

#include "Buffer.h"

#include <memory>

namespace hezzle
{
	class VertexArray
	{
	public:
		virtual ~VertexArray() {}

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual void AddVetexBuffer(std::shared_ptr<VertexBuffer>)  = 0;
		virtual void AddIndexBuffer(std::shared_ptr<IndexBuffer>)  = 0;

		static VertexArray* Create();
	};
}