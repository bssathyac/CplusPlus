#include <D:\TrialProjects\VSCode\InitCPP\header\commonHeaders.h>

void swap(char *xp, char *yp) 
{ 
    char temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
// A function to implement bubble sort 
void bubbleSort(char arr[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)       
  
       // Last i elements are already in place    
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swap(&arr[j], &arr[j+1]); 
} 
char str[] = "Hello World Hi YThere xx yy zzz bb";
int strsize;
int i,j,k,flag;
int c = 0, count[26] = {0};
   
int letterCountInString(void) {
	// your code goes here
	
	strsize = sizeof(str);
	bubbleSort(str, strsize);
   while (c <= strsize)
   {

	  if ((str[c] >= 'a' && str[c] <= 'z') || (str[c] >= 'A' && str[c] <= 'Z'))

	  {
		 if (str[c] >= 'a' && str[c] <= 'z')
		 {
		 count[str[c]-'a']++;
		 }
		 else if (str[c] >= 'A' && str[c] <= 'Z')
		 {
		 count[str[c]-'A']++;
		 }
	  }

	  c++;
   }

   for (c = 0; c < 26; c++)
   {
	  if (count[c] == 2)
	  {
		 printf("%c, ",c+'a');
		 flag = 1;
	  }
   }
   
   if(flag == 0) printf("No Duplicates");

   printf("Done counting... \n");

	
	return 0;
}

