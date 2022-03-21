// C++ program to demonstrate working of
// Variadic function Template
#include <D:\TrialProjects\VSCode\InitCPP\header\commonHeaders.h>

// To handle base case of below recursive
// Variadic function Template
void print()
{
	cout << "I am empty function to mark the end and "
			"I am called at last after exhausting all args.\n";
}

// Variadic function Template that takes
// variable number of arguments and prints
// all of them.
template <typename T, typename... Types>
void print(T var1, Types... var2)
{
	cout << var1 << endl;

	print(var2...);
}

// Driver code
int checVariadicTemplate(void)
{
	print(1, 2, 3.14,
		"Pass me any "
		"number of arguments",
		"I will print\n");

	return 0;
}
