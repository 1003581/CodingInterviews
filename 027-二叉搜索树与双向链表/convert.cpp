#include <iostream>

using namespace std;

//
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain

#ifdef __tmain

struct TreeNode
{
	int val; struct TreeNode *left; struct TreeNode *right; TreeNode(int x)
	:val(x), left(NULL), right(NULL)
	{
	}
};

#endif  //  __tmain

class Solution
{
public:
    /**
     * [Convert description]
     * @AuthorHTL
     * @DateTime  2016-04-23T21:02:08+0800
     * @param     pRootOfTree              [description]
     * @return                             [description]
     */
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == NULL)
        {
            return NULL;
        }
        TreeNode *pLastNode = NULL;
        pRootOfTree = ConvertNode(pRootOfTree, &pLastNode);

        // ���ݹ������,*pLastNodeָ����˫�������β���
        TreeNode *node = *pLastNode;
        while(pLastNode != NULL
           && pLastNode->left != NULL)
        {
           pLastNode = pLastNode->left;
        }

        return pLastNode;
    }

    TreeNode* ConvertRecursion(TreeNode *root, TreeNode **pLastNode)
    {
        if(root == NULL)
        {
            return NULL;
        }
        TreeNode *currNode = root;

        //////////////////////////
        /// �������� �ݹ�������
        //////////////////////////
        if(currNode->left != NULL)
        {
            ConvertRecursion(root->left, pLastNode);
        }


        //////////////////////////
        /// ��������ʼ���ʸ��ڵ�
        /// ��������ʵĹ����ݱ�Ϊ���������ĸ�����ڵ����ӳ�һ������
        //////////////////////////

        ///  ��ʼ�����������͵�ǰ���ڵ�
        //  *pLastNode -=> currNode
        currNode->left = *pLastNode; //
        if(*pLastNode != NULL)
        {
            (*pLastNode)->right = currNode;
        }

        //  ������һ�����ʵ�ָ����
        //  ����Ҫ����ǰһ��ָ���ָ����
        //  �����Ҫʹ����ָ�����޸���ָ��
        *pLastNode = currNode;

        //  �������
        if(currNode->right != NULL)
        {
            ConvertRecursion(currNode->right, pLastNode);
        }
    }
};



int __tmain( )
{
    debug <<"test" <<endl;
    return 0;
}
