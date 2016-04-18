#链接
------- 
>牛客OJ：[顺时针打印矩阵](http://www.nowcoder.com/practice/9b4c81a02cd34f76be2659fa0d54342a?tpId=13&tqId=11172&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)
> 
>九度OJ：http://ac.jobdu.com/problem.php?pid=1391
> 
>GitHub代码： [020-顺时针打印矩阵](https://github.com/gatieme/CodingInterviews/tree/master/020-顺时针打印矩阵)
>
>CSDN题解：[剑指Offer--020-顺时针打印矩阵](http://blog.csdn.net/gatieme/article/details/51182615)

| 牛客OJ | 九度OJ | CSDN题解 | GitHub代码 | 
| ------------- |:-------------:| -----:| 
|[顺时针打印矩阵](http://www.nowcoder.com/practice/9b4c81a02cd34f76be2659fa0d54342a?tpId=13&tqId=11172&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking) | [1391-顺时针打印矩阵](http://ac.jobdu.com/problem.php?pid=1391) | [剑指Offer--020-顺时针打印矩阵](http://blog.csdn.net/gatieme/article/details/51182615) | [020-顺时针打印矩阵](https://github.com/gatieme/CodingInterviews/tree/master/020-顺时针打印矩阵) |


#题意

-------

**题目描述**

题目描述

输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，

例如，
如果输入如下矩阵： 

>1 2 3 4 
>5 6 7 8 
>9 10 11 12 
>13 14 15 16 

则依次打印出数字

>1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10


#类似与蛇形填数
-------
```cpp
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

//  调试开关
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain

class Solution
{
public:
    vector<int> printMatrix(vector<vector<int> > matrix)
    {

        int row = matrix.size( );
        int col = matrix[0].size( );

        int left = 0, right = col, up = 0, down = row;      //  限制当前遍历的数的范围在行ROW[left, right), COL[left, right)

        int x = 0, y = 0;                                   //  当前遍历的下标
        int count = 0, max_count = row * col;               //  当前遍历的数据的个数

        vector<int> res;
        res.push_back(matrix[x][y]);

        for(count = 1; count < max_count;)
        {
            //  turn right y++
            for(y++; y < right && count < max_count; y++)
            {
                res.push_back(matrix[x][y]);
                debug <<"right-[" <<x <<", " <<y <<"] = " <<matrix[x][y] <<", count = " <<count <<endl;
                count++;
            }
#ifdef __tmain
            assert(right == y);
            assert(up == x);
            system("PAUSE");
#endif // __tmain
            y--;        //  最后一次的时候, y == right了, 超出了范围需要回退
            up++;       //  向右走以后, 那么当前最顶行up == x已经遍历过了，不可能再遍历了, 因此up++



            //  turn down x++
            for(x++; x < down && count < max_count; x++)
            {
                res.push_back(matrix[x][y]);
                debug <<"right-[" <<x <<", " <<y <<"] = " <<matrix[x][y] <<", count = " <<count <<endl;
                count++;
            }
#ifdef __tmain
            assert(down  == x);
            assert(right - 1 == y);
            system("PAUSE");
#endif // __tmain
            x--;            //  最后一次的时候, x == down, 超出了范围需要回退
            right--;        //  向右走以后, 那么当前最右列right - 1 == y已经遍历过了，不可能再遍历了, 因此right--



            //  turn left y--
            for(y--; y >= left && count < max_count; y--)
            {
                res.push_back(matrix[x][y]);
                debug <<"right-[" <<x <<", " <<y <<"] = " <<matrix[x][y] <<", count = " <<count <<endl;
                count++;
            }
#ifdef __tmain
            assert(down - 1 == x);
            assert(left - 1 == y);
            system("PAUSE");
#endif // __tmain
            y++;            //  最后一次的时候, y == left - 1, 超出了范围需要回退
            down--;         //  向左走以后, 那么当前最下行(down - 1) == x已经遍历过了，不可能再遍历了, 因此down--

            //  turn uo x--
            for(x--; x >= up && count < max_count; x--)
            {
                res.push_back(matrix[x][y]);
                debug <<"right-[" <<x <<", " <<y <<"] = " <<matrix[x][y] <<", count = " <<count <<endl;
                count++;
            }
#ifdef __tmain
            assert(up - 1 == x);
            assert(left == y);
            system("PAUSE");
#endif // __tmain
            x++;            //  最后一次的时候, x == up - 1, 超出了范围需要回退
            left++;         //  向左走以后, 那么当前最左列left == y已经遍历过了，不可能再遍历了, 因此left--

#ifdef __tmain
            system("PAUSE");
#endif // __tmain
        }

        return res;
    }
};


int __tmain( )
{
    int a1[] = {  1,  2,  3,  4 };
    int a2[] = {  5,  6,  7,  8 };
    int a3[] = {  9, 10, 11, 12 };
    int a4[] = { 13, 14, 15, 16 };
//    int a1[] = { 1 };
//    int a2[] = { 2 };
//    int a3[] = { 3 };
//    int a4[] = { 4 };

    vector<int> vec1(a1, a1 + 4);
    vector<int> vec2(a2, a2 + 4);
    vector<int> vec3(a3, a3 + 4);
    vector<int> vec4(a4, a4 + 4);


    vector< vector<int> > vec;
    vec.push_back(vec1);
    vec.push_back(vec2);
    vec.push_back(vec3);
    vec.push_back(vec4);

    Solution solu;
    vector<int> res = solu.printMatrix(vec);
    for(int i = 0; i < res.size( ); i++)
    {
        cout <<res[i] <<" ";
    }
    return 0;
}
```