#include <iostream>

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
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL)
    {
	}
};
#endif // __tmain


class Solution {
public:
    void MirrorPre(TreeNode *pRoot)
    {
        if(pRoot == NULL)
        {
            return;
        }
        stack<TreeNode *> nstack;
        nstack.push(pRoot);

        TreeNode *node = NULL;
        while(nStack.empty() != true)
        {
            node = nstack.top( );
            nstack.pop( );

            //  �Ƚ���, Ȼ��ݹ��󣬽��ŵݹ���
            //  �൱��һ��ǰ�����
            if(tree->left != NULL || tree->rigth != NULL)
            {
                swap(node->left, node->right);
            }

            if(tree->left != NULL)
            {
                nstack.push(node->left);
            }
            if(tree->rigth != NULL)
            {
                nstack.push(node->right);
            }
        }
    }

    void MirrorIn(TreeNode *pRoot)
    {
        if(pRoot == NULL)
        {
            return;
        }
        stack<TreeNode *> nstack;
        nstack.push(pRoot);

        TreeNode *node = NULL;
        while(nStack.empty() != true)
        {
            node = nstack.top( );
            nstack.pop( );

            //  �Ƚ���, Ȼ��ݹ��󣬽��ŵݹ���
            //  �൱��һ��ǰ�����
            if(tree->left != NULL || tree->rigth != NULL)
            {
                swap(node->left, node->right);
            }

            if(tree->left != NULL)
            {
                nstack.push(node->left);
            }
            if(tree->rigth != NULL)
            {
                nstack.push(node->right);
            }
        }
    }
};


int __tmain( )
{
    debug <<"test" <<endl;
    return 0;
}
