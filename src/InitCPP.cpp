//============================================================================
// Name        : InitCPP.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <D:\TrialProjects\VSCode\InitCPP\header\commonHeaders.h>


void WriteFormatted (FILE * stream, const char * format, ...)
{
  va_list args;
  va_start (args, format);
  vfprintf (stream, format, args);
  va_end (args);
}

int checkTypeCastPromotion()
{
    int n(10);
    double arra[n][5];
    int a = 7, b = 2;
    float c;
    c = a / b;
  
    cout << "Result of a/b : ["<<a<<"/"<<b<<"=]" << c;
	return EXIT_SUCCESS;
}


void fileOperation(void)
{
	FILE * qFile;
	char* fName = {"myl.txt"};

	qFile = fopen (fName,"w");

	WriteFormatted (qFile,"Call with %d variable argument.\n",1);
	WriteFormatted (qFile,"Call with %d variable %s.\n",2,"arguments");

	fclose (qFile);
}

int varArgfuncUsage(void) {

	char* xStr[256];
	int x, y(50);

	int &ptr1 = y, &ptr2 = ptr1;
	++ptr1; ++ptr2; // alias usage incrementing y with two diff name aliases
	cout << &ptr1 << "\t" << &ptr2 << "\n"; // aliases have same address (as of 'y' here)

	puts("in Function ");
    std::cout << "varArgfuncUsage\n";
	//gets(xStr);
	FILE * pFile;
    char sentence [256];

    fflush(stdout); // Will now print everything in the stdout buffer
	printf ("Enter sentence to append:\t");
    fflush(stdin); // Will now clear everything in the stdin buffer
    fgets (sentence,256,stdin);
    pFile = fopen ("mylog.txt","a");
    fputs (sentence,pFile);
    fclose (pFile);
    cout << "Enter any int" << "\t";
	scanf("%d",&x);
	// scanf("%d *[^\n]", &x); // beware enter key does not stop the scanning and *[^\n] says to ignore everything after your integer
							//  input that isn't a newline, but don't do anything with the newline (skip it).
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

	cout << checkTypeCastPromotion() << "\n";
	fileOperation();

	return EXIT_SUCCESS;
}