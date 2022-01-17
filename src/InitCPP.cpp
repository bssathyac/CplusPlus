//============================================================================
// Name        : InitCPP.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include <stdarg.h>
#include <stdlib.h>
#include <D:\TrialProjects\VSCode\InitCPP\header\commonHeaders.h>


void WriteFormatted (FILE * stream, const char * format, ...)
{
  va_list args;
  va_start (args, format);
  vfprintf (stream, format, args);
  va_end (args);
}

int varArgfuncUsage(void) {

	char* xStr[256];
	int x, y(50);

	cout << "Enter any int" << "\n";
	scanf("%d",&x);
	int &ptr1 = y, &ptr2 = ptr1;
	++ptr1; ++ptr2;
	cout << &ptr1 << "\t" << &ptr2 << "\n";

	puts("Hello C World!!!");
    std::cout << "Hello, C++ world!\n";
	//gets(xStr);
	FILE * pFile;
    char sentence [256];

    printf ("Enter sentence to append: ");
    fflush(stdout); // Will now print everything in the stdout buffer
    fgets (sentence,256,stdin);
    pFile = fopen ("mylog.txt","a");
    fputs (sentence,pFile);
    fclose (pFile);
	printf("%d %s", x+y, sentence);
	/* *
	 * The stdout stream is line buffered by default, so will only display what's in the buffer after it reaches a newline (or when it's told to). You have a few options to print immediately:
	 * Print to stderrinstead using fprintf (stderr is unbuffered by default):
	 * fprintf(stderr, "I will be printed immediately");
	 * Flush stdout whenever you need it to using fflush:
	 * printf("Buffered, will be flushed");
	 * fflush(stdout); // Will now print everything in the stdout buffer
	 * Disable buffering on stdout by using setbuf:
	 * setbuf(stdout, NULL);
	 * Or use the more flexible setvbuf:
	 * setvbuf(stdout, NULL, _IONBF, 0);
	 * */

	 FILE * qFile;
	 char* fName = {"myl.txt"};

	   qFile = fopen (fName,"w");

	   WriteFormatted (qFile,"Call with %d variable argument.\n",1);
	   WriteFormatted (qFile,"Call with %d variable %s.\n",2,"arguments");

	   fclose (qFile);



	return EXIT_SUCCESS;
}
int checkTypeCastPromotion()
{
    int n(10);
    double arra[n][5];
    int a = 7, b = 2;
    float c;
    c = a / b;
  
    cout << "Result:" << c;
	return EXIT_SUCCESS;
}