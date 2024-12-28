#include <iostream>
#include <vector>

int main(){
    std::vector<int> vec {-1,-1};

    vec = {2,3};

    // Iterate through elements
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    /*

    // Add elements
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    // Access elements
    std::cout << "First element: " << vec.front() << std::endl;
    std::cout << "Last element: " << vec.back() << std::endl;

    // Iterate through elements
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    // Remove the last element
    vec.pop_back();

    // Insert an element at the beginning
    vec.insert(vec.begin(), 5);

    // Erase the first element
    vec.erase(vec.begin());

    // Clear the vector
    vec.clear();
    */

    return 0;   
}
