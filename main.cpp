#include "methods.h"

int main()
{
	BOOLEAN bl;
	ULONG BreakOnTermination;
	NTSTATUS status;
	char input[10];

	//To set a process as critical process using NtSetInformationProcess and RtlSetProcessIsCritical functions, the caller must have SeDebugPrivilege enabled.

	if (!NT_SUCCESS(RtlAdjustPrivilege(20, TRUE, FALSE, &bl)))
	{
		printf("Unable to enable SeDebugPrivilege. Make sure you are running this program as administrator.");
		return 1;
	}

	printf("Commands:\n\n");

	printf("[ on ] - Set the current process as critical process.\n"
		"[ off ]- Cancel the critical process status.\n"
		"[ exit ] - Terminate the current process.\n\n");
	for (;;)
	{

		printf("Enter command >> ");
		scanf_s("%s", input, sizeof(input));

		if (!strcmp("on", input))
		{
			memset(input, 0, sizeof(input));

			printf("\n[ 1 ] : Use RtlSetProcessIsCritical to set the process as critical process.\n"
				"[ 2 ] : Use NtSetInformationThread to set the process as critical process.\n");
				

			printf("Enter method number (ON) >> ");
			scanf_s("%s", input, sizeof(input));
			if (!strcmp("1", input))
			{
				printf("Method RtlSetProcessIsCritical (ON) running...\n");
				criticalProcessOn::M1_CallRtlSetProcessIsCritical();
			}
			else if (!strcmp("2", input))
			{
				printf("Method NtSetInformationThread (ON) running...\n");
				criticalProcessOn::M2_CallNtSetInformationThread();
			}

			else
			{
				printf("Error: unable to understand the entered input,please try again.\n");
			}
		}
		else if (!strcmp("off", input))
		{
			memset(input, 0, sizeof(input));

			printf("\n[ 1 ] : Use RtlSetProcessIsCritical to cancel the process as critical process.\n"
				"[ 2 ] : Use NtSetInformationThread to cancel the process as critical process.\n");

			printf("Enter method number (OFF) >> ");
			scanf_s("%s", input, sizeof(input));

			if (!strcmp("1", input))
			{
				printf("Method RtlSetProcessIsCritical (OFF) running...\n");
				criticalProcessOff::M1_CallRtlSetProcessIsCritical();
			}
			else if (!strcmp("2", input))
			{
				printf("Method NtSetInformationThread (OFF) running...\n");
				criticalProcessOff::M2_CallNtSetInformationThread();
			}

			else
			{
				printf("Error: unable to understand the entered input,please try again.\n");
			}
		}
		else if (!strcmp("exit", input))
		{
			break;
		}
		else
		{
			printf("Error: unable to understand the entered input,please try again.\n");
		}
	}
}