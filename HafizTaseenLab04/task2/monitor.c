/**
 * Name: Taseen Hafiz
 * Lab/task: Lab 04 - Task 2
 * Date: 02/24/2020
 **/

#include "message.h"

int main(int argc, char *argv[])
{
//TEMPERATURE nodeData[argv[2]];  //Initializes array of node data specified from 3rd argument

char temp[sizeof(NODE_TEMP)+1];
for(int i=0; i<3; i++)
{
sprintf(temp, "%s%d", NODE_TEMP, i);
printf("\n%s\n", temp);
}
	exit(EXIT_SUCCESS);
}
