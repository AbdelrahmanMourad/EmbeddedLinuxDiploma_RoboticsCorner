/*________________________________________________________________________________________________________

    Task(7.7): Extra Prefix sum:
    ----------------------------

        You are given an array of N integers.
        You have to answer Q queries.
        Each query contains two integers L and R
        For each query print the sum of integers in array from index L to R

        Input :
            First line will contain an integer T (number of test cases).
            T blocks of line follows.
            First line of each block contains an integer N (number of array elements).
            Next line contains N integers (array elements).
            Next line contains an integer Q (number of queries).
            Next Q lines contain two integers L and R

        HINT:
            use prefix sum array.

        Sample Input :
            2 4 10 20 30
            40 2 1 4 2 3 5
            1 1 1 1 1 3 1 2
            2 5 5 5

        Sample Output:
            100 50 2 4 1
___________________________________________________________________________________________________________*/

/*  -------------------------------------------------------------------
                    Included Libraries.
    ------------------------------------------------------------------- */
#include <iostream>
#include <vector>
using namespace std;

/*  -------------------------------------------------------------------
                        Functions Prototype
    ------------------------------------------------------------------- */

    
/*  -------------------------------------------------------------------
                        Entry Point
    ------------------------------------------------------------------- */
int main()
{

    int T;
    cin >> T; // Number of test cases

    while (T--)
    {
        int N;
        cout << "Enter number of elements in the array: "; // Prompt for input
        cin >> N;                                          // Number of elements in the array

        // Read the array elements
        vector<int> arr(N);
        for (int i = 0; i < N; ++i)
        {
            cout << "Element[" << i << "]: "; // Prompt for each element
            cin >> arr[i];                    // Read array elements
        }

        // Build prefix sum array
        vector<int> prefix(N + 1, 0); // prefix[0] = 0
        for (int i = 1; i <= N; ++i)
        {
            prefix[i] = prefix[i - 1] + arr[i - 1];
        }

        // Output the prefix sum array for debugging
        int Q;
        cout << "Enter number of queries: "; // Prompt for input.
        cin >> Q;                            // Number of queries

        while (Q--)
        {
            // Read the query indices L and R (1-based)
            int L, R;
            cout << "Enter Query's L and R: "; // Prompt for input
            cin >> L >> R;                     // Query:  sum from index L to R (1-based)
            // Note: L and R are 1-based indices, so we need to adjust them for (0-based) indexing

            // Calculate sum using prefix sum array
            // prefix[R] - prefix[L-1] gives sum from L to R (inclusive)
            cout << (prefix[R] - prefix[L - 1]) << " ";
        }
    }
    cout << endl;
    return 0;
}

/*  -------------------------------------------------------------------
                        Functions implementation
    ------------------------------------------------------------------- */
