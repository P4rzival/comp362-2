/**
 * Name: Taseen Hafiz
 * Lab/task: Lab 04 - Task 2
 * Date: 02/24/2020
 **/

#include "message.h"

int main(int argc, char *argv[])
{
	//TEMPERATURE nodeData[argv[2]];  //Initializes array of node data specified from 3rd argument
	//-----------Testing---------------
	char temp[sizeof(MONITOR_QUEUE)+1];
	for(int i=0; i<3; i++)
	{
		sprintf(temp, "%s%s%d","/", NODE_NAME_PREFIX, i);
		printf("\n%s\n", temp);
	}
	//------------------------------------

	// String to store the name of the node in use
	char nodeStr[sizeof(NODE_NAME_PREFIX)+1];

	// Removes message queues that are left from abnormal terminations (e.g., ^C) of monitor and nodes (for nodes, only the ones needed are going to be unlinked, if they exist)
	if (mq_unlink(MONITOR_QUEUE) == 0)
	{
		printf("\nSRV: Message queue %s removed.\n", MONITOR_QUEUE+1);
	}

	for(int i = 0; i < argv[2]; i++)
	{
		sprintf(nodeStr, "%s%s%d","/", NODE_NAME_PREFIX, i);
		if (mq_unlink(nodeStr) == 0)
		{
			printf("\nSRV: Message queue %s removed.\n", nodeStr+1);
		}
	}
	exit(EXIT_SUCCESS);
}
