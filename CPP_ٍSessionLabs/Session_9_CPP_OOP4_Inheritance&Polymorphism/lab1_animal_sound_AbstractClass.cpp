#include <iostream>

// Abstract Class - {{{""""""Can't make object of it""""""}}}
// [Abstract class: has at least one pure virtual function]
// [Pure virtual function - Function with not implementation and Equals to zero]
class Animal
{
public:
    virtual void MakeSound() = 0;   // Pure virtual function.
    virtual void SoundVolume() = 0; // virtual function.

    /*-----------------------------------------------------------------------------------*/
    /*********** If you have virtual function, need to make VIRTUAL DESTRUCTOR ***********/
    /*********** If not use virtual, no derived destructors will be called ***************/
    virtual ~Animal() = default; // Will Call destructor of the object needed to be destroyed.
    // virtual ~Sound() // Same if we don't need default and wanna make specific implementation.
    // {
    //     std::cout << "Sound Destructor\n";
    // }
    // ~Sound() // If not use virtual, no derived destructors will be called
    // {
    //     std::cout << "Sound Destructor\n";
    // }
    /*-----------------------------------------------------------------------------------*/
};

class Cow : public Animal
{
public:
    void MakeSound() override { std::cout << "Cow Sound\n"; }
    ~Cow() { std::cout << "destructor called in cow"; }
};

class Cat : public Animal
{
public:
    void MakeSound() override { std::cout << "Cow Sound\n"; } // override (Optional-MISRA): ensure that override identiacl signature virtual function (Safety Mechanism).
    ~Cat() { std::cout << "destructor called in cat"; }
};

int main()
{

    // // Sound s;                 //  error - Abstract Class {can't make object form it.}
    // Animal *obj_sound = new Cow; // Base/Super Class Pointer can point to derived class object. (but not vise versa)
    // obj_sound->MakeSound();

    // /*******Heap***********/
    // Cat *cat = new Cat; // Pointer to derived class Cow.
    // cat->MakeSound();
    // obj_sound = cat;
    // obj_sound->MakeSound();
    // obj_sound->SoundVolume();
    // delete obj_sound, cat;

    // /*******Stack***********/
    // Cow cow;
    // Animal &sound = cow;
    // sound.MakeSound();
    return 0;
}
