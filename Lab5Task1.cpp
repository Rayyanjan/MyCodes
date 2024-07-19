#include <iostream>
using namespace std;

class Mammal
{
public:
    Mammal(void) : itsAge(1)
    {
        cout << "Mammal constructor..." << endl;
    }
    ~Mammal(void)
    {
        cout << "Mammal destructor..." << endl;
    }
    virtual void Move() const
    {
        cout << "Mammal moves a step!" << endl;
    }
    virtual void Speak() const
    {
        cout << "What does a mammal speak? Mammilian!" << endl;
    }

protected:
    int itsAge;
};
class dog : public Mammal
{
private:
    char gender;

public:
    dog(void) : gender('F')
    {
        cout << "Dog constructor....." << endl;
    }
    ~dog(void)
    {
        cout << "Dog has been destroyed...." << endl;
    }
    void Move() const override
    {
        cout << "dog moves a step!" << endl;
    }
    void Speak() const override
    {
        cout << "What does a dog speak? woof!" << endl;
    }
};
class cat : public Mammal
{
private:
    double height;

public:
    cat(void) : height(57.0)
    {
        cout << "cat constructor....." << endl;
    }
    ~cat(void)
    {
        cout << "cat has been destroyed...." << endl;
    }
    void Move() const override
    {
        cout << "cat moves a step!" << endl;
    }
    void Speak() const override
    {
        cout << "What does a cat speak? meow!" << endl;
    }
};
class Horse : public Mammal
{
private:
    char gender;

public:
    Horse(void) : gender('M')
    {
        cout << "Horse constructor....." << endl;
    }
    ~Horse(void)
    {
        cout << "Horse has been destroyed...." << endl;
    }
    void Move() const override
    {
        cout << "Horse moves a step!" << endl;
    }
    void Speak() const override
    {
        cout << "What does a Horse speak? neigh!" << endl;
    }
};
class Mouse : public Mammal
{
private:
    char gender;

public:
    Mouse(void) : gender('F')
    {
        cout << "Mouse constructor....." << endl;
    }
    ~Mouse(void)
    {
        cout << "Mouse has been destroyed...." << endl;
    }
    void Move() const override
    {
        cout << "Mouse moves a step!" << endl;
    }
    void Speak() const override
    {
        cout << "What does a Mouse speak? squeak!" << endl;
    }
};
int main () {
Mammal* theArray[5];
Mammal* ptr;
int choice, i;
for (i = 0; i<5; i++) {
cout << "(1)dog (2)cat (3)horse (4)mouse: ";
cin >> choice;
switch (choice) {
case 1: ptr = new dog; break;
case 2: ptr = new cat; break;
case 3: ptr = new Horse; break;
case 4: ptr = new Mouse; break;
default: ptr = new Mammal; break;
}
theArray[i] = ptr;
}
for (i=0;i<5;i++)
theArray[i]->Speak();
// Always free dynamically allocated objects
for (i=0;i<5;i++)
delete theArray[i];
}