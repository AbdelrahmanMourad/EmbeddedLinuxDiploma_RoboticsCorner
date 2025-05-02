#include <iostream>

class Sound
{
public:
    void MakeSound()
    {
        std::cout << "Sound\n";
    }
    void SoundVolume()
    {
        std::cout << "low\n";
    }
};

class Cow : public Sound
{
public:
    void MakeSound()
    {
        std::cout << "Cow Sound\n";
    }
};

class Cat : public Sound
{
public:
    void MakeSound()
    {
        std::cout << "Cow Sound\n";
    }
};

int main()
{
    // Now that it's not virtual - When calling the MakeSound() function from derived objects, the base function will be called.
    
    Sound *obj_sound = new Cow; // Base/Super Class Pointer can point to derived class object. (but not vise versa)
    obj_sound->MakeSound();     // Not virtual - "Sound" .. Not .. "Cow Sound"

    // /*******Heap***********/
    // Cat *cat = new Cat;
    // cat->MakeSound();
    // obj_sound = cat;
    // obj_sound->MakeSound();
    // obj_sound->SoundVolume();
    // delete obj_sound, cat;

    // /*******Stack***********/
    // Cow cow;
    // Sound &sound = cow;
    // sound.MakeSound();

    return 0;
}
