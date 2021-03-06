#include <algorithm>
#include <D:\TrialProjects\VSCode\InitCPP\header\commonHeaders.h>
 
void show(int a[], int array_size)
{
    for (int i = 0; i < array_size; ++i)
        cout << a[i] << " ";
}
 
// Driver code
int sortFuncFromAlgorithmLib()
{
    int a[] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
   
    // size of the array
    int asize = sizeof(a) / sizeof(a[0]);
    cout << "The array before sorting is : \n";
   
    // print the array
    show(a, asize); 
 
      // sort the array
    sort(a, a + asize); // args are start and end address of array
 
    cout << "\n\nThe array after sorting is :\n";
   
    // print the array after sorting
    show(a, asize);
 
    return 0;
}