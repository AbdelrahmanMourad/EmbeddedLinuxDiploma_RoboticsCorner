/*
    Adaptor == providing interfaces for legace code
*/

// use case 1

extern "C"  //  Means use c-style compiler => no name-mangling "no functions overloading"
{
#include <stdio.h>

    // Legacy c-code.
    void veryOldDraw()
    {
        printf("legacyDray\n");
    }
}



/*
---------------------------------------------------------------------------------
to build:
---------
    gcc -c .\functions.c    
            // this will generate .o file
    g++ -o adaptor .\adaptor.cpp .\legace.cpp .\functions.o         
            // Generate adaptor executable from all the other 3 files.
---------------------------------------------------------------------------------
*/