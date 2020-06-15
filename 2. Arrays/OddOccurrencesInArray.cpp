/*
  A non-empty array A consisting of N integers is given. The array contains an odd number of elements, and each element of the array can be paired with another element that has the same value, except for one element that is left unpaired.
  For example, in array A such that:
    A[0] = 9  A[1] = 3  A[2] = 9
    A[3] = 3  A[4] = 9  A[5] = 7
    A[6] = 9
  the elements at indexes 0 and 2 have value 9,
  the elements at indexes 1 and 3 have value 3,
  the elements at indexes 4 and 6 have value 9,
  the element at index 5 has value 7 and is unpaired.
  Write a function:
  def solution(A)
  that, given an array A consisting of N integers fulfilling the above conditions, returns the value of the unpaired element.
  For example, given array A such that:
    A[0] = 9  A[1] = 3  A[2] = 9
    A[3] = 3  A[4] = 9  A[5] = 7
    A[6] = 9
  the function should return 7, as explained in the example above.
  Write an efficient algorithm for the following assumptions:
  N is an odd integer within the range [1..1,000,000];
  each element of array A is an integer within the range [1..1,000,000,000];
  all but one of the values in A occur an even number of times.
*/

int solution1(vector<int> &A) {
    
    sort(A.begin(), A.end()); 
    
    A.push_back(A[A.size() - 1] + 1);
    
    for (unsigned int i = 0; i < (A.size() - 1); i++)
    {
        if (i % 2 == 0)
        {
            if (A[i] != A[i + 1])
            {
                return A[i];
            }
        }
    }
    return 0; // should never happen only to mute compiler warning
}

#include <unordered_map>

int solution2(vector<int> &A) {
    unordered_map<int,int> m;
  
    for(unsigned i = 0; i < A.size(); i++)
    {
        unordered_map<int,int>::iterator res =  m.find(A[i]);
        if( res != m.end() )
        {
            res->second++;
        }
        else
        {
            m.insert( {A[i], 1} );
        }
    }
    for(auto i = m.begin(); i != m.end(); i++)
    {
        if(i->second % 2 != 0 )
        {
            return i->first;
        }
    }
    return 0;
}
