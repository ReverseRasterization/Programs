#include <iostream>

int main() 
{
    int numbers[] = {3, 8, 1, 10, 5, 6, 7, 4, 2, 9};

    int size = sizeof(numbers)/sizeof(int);

    int temp;
    for (int _ = 0; _<size-1;_++)
    {
        for (int i = 0; i < size - _ - 1; i++)
        {
            if (numbers[i] > numbers[i+1]){
                temp = numbers[i];
                numbers[i] = numbers[i + 1];
                numbers[i + 1] = temp; 
            }

        }
        
    }

    for (int element : numbers){
        std::cout << element << '\n';
    }



    

    return 0;
}