/**
 * Name: Taseen Hafiz
 * Lab/task: Lab 04 - Task 2
 * Date: 02/24/2020
 **/

#include "message.h"

int main(int argc, char *argv[])
{
	mqd_t mon_msqid;	// Store monitor's queue id
	mqd_t nod_msqid;	// Store nodes' queue id
	MESSG msg_rcvd, msg_send;
	unsigned int type;
	bool loopFlag = true;
	float new_node_temp;
	float previous_node_temp;
	float new_integrated_temp;
	TEMPERATURE nodeData;

	// String to store the name of the node in use
	char nodeStr[sizeof(NODE_NAME_PREFIX)+2];
	sprintf(nodeStr, "%s%s%d","/", NODE_NAME_PREFIX, atoi(argv[1]));	

	if ((mon_msqid = mq_open(MONITOR_QUEUE, O_WRONLY)) < 0)
	{
		oops("CLI: Error opening a queue.", errno);
	}

	if ((nodeData.msqid = mq_open(nodeStr, O_RDONLY)) < 0)
	{   
		oops("CLI: Error opening a queue.", errno);
	}

	msg_send.nodeId = atoi(argv[1]);	// Stores current node id

	// Returned "error: pointer value used where a floating point value was expected" on these lines and I'm not sure why
	//msg_send.temperature = (float)argv[2];
	//nodeData.previousTemperature = (float)argv[2];

	while(loopFlag)
	{
		if (mq_send(mon_msqid, (char *) &msg_send, sizeof(MESSG), (unsigned int) TYPE) < 0)
		{
			oops("CLI: Error sending a message.", errno);
		}

		if (mq_receive(nodeData.msqid, (char *) &msg_rcvd, MAX_MSG_SIZE, &type) < 0)
		{
			oops("CLI: Error receiving data.", errno);	
		}

		// If the recieved stable flag is false, end the loop, otherwise, recalculate temp and continue
		if(msg_rcvd.stable)
		{
			loopFlag == false;
		}

		//		new_node_temp  = (previous_node_temp * 3 + 2 * new_integrated_temp) / 5;

	}

	exit(EXIT_SUCCESS);
}
