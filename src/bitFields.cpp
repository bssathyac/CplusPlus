#include <D:\TrialProjects\VSCode\InitCPP\header\commonHeaders.h>

struct test {
	unsigned int x;
	unsigned int y : 33;
	unsigned int z;
};

struct test2 {
	unsigned int x;
	long int y : 33;
	unsigned int z;
};

union test3 {
	unsigned int x : 3;
	unsigned int y : 3;
	int z;
};

union test4 {
    struct byte
    {
	unsigned char B1 : 8;
	unsigned char B2 : 8;
	unsigned char B3 : 8;
	unsigned char B4 : 8;
    } BYTES;
	unsigned int z;
};

int chkOutput4()
{
	union test4 t;
	t.z = 0x1;
	printf("\n t.B1 = %d, t.B2 = %d, t.B3 = %d, t.B4 = %d",
		t.BYTES.B1, t.BYTES.B2, t.BYTES.B3,t.BYTES.B4);
	return 0;
}

int chkOutput3()
{
	union test3 t;
	t.x = 5;
	t.y = 4;
	t.z = 1;
	printf("\n t.x = %d, t.y = %d, t.z = %d",
		t.x, t.y, t.z);
	return 0;
}


int chkOutput2()
{
	struct test2 t;
	unsigned int* ptr1 = &t.x;
	unsigned int* ptr2 = &t.z;
	printf("%d \n", ptr2 - ptr1);
	return 0;
}

// Alignment requirements
// (typical 32 bit machine)

// char     1 byte
// short int  2 bytes
// int     4 bytes
// double    8 bytes

// structure A 4
typedef struct structa_tag
{
char    c;
short int  s;
} structa_t;

// structure B 8 
typedef struct structb_tag
{
short int  s;
char    c;
int     i;
} structb_t;

// structure C  24
typedef struct structc_tag
{
char    c;
double   d;
int 	 s;
} structc_t;

// structure D 16
typedef struct structd_tag
{
double   d;
int 	 s;
char    c;
} structd_t;

int structPadding()
{
printf("\nstructPadding\n");
printf("sizeof(structa_t) = %lu\n", sizeof(structa_t));
printf("sizeof(structb_t) = %lu\n", sizeof(structb_t));
printf("sizeof(structc_t) = %lu\n", sizeof(structc_t));
printf("sizeof(structd_t) = %lu\n", sizeof(structd_t));

return 0;
}


int checkBitFieldOutput()
{
	printf("%lu \n", sizeof(int));
	printf("%lu \n", sizeof(struct test));
    chkOutput2();
    chkOutput3();
    chkOutput4();
    structPadding();

	return 0;
}