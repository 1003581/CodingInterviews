#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain

class Solution
{
public:
    /// ����һ
    /// ע�⵽Ŀ���� �������鳤�ȵ�һ�룬
    /// ������ͬʱȥ��������ͬ�����֣�
    /// �����ʣ�µ�һ�������Ǹ����֡�
    /// ���ʣ����������ô������Ҳ��һ���ģ����ǽ������
    /// ��������ϰ����ʣ�µ�һ�����ֻ��������ص�ԭ�������У�
    /// ���������һ��ͳ��һ�����ֳ��ִ������������жϡ�

    int MoreThanHalfNum_Solution(vector<int> numbers)
    {



};


int __tmain( )
{
    int arr1[] = { 5, 5, 2, 2, 3, 3, 5, 5, 5};

    vector<int> vec1(arr1, arr1 + 9);

    Solution solu;
    cout <<solu.MoreThanHalfNum_Solution(vec1) <<endl;


    int arr2[] = { 1, 2 };

    vector<int> vec2(arr2, arr2 + 2);
    cout <<solu.MoreThanHalfNum_Solution(vec2) <<endl;
    return 0;
}
