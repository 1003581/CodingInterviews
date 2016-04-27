#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//  ���Կ���
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain

class Solution
{
protected:
    vector<int> m_res;
public:

    vector<int> GetLeastNumbers_Solution(vector<int> numbers, int k)
    {
        m_res.clear( );
        LeastKNumbers_ByMinHeap(numbers, k);
        return m_res;
    }

    ///  ��������ǰK������
    vector<int> LeastKNumbers_BySort(vector<int> numbers, int k)
    {
        debug <<endl <<"line " <<__LINE__ <<"in function : "<<__func__ <<endl <<endl;

        vector<int> res;

        sort(numbers.begin( ), numbers.end( ));
        for(int i = 0; i < k; i++)
        {
            debug <<numbers[i] <<" ";
            res.push_back(numbers[i]);
        }
        debug <<endl;

        return res;
    }

    vector<int> LeastKNumbers_ByMinHeap(vector<int> numbers, int k)
    {
        make_heap(numbers.begin( ), numbers.end( ), greater_class());

        for(int i = 0; i < k; i++)
        {

            //  ��С��Ԫ����ջ��
            debug <<numbers[0] <<" ";
            m_res.push_back(numbers[0]);

            ///  һ�����ֲ���������
            // [1]  --  �����, Ȼ�����������
            //numbers.erase(numbers.begin( ));
            //sort_heap(numbers.begin( ), numbers.end( ));

            // [2]  --  ��Ȼ�Ӷѳ��������ջ��Ԫ��
            pop_heap(numbers.begin( ), numbers.end( ), greater_class( ));   // ����һ��Ԫ�غ�ʣ�µ����ؽ��� heap���Ա���heap������
            numbers.pop_back();         // vector ɾ��ĩβԪ��
        }
    }


};


int __tmain( )
{

    int arr[ ] = { 4, 5, 1, 6, 2, 7, 3, 8 };
    std::vector<int> vec(arr, arr + 8);

    Solution solu;
    solu.GetLeastNumbers_Solution(vec, 4);
    return 0;
}
