#����
------- 

>ţ��OJ��[�ؽ�������](http://www.nowcoder.com/practice/8a19cbe657394eeaac2f6ea9b0f6fcf6?tpId=13&tqId=11157&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking) 
>
>�Ŷ�OJ��http://ac.jobdu.com/problem.php?pid=1385
>
>GitHub���룺 [005-��β��ͷ��ӡ����](https://github.com/gatieme/CodingInterviews/tree/master/005-%E4%BB%8E%E5%B0%BE%E5%88%B0%E5%A4%B4%E6%89%93%E5%8D%B0%E9%93%BE%E8%A1%A8)
>
>CSDN��⣺[��ָOffer--005-��β��ͷ��ӡ����](http://blog.csdn.net/gatieme/article/details/51107632)



| ţ��OJ | �Ŷ�OJ | CSDN��� | GitHub���� |
| ------------- |:-------------:| -----:|
| [�ؽ�������](http://www.nowcoder.com/practice/8a19cbe657394eeaac2f6ea9b0f6fcf6?tpId=13&tqId=11157&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking) | [1385-�ؽ�������](http://ac.jobdu.com/problem.php?pid=1385)   | [��ָOffer--005-��β��ͷ��ӡ����](http://blog.csdn.net/gatieme/article/details/51107632)   | [005-��β��ͷ��ӡ����](https://github.com/gatieme/CodingInterviews/tree/master/005-%E4%BB%8E%E5%B0%BE%E5%88%B0%E5%A4%B4%E6%89%93%E5%8D%B0%E9%93%BE%E8%A1%A8)  |


#����
-------
��Ŀ����


>����ĳ��������ǰ���������������Ľ�������ؽ����ö�������
>
>���������ǰ���������������Ľ���ж������ظ������֡�

����
>ǰ���������{1,2,4,7,3,5,6,8}
>
>�����������{4,7,2,1,5,3,8,6}


���ؽ������������ء�

#����
-------

����⻹�ǱȽϼ򵥵ģ�����֪��
*    ǰ�������˳��Ϊ��������
*    ���������˳��Ϊ�������

�ݹ�˼��
1.    �����ȸ���ǰ��������еĵ�һ��ȷ������Ȼ��������������������ҵ�����λ�ã�����ߵľ��������������ұ߾�����������
2.    ����������������
3.    �ݹ�Ľ���1��2
```cpp
#include <iostream>
#include <vector>

using namespace std;

//  ���Կ���
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain


#ifdef __tmain
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x)
    : val(x), left(NULL), right(NULL)
    {
    }

    //
    static void PreOrder(TreeNode *root)
    {
        if(root == NULL)
        {
            return;
        }
        cout <<root->val;
        PreOrder(root->left);
        PreOrder(root->right);
    }

    static void InOrder(TreeNode *root)
    {
        if(root == NULL)
        {
            return;
        }
        InOrder(root->left);
        cout <<root->val;
        InOrder(root->right);
    }

 };
#endif // __tmain

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    struct TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in)
    {
        //  ǰ������ĳ��ȸ���������ĳ���Ӧ����ͬ
        if(pre.size( ) != in.size( ))
        {
            debug <<"the length of PRE and IN should be smae" <<endl;
            return NULL;
        }

        // ���Ȳ���Ϊ0
        int size = pre.size( );
        if(size == 0)
        {
            debug <<"it's a NULL tree(length = 0)" <<endl;
            return NULL;
        }

        int length = pre.size( );
        debug <<"the length of your tree = " <<length <<endl;
        int value = pre[0];      //  ǰ������ĵ�һ������Ǹ��ڵ�
        TreeNode *root = new TreeNode(value);

        debug <<"the root is" <<root->val <<endl;
        //  ����������в��ҵ�����λ��
        int rootIndex = 0;
        for(rootIndex = 0; rootIndex < length; rootIndex++)
        {
            if(in[rootIndex] == value)
            {
                debug <<"find the root at " <<rootIndex <<" in IN" <<endl;
                break;
            }
        }
        if(rootIndex >= length)
        {
            debug <<"can't find root (value = " <<value <<") in IN" <<endl;
            return NULL;
        }

        ///  ������������������
        ///  ���������, ����ߵľ���������, �ұߵľ���������
        ///  ǰ�������, ���������ȱ���������, Ȼ����������

        ///  ����ȷ�����������ĳ���, ���������in��ȷ��
        int leftLength = rootIndex;
        int rightLength = length - 1 - rootIndex;
        debug <<"left length = " <<leftLength <<", rightLength = " <<rightLength <<endl;
        vector<int> preLeft(leftLength), inLeft(leftLength);
        vector<int> preRight(rightLength), inRight(rightLength);
        for(int i = 0; i < length; i++)
        {
            if(i < rootIndex)
            {
                //  ǰ������ĵ�һ���Ǹ��ڵ�, �������(leftLegnth = rootIndex) - 1���ڵ���������, �����i+1
                preLeft[i] = pre[i + 1];
                //  �������ǰ(leftLength = rootIndex) - 1���ڵ���������, ��rootIndex���ڵ��Ǹ�
                inLeft[i] = in[i];
                debug <<preLeft[i] <<inLeft[i] <<" ";

            }
            else if(i > rootIndex)
            {
                //  ǰ������ĵ�һ���Ǹ��ڵ�, �������(leftLegnth = rootIndex) - 1���ڵ���������, ������������
                preRight[i - rootIndex - 1] = pre[i];
                //  �������ǰ(leftLength = rootIndex) - 1���ڵ���������, ��rootIndex���ڵ��Ǹ�, Ȼ����������
                inRight[i - rootIndex - 1] = in[i];
                debug <<preRight[i - rootIndex - 1] <<inRight[i - rootIndex - 1] <<" ";

            }
        }
        debug <<endl <<"the left tree" <<endl;
        for(int i = 0; i < leftLength; i++)
        {
            debug <<preLeft[i] <<inLeft[i] <<" ";
        }
        debug <<endl;
        debug <<"the right tree" <<endl;
        for(int i = 0; i < rightLength; i++)
        {
            debug <<preRight[i] <<inRight[i] <<" ";
        }
        debug <<endl;


        root->left = reConstructBinaryTree(preLeft, inLeft);
        root->right = reConstructBinaryTree(preRight, inRight);

        return root;
    }





};

int __tmain( )
{
    int pre[] = { 1, 2, 4, 7, 3, 5, 6, 8 };
    int in[] = { 4, 7, 2, 1, 5, 3, 8, 6 };

    vector<int> preOrder(pre, pre + 8);
    vector<int>  inOrder( in,  in + 8);

    Solution solu;
    TreeNode *root = solu.reConstructBinaryTree(preOrder, inOrder);

    cout <<"PreOrder";
    TreeNode::PreOrder(root);
    cout <<endl;

    cout <<"InOrder ";
    TreeNode::InOrder(root);
    cout <<endl;

    return 0;
}

```
