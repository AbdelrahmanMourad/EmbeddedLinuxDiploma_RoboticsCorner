#include <iostream>

// Abstract Class - {{{Can't make object of it}}}
// [Abstract class: has at least one pure virtual function]
// [Pure virtual function - Function with not implementation and Equals to zero]
class Sound
{
public:
    virtual void MakeSound() = 0; // Pure virtual function.
    virtual void SoundVolume()    // virtual function.
    {
        std::cout << "low\n";
    }

    /*-----------------------------------------------------------------------------------*/
    /*********** If you have virtual function, need to make VIRTUAL DESTRUCTOR ***********/
    /*********** If not use virtual, no derived destructors will be called ***************/
    virtual ~Sound() = default; // Will Call destructor of the object needed to be destroyed.
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

class Cow : public Sound
{
public:
    void MakeSound() override
    {
        std::cout << "Cow Sound\n";
    }
    void Chewing()
    {
        std::cout << "Chewing.....\n";
    }
    ~Cow()
    {
        std::cout << "destructor called in cow";
    }
};

class Cat : public Sound
{
public:
    void MakeSound() override // override (Optional-MISRA): ensure that override identiacl signature virtual function (Safety Mechanism).
    {
        std::cout << "Cow Sound\n";
    }
    ~Cat()
    {
        std::cout << "destructor called in cat";
    }
};

/***************How To use virtual function / abstracted class ***********/
#include <vector>

void RunAllSounds(std::vector<Sound *> Sounds)
{
    for (auto &Sound : Sounds)
    {
        Sound->MakeSound();
        if (Cow *cow = dynamic_cast<Cow *>(Sound)) // Check that Ptr is not nullptr.
        {
            cow->Chewing();
        }
        else if (Cat *cat = dynamic_cast<Cat *>(Sound))
        {
            // call cat specific method.
        }
    }
}

int main()
{
    Sound *obj_sound = new Cow; // Base/Super Class Pointer can point to derived class object. (but not vice versa)
    Cow *cow_ = new Cow;
    Cat *cat_ = new Cat;

    std::vector<Sound *> Sounds{obj_sound, cow_, cat_};
    RunAllSounds(Sounds);

    delete obj_sound, cat_, cow_;

    return 0;
}
