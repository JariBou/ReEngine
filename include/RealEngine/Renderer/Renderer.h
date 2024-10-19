#pragma once

namespace Re
{
	class Renderer
	{
		public:
			Renderer() = default;
			Renderer(const Renderer&) = delete;
			Renderer(Renderer&&) = delete;
			~Renderer() = default;

			Renderer& operator=(const Renderer&) = delete;
			Renderer& operator=(Renderer&&) = delete;

		private:
	};
}
