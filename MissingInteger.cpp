/*
  
  This is a demo task.
  Write a function:
  int solution(vector<int> &A);
  that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.
  For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.
  Given A = [1, 2, 3], the function should return 4.
  Given A = [−1, −3], the function should return 1.
  Write an efficient algorithm for the following assumptions:
  N is an integer within the range [1..100,000];
  each element of array A is an integer within the range [−1,000,000..1,000,000].
  
*/

int solution1(vector<int> &A) {
    int N = A.size();
    vector <int> counter(N + 1);

    for (int i = 0; i < N ; i++)
    {
        if (A[i] > 0 && A[i] <= N + 1)
        {
            counter[A[i] - 1] = 1;
        }
    }

    for (int i = 0; i < N +1 ; i++)
    {
        if ( !(counter[i]) ) 
            return i + 1;
    }
  }

int solution2(vector<int> &A) {  
    int n = 1;
    sort(A.begin(), A.end());
    
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == n)
        {
            n++;
        }
    }
    return n;
}

#include <algorithm>
#include <set>
#include <iterator>
#include <numeric>

int solution3(vector<int> &A) {
    // set set from A
    set<int> p( A.begin(), A.end() );
    A.assign( p.begin(), p.end() );
    // create vector from with size 100
    std::vector<int> v(A.size() + 2);
    // fill vector with numbers from 1 to 100
    std::iota(v.begin(), v.end(), 1);
    // set set from 1 to A.size() + 2
    set<int> q(v.begin(), v.end());
    
    std::set<int> n; // use difference method
    std::set_difference(q.begin(), q.end(), p.begin(), p.end(),
    std::inserter(n, n.end()));
    
    int m = *min_element(n.begin(), n.end());
    
    return m;
}
