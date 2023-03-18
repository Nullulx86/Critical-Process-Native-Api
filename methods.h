#pragma once
#include "common.h"

namespace criticalProcessOn
{
	BOOL M1_CallRtlSetProcessIsCritical();
	BOOL M2_CallNtSetInformationThread();

}
namespace criticalProcessOff
{
	BOOL M1_CallRtlSetProcessIsCritical();
	BOOL M2_CallNtSetInformationThread();
}