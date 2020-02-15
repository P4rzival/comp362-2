/**
 * Name: Taseen Hafiz
 * Lab/task: Lab 02
 * Date: 02/10/2020
 **/
// To run with cmake:	$ cmake ..
//						$ make

// For post-mortem debugging: $ ulimit -c unlimited

// Use Ctrl+D to simulate end of file when entering stdinput
// Instead of $ set | grep PATH, use $ printenv | grep PATH
// argv, argc-commandline arguments
// If sub run with no options then display -h
// freopen extra parameter so stdinput/output if not file is give

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include <stdbool.h>
#include <unistd.h>

// A function to print the help page whenever needed
void printHelp()
{
    puts("\nUSAGE:\n   sub [ -h | --fromChars -+toChars [-i inputFile] [-o outputFile] ]\n\nDESCRIPTION:\n   This utility copies text from an input stream to an output stream replacing every \n   instance of a specific character in fromChars with a corresponding (position-wise) \n   character from toChars. Any characters in fromChars and in toChars that do not \n   have corresponding counterparts in the other one are ignored. If an input file is \n   provided, the content is read from that file; otherwise, the standard input is used. \n   If an output file is provided, then the modified content is written to that file; \n   otherwise, the standard output is used.\n\nOPTIONS:\n   --(followed by a string without separating space)\n     indicates all characters that will be replaced in the processed text\n   -+(followed by a string without separating space) \n     indicates the characters that will be used to replace corresponding \n     (position-wise) characters from fromChars in the processed text\n   -i (followed by input file name) \n     use the provided file as an input stream instead of standard input \n   -o (followed by output file name) \n     use the provided file as an output stream instead of standard output \n   -h prints this help message\n");
}

int main(int argc, char* argv[])
{
    //	freopen("src.txt", "r", stdin);
    //	char* str;// = (char*) malloc(sizeof(char));
    //str[0] = '\0';
    //fclose(fp);
    //	char o = 'p';
    //	char i = 'o';
    //	char* h = argv[1]+1;
   for(int i = 1; i <= argc; i++)    
{
	for(int j = 0; j < (int) strlen(argv[i]); j++)
            {
			puts("yes");
}
}
//strncat(h, &o, 1);
    //strncat(h, &i, 1);
    //str = (char*) malloc((sizeof(h)+1)*sizeof(char));
    //strcpy(str, h);
    //	char ap[2] = "";
    //	ap[0] = app;

    //	printf("\n%s", h);
    //	printf("\nargc: %d\n %zu, %zu, %c\n", argc, strlen(argv[0]), strlen(argv[1]), argv[1][0]);

    // I did not fclose freopen since stdin and stdout were not used as it normaly  would be afterwards

//    // Variable to hold the char to be processed
//    char strBuffer;
//
//    // Flag for when errors are tripped so nothing will be replaced
//    bool errFlag = true;
//
//    // Flags for if --fromChars or -+toChars have chars associated with them
//    bool fromFlag = false;
//    bool toFlag = false;
//
//    // Flags for if -i or -o is used
//    bool fromFileFlag = false;
//    bool toFileFlag = false;
//
//    // Variables to hold the chars to be replaced
//    char* fromChars;
//    char* toChars;
//
//    // Variables to hold filenames for -i & -o
//    char* fromFile;
//    char* toFile;
//
//    // If sub is run with no arguments, help page is printed
//    if(argc == 1)
//    {
//        printHelp();
//    }
//    else
//    {
//        // Reads through each argument and determines what to do no matter the order except for when the input/output files are after -i and -o respectively
//        for(int i = 1; i <= argc; i++)
//        {
//            for(int j = 0; j < strlen(argv[i]); j++)
//            {
//                switch(argv[i][j])
//                {
//                case '-':
//                    switch(argv[i][j])
//                    {
//                    // Prints help page
//                    case 'h':
//                        // Prints help page if -h is not the only argument
//                        if(argc > 2)
//                        {
//                            puts("WARNING - \"-h\" was detected among other arguments, all other arguments will be ignored. Please read the help page for proper usage.\n");
//                        }
//                        printHelp();
//                        break;
//
//                    // Flag is set to true, storage is allocated, and chars to replace is stored if there exists fromChars
//                    case '-':
//                        if(strlen(argv[i]+2) == 0)
//                        {
//                            fromFlag = true;
//                        }
//                        else
//                        {
//                            fromChars = (char*) malloc(sizeof(argv[i]+2)*sizeof(char));
//                            strcpy(fromChars, argv[i]+2);
//                        }
//                        break;
//
//                    // Flag is set to true, storage is allocated, and chars substitutes is stored if there are toChars
//                    case '+':
//                        if(strlen(argv[i]+2) == 0)
//                        {
//                            toFlag = true;
//                        }
//                        else
//                        {
//                            toChars = (char*) malloc(sizeof(argv[i]+2)*sizeof(char));
//                            strcpy(toChars, argv[i]+2);
//                        }
//                        break;
//
//                    // Checks if next argument is a file that exists, if it does exist, storage is allocated and the name of the file is stored, and flag is set to true
//                    case 'i':
//                        if(access(argv[i+1], F_OK) == 0)
//                        {
//                            fromFile = (char*) malloc(sizeof(argv[i+1])*sizeof(char));
//                            strcpy(fromFile, argv[i+1]);
//                            fromFileFlag = true;
//                        }
//                        else
//                        {
//                            puts("sub: WARNING - File not found. Will read from stdin.");
//                        }
//                        break;
//
//                    // Checks if next argument is a file that exists, if it does exist, storage is allocated and the name of the file is stored, and flag is set to true
//                    case 'o':
//                        if(access(argv[i+1], F_OK) == 0)
//                        {
//                            toFile = (char*) malloc(sizeof(argv[i+1])*sizeof(char));
//                            strcpy(toFile, argv[i+1]);
//                            toFileFlag = true;
//                        }
//                        else
//                        {
//                            puts("sub: WARNING - File not found. Will print to stdout.");
//                        }
//                        break;
//
//                    // Issues an error for any invalid arguments that are provided and changes errFlag to false
//                    default:
//                        puts("\nsub: ERROR - Invalid arguments provided, printing help page.");
//                        errFlag = false;
//                        printHelp();
//                    }
//                }
//            }
//        }
//
//        if (fromFlag && toFlag)
//        {
//            // Issues a warning if there are more chars substitutes than chars to replace with
//            if(strlen(toChars) > strlen(fromChars))
//            {
//                puts("\nsub: WARNING - extraneous replacement character");
//            }
//
//            // Issues a error and changes errFlag to false if there are more chars to replace with than chars substitutes
//            else if(strlen(fromChars) > strlen(toChars))
//            {
//                puts("\nsub: ERROR - missing replacement character");
//                errFlag = false;
//            }
//        }
//
//        // Issues an error and changes errFlag to false if either no chars substitutes or no chars to be replaced
//        else
//        {
//            puts("\nsub: ERROR - No fromChars or no toChars provided.");
//            errFlag = false;
//        }
//
//        // If a source file was given, opens file stream into stdin
//        if(fromFileFlag)
//        {
//            freopen(fromFile, "r", stdin);
//        }
//
//        // If a destination file was given, writes to file from stdout
//        if(toFileFlag)
//        {
//            freopen(toFile, "w", stdout);
//        }
//
//        // Takes in sdin one char at a time, finds if it is one of fromChars, in which case it prints to stdout with the respective positionwise toChars
//        while(((strBuffer = getc(stdin)) != EOF) && errFlag)
//        {
//            for(int k = 0; k < strlen(fromChars); k++)
//            {
//                if(fromChars[k] == strBuffer)
//                {
//                    putc(toChars[k], stdout);
//                }
//            }
//        }
//    }
}
