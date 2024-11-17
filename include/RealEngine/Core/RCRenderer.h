#pragma once

#include <RealEngine/Core/Export.h>

#include "ReComponent.h"

namespace Re
{
	class RE_CORE_API RCRenderer : public ReComponent
	{
		public:
			void ComponentTick(ReEngine* Engine) override;

			RCRenderer() = default;
			RCRenderer(const RCRenderer&) = delete;
			RCRenderer(RCRenderer&&) = delete;
			~RCRenderer() = default;



			RCRenderer& operator=(const RCRenderer&) = delete;
			RCRenderer& operator=(RCRenderer&&) = delete;

		private:
	};
}


