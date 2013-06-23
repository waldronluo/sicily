#include <iostream>
using namespace std;

class Animal {
    public:
        Animal(){};
        ~Animal(){};
    private:
        int age;
};

class Dog : public Animal {
    public:
        Dog(){};
        ~Dog(){};
        int age;
        void setAge (int n) {
            this->age = n;
        }
};

int main()
{

    Dog dog;
    dog.setAge (6);
    cout<<dog.age<<" is the age of current dog"<<endl;
    return 0;
}

