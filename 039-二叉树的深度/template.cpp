#include <iostream>

using namespace std;

//  ���Կ���
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain




int __tmain( )
{
    debug <<"test" <<endl;
    return 0;
}
