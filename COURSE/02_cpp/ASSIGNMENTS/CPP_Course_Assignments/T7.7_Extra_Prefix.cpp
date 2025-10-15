
/*  ________________________________________________________________________________________________________

    Task(7.7): Extra Prefix Sum:
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
    ___________________________________________________________________________________________________________
*/

/*  -------------------------------------------------------------------
                    Included Libraries.
    ------------------------------------------------------------------- */
#include <iostream>
#include <vector>
using namespace std;
/*  -------------------------------------------------------------------
                        Functions Prototype
    ------------------------------------------------------------------- */
// Function to process a single test case
void processTestCase();

/*  -------------------------------------------------------------------
                        Entry Point
    ------------------------------------------------------------------- */
int main()
{
    int T;
    cin >> T; // Number of test cases

    while (T--)
    {
        processTestCase(); // Process each test case separately
    }

    return 0; // End program successfully
}
/*  -------------------------------------------------------------------
                        Functions implementation
    ------------------------------------------------------------------- */
// Function to process a single test case
void processTestCase()
{
    int N;
    cin >> N; // Number of array elements

    vector<int> arr(N + 1, 0);       // Array (1-based indexing)
    vector<int> prefixSum(N + 1, 0); // Prefix sum array

    // Read input elements and compute prefix sum simultaneously
    for (int i = 1; i <= N; ++i)
    {
        cin >> arr[i];
        prefixSum[i] = prefixSum[i - 1] + arr[i]; // Prefix sum calculation
    }

    int Q;
    cin >> Q; // Number of queries

    while (Q--)
    {
        int L, R;
        cin >> L >> R;                                  // Query range [L, R]
        cout << prefixSum[R] - prefixSum[L - 1] << " "; // Answer query in O(1)
    }

    cout << endl; // New line after test case
}
