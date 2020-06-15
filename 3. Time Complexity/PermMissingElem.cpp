/*
  An array A consisting of N different integers is given. The array contains integers in the range [1..(N + 1)], which means that exactly one element is missing.

  Your goal is to find that missing element.

  Write a function:

  int solution(vector<int> &A);

  that, given an array A, returns the value of the missing element.

  For example, given array A such that:

    A[0] = 2
    A[1] = 3
    A[2] = 1
    A[3] = 5
  the function should return 4, as it is the missing element.

  Write an efficient algorithm for the following assumptions:

  N is an integer within the range [0..100,000];
  the elements of A are all distinct;
  each element of array A is an integer within the range [1..(N + 1)].
*/
#include <numeric>

int solution1(vector<int> &A) {
    unsigned int s = A.size(); 
    unsigned int p = (s + 1) * (s + 2) / 2;
    unsigned int q = accumulate(A.begin(), A.end(), 0); 
    return p - q;
}

int solution2(vector<int> &A) {
    vector<int>H(A.size() + 1, 0);
    
    for (auto &i : A)
        H[i - 1] = 1;
    
    for (unsigned int i = 0; i < H.size(); i++ )
    {
        if (H[i] == 0)
            return i + 1;
    }
    
    return 0; // only to mute compiler warning !
}

#include <algorithm>

int solution3(vector<int> &A) {
    sort(A.begin(), A.end());
    int j = 1;
    for (auto &i : A)
        if (i == j)
            j++;
    return j;
}
