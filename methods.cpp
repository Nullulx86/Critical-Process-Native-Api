#include "methods.h"

BOOL criticalProcessOn::M1_CallRtlSetProcessIsCritical()
{
	if (!RtlSetProcessIsCritical(TRUE, NULL, FALSE)) 
	{
		printf("Successfully set the current process as critical process.\n\n");
		return TRUE;
	}
	else 
	{
		printf("Error: Unable to set the current process as critical process. RtlSetProcessIsCritical failed with status %d\n\n", ::GetLastError());
	}
}
BOOL criticalProcessOn::M2_CallNtSetInformationThread()
{
	ULONG BreakOnTerminationFlag = 1; // 1 : set the selected process as a critical process.
	
	// ProcessBreakOnTermination : this flag does not directly change the process to a critical process.
	// but ProcessBreakOnTermination flag set to TRUE can help ensure that the function completes successfully
	// FALSE for no critial process

	NTSTATUS status = NtSetInformationProcess((HANDLE)-1, ProcessBreakOnTermination, &BreakOnTerminationFlag, sizeof(ULONG));
	
	if (status != 0)
	{
		printf("Error: Unable to set the current process as critical process. NtSetInformationProcess failed with status %#x\n\n", status);
		return FALSE;
	}
    else
    {
	    printf("Successfully set the current process as critical process.\n\n");
		return TRUE;
    }
}


//-----------------------------------------------------------------------------------------------------------------------------------------

BOOL criticalProcessOff::M1_CallRtlSetProcessIsCritical()
{
	if (!RtlSetProcessIsCritical(FALSE, NULL, FALSE))
	{
		
		printf("Successfully canceled the current process as critical process.\n\n");
		return TRUE;
	}
	else
	{
		printf("Error: Unable to canceled the current process as critical process. RtlSetProcessIsCritical failed with ErrorCode %d\n\n", ::GetLastError());
	}
}

BOOL criticalProcessOff::M2_CallNtSetInformationThread()
{
	ULONG BreakOnTerminationFlag = 0; // 0 : cancel the selected a critical process to a normal process.

	// ProcessBreakOnTermination : this flag does not directly change the process to a critical process.
	// but ProcessBreakOnTermination flag set to TRUE can help ensure that the function completes successfully
	// FALSE for no critial process

	NTSTATUS status = NtSetInformationProcess((HANDLE)-1, ProcessBreakOnTermination, &BreakOnTerminationFlag, sizeof(ULONG));

	if (status != 0)
	{
		printf("Error: Unable to canceled the current process as critical process. NtSetInformationProcess failed with status %#x\n\n", status);
		return FALSE;
	}
	else
	{
		printf("Successfully canceled the current process as critical process.\n\n");
		return TRUE;
	}
}
