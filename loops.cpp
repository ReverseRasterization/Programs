#include <iostream>

int main()
{
	/* Do while loops
	
	int number;

	do{
		std::cout << "Enter a positive number: ";
		std::cin >> number;
	}while(number < 0);

	std::cout << "Your number is: " << number;
	

	// For loops
	
	for (int index = 1; index <= 2025; index++)
	{
		std::cout << index << '\n';
	}
	*/

	// Break & Continue
	// Break = Break out of a loop
	// Continue = Skip current iteration
	
	// Nested Loops

	for (int i = 1; i <= 3; i++){
		for (int j = 1; j<=10; j++){
			std::cout << j << ' ';
		}
	}	




	return 0;
}
