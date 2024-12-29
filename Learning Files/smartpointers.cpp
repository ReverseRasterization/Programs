#include <iostream>
#include <memory>

class Entity {
    public:
        Entity()
        {
            std::cout << "Created Entity!" << '\n';
        }

        ~Entity()
        {
            std::cout << "Destroyed Entity!" << '\n';
        }

        void Print(){}
};

int main(){
    // Smart pointers delete pointers automatically, hell you dont even have to call new

    // Unique pointers call delete upon going out of scope, cannot be copied
    // {
    //     std::unique_ptr<Entity> entity = std::make_unique<Entity>(); // make_unique is slightly safer in the event of an exception
    //     //std::unique_ptr<Entity> e0 = entity; // this would error

    //     entity->Print(); // Created entity!
    // }

    // Entity has been destroyed :(

    // Shared pointer uses reference counting (keeping track of the amount of references to your pointer, when references reach 0, it gets deleted)

    //std::shared_ptr<Entity> e0;
    std::weak_ptr<Entity> e0;
    {
        std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>(); // Created here! 1 references
        e0 = sharedEntity; // 2 references

    } // 1 references (assuming e0 is also shared) (sharedEntity dies)

    // weak ptr e0 dies here because it doesn't increase the ref count
    

    return 0; // sharedptr e0 dies, the whole thing dies

}