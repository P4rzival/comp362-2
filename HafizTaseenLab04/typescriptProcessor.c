#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
char* command;
char* processedBuffer;
	for(int i = 1; i <= argc; i++)
	{
printf("%s", argv[i]);
//		snprintf(command, sizeof(argv[i], "%s | perl -pe 's/\e([^\[\]]|\[.*?[a-zA-Z]|\].*?\a)//g' | col -b > processed-%s", argv[i], argv[i]);
//		system(command);
	}
}
