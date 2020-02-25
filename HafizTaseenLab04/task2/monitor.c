/**
 * Name: Taseen Hafiz
 * Lab/task: Lab 04 - Task 2
 * Date: 02/24/2020
 **/

#include "message.h"

int main(int argc, char *argv[])
{
//	//-----------Testing---------------
//	char temp[sizeof(MONITOR_QUEUE)+1];
//	for(int i=0; i< atoi(argv[2]); i++)
//	{
//		sprintf(temp, "%s%s%s","/", NODE_NAME_PREFIX, argv[2]);
//		printf("\n%s\n", temp);
//	}
//	//------------------------------------

	// Variables needed for queues
	mqd_t mon_msqid;				// Store monitor's queue id
	TEMPERATURE nodeData[atoi(argv[2])];  //Initializes array of node data specified from 3rd argument
	MESSG msg_rcvd, msg_send;
	pid_t pid;
	unsigned int type;
	bool loopFlag = true;
	float new_integrated_temp;
	float previuous_integrated_temp;
	float sum_of_client_temps;

	// String to store the name of the node in use
	char nodeStr[sizeof(NODE_NAME_PREFIX)+2];



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

		if ((nodeData[i].msqid = mq_open(nodeStr, O_RDWR | O_CREAT, S_IWUSR | S_IRUSR, &attr)) < 0)
		{   
			oops("SRV: Error opening a server queue.", errno);
		}   

		printf("SRV: Message queue %s created.\n", nodeStr+1);
	} 

	// Creates nodes as child processes
	for(int i = 0; i < atoi(argv[2]); i++)
	{
		sprintf(nodeStr, "%s%s%d","/", NODE_NAME_PREFIX, i);
		pid = fork();

		if (pid < 0) // error occurred
		{
			//oops("Fork Failed!");
		}

		if (pid == 0) // node_i child
		{
			if (execlp("./node", nodeStr, i, argv[i + 3], NULL) < 0) 
			{
				//	oops("Execlp Failed!");
			}
			printf("\n%s process created\n", nodeStr);
			break;	// Since it is the child, it will break for loop to prevent making children
		}		
	}

	// Reads node reports and processes data
	while(loopFlag)
	{
		if (mq_receive(mon_msqid, (char*) &msg_rcvd, MAX_MSG_SIZE, &type) >= 0)
		{
			loopFlag = false;	
		}
		loopFlag = false;	
	}
	exit(EXIT_SUCCESS);
}
