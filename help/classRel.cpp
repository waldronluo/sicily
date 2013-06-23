#include <iostream>
#include <stdio.h>
using namespace std;

class Animal{
    public:
        int age; // attribute often puts here.
        Animal(){
            this->age = 5; // I give age a value here.
        }
        ~Animal(){}
};

class Dog:public Animal{
    public:
        Dog(){}
        ~Dog(){}
        int SetDog (){ //where is the defination of age?
            cin>>age;
            cout<<"dog is "<<age<<" ."<<endl;
            // if u want to change age and see it change, log it after your alternation.
        }
};
int main()
{
    Dog dog;
    for (;;) {
        dog.SetDog();// dog, not Dog. Dog is a class, dog is an instant.
        cout<<"dog is from animal"<<endl;
        cout <<"Press Y to continue."<<endl;// If u want to verify your change
        char c;//you should put it in a loop and log them out
        cin >> c;
        if ((c != 'y')&&(c  != 'Y')) //
            break; // these statements can be deleted.
    }
    return 0;
} 
