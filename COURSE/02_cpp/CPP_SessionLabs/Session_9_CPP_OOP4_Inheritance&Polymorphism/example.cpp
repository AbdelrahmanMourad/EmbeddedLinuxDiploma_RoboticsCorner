// #include <iostream>
// #include <array>
// #include <functional>

// // Abstract class
// class Sound
// {
// public:
//     Sound() { std::cout << "Constructor Called: Sound.\n"; }
//     virtual void MakeSound() { std::cout << "Sound.\n"; }
//     virtual void SoundVolume() { std::cout << "Low.\n"; }
//     virtual ~Sound() { std::cout << "Destructor Called: Sound.\n"; }
// };

// // Derived classes
// class Cat : Sound
// {
// public:
//     Cat() { std::cout << "Constructor Called: Cat.\n"; }
//     void MakeSound() { std::cout << "Sound: Meow.\n"; }
//     void SoundVolume() { std::cout << "High.\n"; }
//     ~Cat() { std::cout << "Destructor Called: Cat.\n"; }
// };
// class Cow : Sound
// {
// public:
//     Cow() { std::cout << "Constructor Called: Cow.\n"; }
//     void MakeSound() { std::cout << "Sound: Moooh.\n"; }
//     void SoundVolume() { std::cout << "High.\n"; }
//     ~Cow() { std::cout << "Destructor Called: Cow.\n"; }
// };

// /********************************************
//  *  NOTE:
//  *      typedef unsigned char uint8_t;      // C-Style.
//  *              ==
//  *      using uint8 = unsigned char;        // C++ Style.
//  *********************************************/
// /* Implement the virtual table */
// // using FunctionPtr = void (Sound::*)();
// // std::array<FunctionPtr, 3> vtbl{&Sound::MakeSound, &Cat::MakeSound, &Cow::MakeSound};
// // static FunctionPtr vptr = vtbl[0];

// int main()
// {

//     Cat *cat = new Cat;
//     Cow *cow = new Cow;

//     delete cat;
//     delete cow;

//     // Sound *Cat_ptr = new Cat; // ERROR: Can't create object of abstract class (contain virtual functions).
//     // Cat_ptr->MakeSound();
//     // Cat_ptr->SoundVolume();

//     return 0;
// }



#include <iostream>
int main(){
// Optimize this code:
std::string s;
for (int i = 0; i < 1000; ++i) s += "abc";
}