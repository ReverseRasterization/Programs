#include <iostream>
#include <ctime>

int main()
{	
	// pseudo-random = NOT truly random (but close)
	
	srand(time(NULL));

	int num = rand() % 6; // generates a number between 0 and 6

	std::cout << num;
	
	return 0;    
}
