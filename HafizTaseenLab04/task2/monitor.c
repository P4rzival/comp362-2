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
	for(int i=0; i< atoi(argv[2]); i++)
	{
		sprintf(temp, "%s%s%s","/", NODE_NAME_PREFIX, argv[2]);
		printf("\n%s\n", temp);
	}
	//------------------------------------

	// Variables needed for queues
	mqd_t mon_msqid;				// Store monitor's queue id
	mqd_t nod_msqid[atoi(argv[2])];	// Store nodes' queue id
	MESSG msg_rcvd, msg_send;

	// String to store the name of the node in use
	char nodeStr[sizeof(NODE_NAME_PREFIX)+1];



	// Removes message queues that are left from abnormal terminations (e.g., ^C) of monitor and nodes (for nodes, only the ones needed are going to be unlinked, if they exist)
	if (mq_unlink(MONITOR_QUEUE) == 0)
	{
		printf("\nSRV: Message queue %s removed.\n", MONITOR_QUEUE+1);
	}

	for(int i = 0; i < atoi(argv[2]); i++)
	{
		sprintf(nodeStr, "%s%s%d","/", NODE_NAME_PREFIX, i);
		if (mq_unlink(nodeStr) == 0)
		{
			printf("\nSRV: Message queue %s removed.\n", nodeStr+1);
		}
	}

	// Initialize the queue attributes
	struct mq_attr attr;

	attr.mq_maxmsg = 10;
	attr.mq_msgsize = MAX_MSG_SIZE;
	attr.mq_curmsgs = 0;
	attr.mq_flags = 0;

	// Creates recieving message queue for monitor
	if ((mon_msqid = mq_open(MONITOR_QUEUE, O_RDWR | O_CREAT, S_IWUSR | S_IRUSR, &attr)) < 0)
	{
		oops("SRV: Error opening a server queue.", errno);
	}

	printf("SRV: Message queue %s created.\n", MONITOR_QUEUE);

	// Creates sending message queues to beread by nodes
	for(int i = 0; i < atoi(argv[2]); i++)
	{   
		sprintf(nodeStr, "%s%s%d","/", NODE_NAME_PREFIX, i); 
		
		if ((nod_msqid[i] = mq_open(nodStr, O_RDWR | O_CREAT, S_IWUSR | S_IRUSR, &attr)) < 0)
		{   
			oops("SRV: Error opening a server queue.", errno);
		}   

		printf("SRV: Message queue %s created.\n", nodStr+1);
	} 

	// Creates nodes as child processes
	

	exit(EXIT_SUCCESS);
}
