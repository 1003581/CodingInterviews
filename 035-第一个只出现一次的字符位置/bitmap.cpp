#include <iostream>
#include <cstring>

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
    int FirstNotRepeatingChar(string str)
    {
        int x[26] = {0}, y[26] = {0};
        for(unsigned int i = 0; i < str.size(); ++i)
        {
            //  Сд��ĸ
            if('a' <= str[i] && str[i] <= 'z')
            {
                if(x[str[i] - 'a'] == 0)
                {   
                    //  �״γ��ֱ������λ��
                    x[str[i] - 'a'] = i + 1;
                }
                else
                {
                    //  ���ֶ��, ���ñ�ʶ-1
                    x[str[i] - 'a'] = -1;
                }
            }

            // ��д��ĸ
            if('A' <= str[i] && str[i] <= 'Z')
            {
                if(y[str[i] - 'A'] == 0)
                {
                     //  �״γ��ֱ������λ��
                     y[str[i] - 'A']= i + 1;
                }
                else
                {
                    //  ���ֶ��, ���ñ�ʶ-1
                    y[str[i] - 'a']= -1;
                }
            }
        }

        //  ���ڱ�ʶ������
        //  ֻ����һ�ε��ַ���洢���ֵ�λ��
        //  ���ֶ�ε��ַ��ʹ洢��ʶ-1
        //  ��˲��������з�-1����Сֵ����
        int res = INT_MAX;
        for(int i = 0; i < 26; ++i)
        {
            if(x[i] != 0 && x[i] != -1)
            {
                res = min(res, x[i]);
            }
            if(y[i] != 0 && x[i] != -1)
            {
                res = min(res, y[i]);
            }
        }
        return res > str.size() ? -1 : res - 1;
    }
};

int __tmain( )
{

    Solution solu;
    cout <<solu.FirstNotRepeatingChar("google") <<endl;

    return 0;
}
