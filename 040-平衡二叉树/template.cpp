#include <iostream>

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
public:
    bool IsBalanced_Solution(TreeNode* pRoot)
    {

    }

    int TreeDepth(TreeNode *root)
    {
        if(root == NULL)
        {
            return 0;
        }

        int leftDepth = TreeDepth(root->left);
        int rightDepth = TreeDepth(root->right);

        return max(leftDepth, rightDepth);
    }
};

int __tmain( )
{
    debug <<"test" <<endl;
    return 0;
}
