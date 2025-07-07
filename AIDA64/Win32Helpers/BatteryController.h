#pragma once

namespace win32
{
	struct BatteryController
	{
		static BatteryController& Instance()
		{
			static BatteryController instance;
			return instance;
		}

		bool EnableEcoMode();
		bool DisableEcoMode();

	private:
	};
}