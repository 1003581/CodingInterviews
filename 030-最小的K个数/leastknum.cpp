#include <iostream>

using namespace std;

//  ���Կ���
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        
    }
};


int __tmain( )
{
    debug <<"test" <<endl;
    return 0;
}
