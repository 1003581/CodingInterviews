#include <iostream>
#include <vector>
#include <stack>
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
    ///  ������ ���Ҹ�
    ///  ��ô���ǵĽڵ�
    bool VerifySquenceOfBST(vector<int> sequence)
    {
        if(sequence.size( ) == 0)
        {
            return false;
        }
        int max = 0;
        stack<int> s;
        int it = sequence.size( ) - 1;
        do
        {
            s.push(sequence[it]);
            it--;
        }while(it >= 0 && sequence[it] > sequence[it + 1]);

        max = s.top( );

        for(;it >= 0; it--)
        {
            debug <<"curr = " <<sequence[it] <<", max = " <<max <<endl;

            if(max < sequence[it])  //  ǰ����Ԫ�ر����ֵ���󣬿϶�������Ҫ��
            {
                return false;
            }


            while(s.empty( ) != true && s.top( ) > sequence[it])
            {

                max = s.top();
                cout <<"max = " <<max <<endl;
                s.pop();
            }
            s.push(sequence[it]);
        }
        return true;
    }
};


int __tmain( )
{
//     10
//   6    14
//  8   12  16
//4




    int a[] = { 1, 2, 3 };

    vector<int> vec(a, a + 3);

    Solution solu;
    cout <<solu.VerifySquenceOfBST(vec) <<endl;
    return 0;
}
