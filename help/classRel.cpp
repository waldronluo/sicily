#include <iostream>
using namespace std;
class Animal{
    public:
        Animal(){}
        ~Animal(){}
        int age;
}
class Dog:public Animal{
    public:
        Dog(){}
        ~Dog(){}
        int SetDog{
            cout<<"dog is"<<age;
            cin>>age;
        }
}
int main(){
    Dog dog;
    Dog.SetDog();
    cout<<"dog is from animal":
        return 0;
} 
