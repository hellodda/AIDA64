#include "pch.h"
#include "BatteryController.h"

namespace win32
{
	bool BatteryController::EnableEcoMode()
	{
		PROCESS_POWER_THROTTLING_STATE ThrottlingState = {};
		ThrottlingState.Version = PROCESS_POWER_THROTTLING_CURRENT_VERSION;
		ThrottlingState.ControlMask = PROCESS_POWER_THROTTLING_EXECUTION_SPEED;
		ThrottlingState.StateMask = PROCESS_POWER_THROTTLING_EXECUTION_SPEED;

		return SetProcessInformation(
			GetCurrentProcess(),
			ProcessPowerThrottling,
			&ThrottlingState,
			sizeof(ThrottlingState)
		);
		MessageBox(NULL, L"ECO", NULL, NULL);
	}
	bool BatteryController::DisableEcoMode()
	{
		PROCESS_POWER_THROTTLING_STATE ThrottlingState = {};
		ThrottlingState.Version = PROCESS_POWER_THROTTLING_CURRENT_VERSION;
		ThrottlingState.ControlMask = PROCESS_POWER_THROTTLING_EXECUTION_SPEED;
		ThrottlingState.StateMask = 0;

		return SetProcessInformation(
			GetCurrentProcess(),
			ProcessPowerThrottling,
			&ThrottlingState,
			sizeof(ThrottlingState)
		);

		MessageBox(NULL, L"NOECO", NULL, NULL);
	}
}