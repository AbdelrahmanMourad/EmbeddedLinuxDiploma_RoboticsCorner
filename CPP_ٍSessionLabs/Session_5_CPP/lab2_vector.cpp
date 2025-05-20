#include <iostream>
#include <vector>
#include <algorithm> // for lambdaa expression

/*  -------------------------------------------------------------------
    Session Agenda:
    ---------------
        - Dynamic Arrays.
        - Intro to OOP.
    -------------------------------------------------------------------
*/
/*  -------------------------------------------------------------------
                Vector (Dynamic allocated arrays)
    -------------------------------------------------------------------
    STL (Standard Template Libraries):
        - Containers
            - Array
            - Vector
        - Algo.abort
            - Sort
            - for each
        - Iterators
            -

    ----------------------------Using Vectors----------------------------------------
    #include <vector>

    // vector
    std::vector<int> list1;         // zero number of elements
    std::vector<int> list2(5);      // 5 of zero elements
    std::vector<int> list3(5, 100); // 5 element each of their values equal 100
                                    // |100|100|100|100|100|
    list3.push_back(6);             // will add at the end same size {5 element} , 1st is 6, rest are zeros
                                    // |100|100|100|100|100|6|0|0|0|0|


    --------------------------------------------------------------------
*/

namespace HelpingFunctions
{
    // print separator function.
    void PrintSeparatorFn(void)
    {
        std::cout << "---------------------\n";
    }
    void PrintTextFn(std::string text)
    {
        std::cout << text << std::endl;
    }
}

int main()
{
    // vector
    std::vector<int> list1;         // zero number of elements
    std::vector<int> list2(5);      // 5 of zero elements
    std::vector<int> list3(5, 100); // 5 element each of their values equal 100
                                    // |100|100|100|100|100|
    list3.push_back(6);             // will add at the end same size {5 element} , 1st is 6, rest are zeros
                                    // |100|100|100|100|100|6|0|0|0|0|

    // NOTE: if not assigning size, automatically it assigns "1 bytes"
    std::vector<int> nums1;
    nums1.push_back(100);
    std::cout << "size of vector = \t\"" << nums1.size() << "\"\t Bytes." << std::endl;

    /* NOTE: if assign size{5 Bytes},...
            with each push_back()
                -> size increase by 1
                        - if enough capacity it remains the same.
                        - if enough capacity it increase by the initial size {5 in this example}.

                        {Size > Capacity ... then increase Capacity x2}
    */
    // std::vector<int> nums2{5};
    // // {Size > Capacity ... then increase Capacity x2}
    // nums2.push_back(100); //    [Size=6,Capacity=10]
    // nums2.push_back(100); //    [Size=7,Capacity=10]
    // std::cout << "size of vector = \t\"" << nums2.size() << "\"\t Bytes." << std::endl;
    // std::cout << "Capacity of vector = \t\"" << nums2.size() << "\"\t Bytes." << std::endl;
    // nums2.push_back(100); //    [Size=8,Capacity=10]
    // nums2.push_back(100); //    [Size=9,Capacity=10]
    // std::cout << "Capacity of vector = \t\"" << nums2.capacity() << "\"\t Bytes." << std::endl;
    // nums2.push_back(100); //    [Size=10,Capacity=10]
    // std::cout << "Capacity of vector = \t\"" << nums2.capacity() << "\"\t Bytes." << std::endl;
    // nums2.push_back(100); //    [Size=11,Capacity=15]
    // std::cout << "Capacity of vector = \t\"" << nums2.capacity() << "\"\t Bytes." << std::endl;
    // nums2.push_back(100); //    [Size=12,Capacity=15]
    // std::cout << "Capacity of vector = \t\"" << nums2.capacity() << "\"\t Bytes." << std::endl;
    // nums2.push_back(100); //    [Size=13,Capacity=15]
    // std::cout << "size of vector = \t\"" << nums2.size() << "\"\t Bytes." << std::endl;
    // std::cout << "Capacity of vector = \t\"" << nums2.capacity() << "\"\t Bytes." << std::endl;

    std::vector<int> nums2{5, 100};
    // {Size > Capacity ... then increase Capacity x2}
    nums2.push_back(100); //    [Size=6,Capacity=10]
    nums2.push_back(100); //    [Size=7,Capacity=10]
    std::cout << "size of vector = \t\"" << nums2.size() << "\"\t Bytes." << std::endl;

    HelpingFunctions::PrintSeparatorFn();

    nums2.push_back(100); //    [Size=8,Capacity=10]
    nums2.push_back(100); //    [Size=9,Capacity=10]
    nums2.push_back(100); //    [Size=10,Capacity=10]
    nums2.push_back(100); //    [Size=11,Capacity=15]
    nums2.push_back(80);  //    [Size=12,Capacity=15]
    nums2.push_back(100); //    [Size=13,Capacity=15]
    std::cout << "size of vector = \t\"" << nums2.size() << "\"\t Bytes." << std::endl;
    std::cout << "Capacity of vector = \t\"" << nums2.capacity() << "\"\t Bytes." << std::endl;

    HelpingFunctions::PrintSeparatorFn();

    for (auto element : nums2)
    {
        // Print elements.
        std::cout << "n = \t" << element << "\n";
    }

    HelpingFunctions::PrintSeparatorFn();

    for (int i = 0; i < nums2.size(); i++)
    {
        std::cout << nums2[i] << "\n";
    }
    HelpingFunctions::PrintSeparatorFn();

    std::vector<int>::iterator it; // it's a pointer    // can replace with auto
    for (it = nums2.begin(); it != nums2.end(); ++it)
    {
        std::cout << "*it =\t" << *it << "\n";
    }

    // std::vector<int>::iterator it; // it's a pointer    // can replace with auto
    // for (auto it = nums2.begin(); it != nums2.end(); ++it)
    // {
    //     std::cout << "*it" << *it << "\n";
    // }

    /*
        We can use also the functions as used with arrays
        {{{{    Chech CPP Reference     }}}}

            push_bach()
            size()
            erase()
    */

    HelpingFunctions::PrintSeparatorFn();
    HelpingFunctions::PrintTextFn("Sort():");
    HelpingFunctions::PrintSeparatorFn();

    std::sort(nums2.begin(), nums2.end(), [](int a, int b)
              { return a > b; });

    for (auto it = nums2.begin(); it != nums2.end(); ++it)
    {
        std::cout << "*it =\t" << *it << "\n";
    }

    nums2.erase(std::remove(nums2.begin(), nums2.end(), 80));

    HelpingFunctions::PrintSeparatorFn();
    HelpingFunctions::PrintTextFn("erase element = 80:");
    HelpingFunctions::PrintSeparatorFn();

    for (auto it = nums2.begin(); it != nums2.end(); ++it)
    {
        std::cout << "*it =\t" << *it << "\n";
    }

    return 0;
}
