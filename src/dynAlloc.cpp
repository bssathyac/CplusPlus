#include <D:\TrialProjects\VSCode\InitCPP\header\commonHeaders.h>
#include <stdlib.h>
// 2D arrays with dynamic mem allocation 

/*
* 1) Using a single pointer and a 1D array with pointer arithmetic: 
*    A simple way is to allocate a memory block of size r*c and access its elements using simple pointer arithmetic. 
*/
int Cmethod1(void)
{
	int r = 3, c = 4;

	int* ptr = (int*) malloc((r * c) * sizeof(int));

	/* Putting 1 to 12 in the 1D array in a sequence */
	for (int i = 0; i < r * c; i++)
		ptr[i] = i + 1;

	/* Accessing the array values as if it was a 2D array */
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			printf("%d ", ptr[i * c + j]);
		printf("\n");
	}

	free(ptr);

	return 0;
}

// 2) Using an array of pointers 
// We can create an array of pointers of size r. Note that from C99, C language allows variable sized arrays. 
// After creating an array of pointers, we can dynamically allocate memory for every row.
int Cmethod2()
{
	int r = 3, c = 4, i, j, count;

	int* arr[r];
	for (i = 0; i < r; i++)
		arr[i] = (int*)malloc(c * sizeof(int));

	// Note that arr[i][j] is same as *(*(arr+i)+j)
	count = 10;
	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			arr[i][j] = ++count; // Or *(*(arr+i)+j) = ++count

	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			printf("%d ", arr[i][j]);

	/* Code for further processing and free the
	dynamically allocated memory */

	for (int i = 0; i < r; i++)
		free(arr[i]);

	return 0;
}

// 3) Using pointer to a pointer 
// We can create an array of pointers also dynamically using a double pointer.
//  Once we have an array pointers allocated dynamically, we can dynamically allocate memory and for every row like method 2. 

int Cmethod3()
{
	int r = 3, c = 4, i, j, count;

	int** arr = (int**)malloc(r * sizeof(int*));
	for (i = 0; i < r; i++)
		arr[i] = (int*)malloc(c * sizeof(int));

	// Note that arr[i][j] is same as *(*(arr+i)+j)
	count = 0;
	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			arr[i][j] = ++count; // OR *(*(arr+i)+j) = ++count

	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			printf("%d ", arr[i][j]);

	/* Code for further processing and free the
	dynamically allocated memory */

	for (int i = 0; i < r; i++)
		free(arr[i]);

	free(arr);

	return 0;
}

// 4) Using double pointer and one malloc call 

int Cmethod4()
{
	int r=3, c=4, len=0;
	int *ptr, **arr;
	int count = 0,i,j;

	len = sizeof(int *) * r + sizeof(int) * c * r;
	arr = (int **)malloc(len);

	// ptr is now pointing to the first element in of 2D array
	ptr = (int *)(arr + r);

	// for loop to point rows pointer to appropriate location in 2D array
	for(i = 0; i < r; i++)
		arr[i] = (ptr + c * i);

	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			arr[i][j] = ++count; // OR *(*(arr+i)+j) = ++count

	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			printf("%d ", arr[i][j]);

	return 0;
}

// 5) Using a pointer to Variable Length Array.

// The dimensions of VLA are bound to the type of the variable. Therefore one form a pointer to an array with run-time defined shape.
// The pointer has to be dereferenced before subscripting with syntax (*arr)[i][j].

int Cmethod5()
{
	int row = 3, col = 4, i, j, count;

    int (*arr)[row][col] = (int(*)[row][col]) malloc(sizeof *arr);

    count = 0;
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			(*arr)[i][j] = ++count;

	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			printf("%d ", (*arr)[i][j]);

	free(arr);
	
	return 0;
}

// 6) Using a pointer to the first row of VLA

// Similar to 5 but allows arr[i][j] syntax.

int Cmethod6()
{
	int row = 3, col = 4, i, j, count;

    int (*arr)[col] = (int (*)[col]) calloc(row, sizeof *arr);
	
	count = 0;
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			arr[i][j] = ++count;

	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			printf("%d ", arr[i][j]);

	free(arr);
	
	return 0;
}

// C++ program to dynamically allocate
// the memory for 2D array in C++, here 1D array is poised as 2D
// using new operator

// Driver Code
int Cppmethod1()
{
	// Dimensions of the 2D array
	int m = 3, n = 4, c = 0;

	// Declare a memory block of
	// size m*n
	int* arr = new int[m * n];

	// Traverse the 2D array
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {

			// Assign values to
			// the memory block
			*(arr + i * n + j) = ++c;
		}
	}

	// Traverse the 2D array
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {

			// Print values of the
			// memory block
			cout << *(arr + i * n + j)
				<< " ";
		}
		cout << "\n";
	}

	//Delete the array created
	delete[] arr;

	return 0;
}

// C++ program to dynamically allocate
// the memory for 2D array in C++
// using new operator, here 2 1D arrays are combined to behave as single 2D array

// Driver Code
int Cppmethod2()
{
	// Dimensions of the array
	int m = 3, n = 4, c = 0;

	// Declare memory block of size M
	int** a = new int*[m];

	for (int i = 0; i < m; i++) {

		// Declare a memory block
		// of size n
		a[i] = new int[n];
	}

	// Traverse the 2D array
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {

			// Assign values to the
			// memory blocks created
			a[i][j] = ++c;
		}
	}

	// Traverse the 2D array
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {

			// Print the values of
			// memory blocks created
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}

	//Delete the array created
	for(int i=0;i<m;i++) //To delete the inner arrays
	delete [] a[i];
	delete [] a;			 //To delete the outer array
							//which contained the pointers
							//of all the inner arrays
	
	return 0;
}


int dynAllocMemCandCPP(void)
{
    cout << "C method 1 \n";
    Cmethod1();
    cout << "C method 2 \n";
    Cmethod2();
    cout << "\n C method 3 \n";
    Cmethod3();
    cout << "\n C method 4 \n";
    Cmethod4();
    cout << "\n C method 5 \n";
    Cmethod5();
    cout << "\n C method 6 \n";
    Cmethod6();
    cout << "\n C++ method 1 \n";
    Cppmethod1();
    cout << "C++ method 2 \n";
    Cppmethod2();
	cout << "\n";


    return 0;
}
