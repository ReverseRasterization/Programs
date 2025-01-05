#include <iostream>
#include "LinkedList.h"

enum Item {
    Pickaxe,
    Axe,
    Shovel,
    Money
};

const int inventorySpace = 100;

int DisplayMenu(Node<Item>* selectedItem); // Returns the users choice in the form of an integer
void DisplayItemMenu(LinkedList<Item> inventory); // Displays the list of options
void DisplayInventory(LinkedList<Item> inventory); // Displays the inventory

Node<Item>* SelectItem(LinkedList<Item> inventory);
void PickUpItem(LinkedList<Item> inventory);
void DropItem(LinkedList<Item> inventory, Node<Item>* selectedItem);
void Inspect(Node<Item>* selectedItem);  



int main(){

    LinkedList<Item> inv(true);
    Node<Item>* selectedItem = nullptr;

    while(true){
        int option {DisplayMenu(selectedItem)};

        std::cout << "Your option: " << option << '\n';
    }

    return 0;
}

int DisplayMenu(Node<Item>* selectedItem){
    std::cout << "Please type in your input in the form of a number (1-6)\n";
    std::cout << "  1. Display Inventory\n";
    std::cout << "  2. Select Item\n";
    std::cout << "  3. Pick Up Item\n";
    std::cout << "  4. Drop Item\n";
    std::cout << "  5. Inspect Selected Item (" << selectedItem->data << ")\n";
    std::cout << "  6. Quit\n";
    std::cout << "> ";

    int x;

    while (true){
        std::cin >> x;

        if (x >= 1 && x <= 6){
            return x;
        }else {
            std::cout << "Invalid input, please input a number (1-5)\n";
        }
    }
}

void DisplayInventory(LinkedList<Item> inventory){
    return;
}

void DisplayItemMenu(LinkedList<Item> inventory){
    return;
}



