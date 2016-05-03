#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

//  ���Կ���
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain



template<class T>
string ToString(const T& t)
{

    ostringstream oss;  //  ����һ����

    oss <<t;            //  ��ֵ����������
    return oss.str( );  //  ��ȡת������ַ�ת������д��result
}

class Compare
{

public:

bool operator( )(string &left, string &right)
{
    string leftright = left + right;
    string rightleft = right + left;
    if(leftright > rightleft)
    {
        debug <<leftright <<" > " <<rightleft <<" -- " <<rightleft <<endl;
    }
    else
    {
        debug <<leftright <<" < " <<rightleft <<" -- " <<leftright <<endl;
    }

    return leftright < rightleft;
}

};
class Solution
{
public:


    string PrintMinNumber(vector<int> numbers)
    {
        string res = "";

        vector<string> strNum;
        string str;
        for(unsigned int i = 0; i < numbers.size( ); i++)
        {
            str = ToString(numbers[i]);
            strNum.push_back(str);
            debug <<str <<endl;
        }

        sort(strNum.begin( ), strNum.end( ), Compare());

        for(unsigned int i = 0; i < strNum.size( ); i++)
        {
            debug <<strNum[i];
            res += strNum[i];
        }
        debug <<endl;
        return res;
    }
};


int __tmain( )
{
    Solution solu;

    int arr[] = { 321, 32, 3 };
    vector<int> vec(arr, arr + 3);
    cout <<solu.PrintMinNumber(vec) <<endl;
    return 0;
}
