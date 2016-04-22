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
struct RandomListNode
{
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x)
    :label(x), next(NULL), random(NULL)
    {
    }
};
#endif  //__tmain


class Solution
{
public:
    /// ���ҵ�oldheadָ���ԭ�����������ָ��randNode���µ�����newHead�еĶ�Ӧ���
    RandomListNode* FindInNew(RandomListNode *oldHead, RandomListNode *newHead, RandomListNode *randNode)
    {
        RandomListNode *currNode = oldHead;
        RandomListNode *newNode = newHead;

        while(currNode != NULL && newNode != NULL)
        {
            if(randNode == currNode)
            {
                return newNode;
            }

            /// ��������
            currNode = currNode->next;
            newNode = newNode->next;
        }

        return NULL;
    }
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == NULL)
        {
            return NULL;
        }

        RandomListNode *currNode = pHead;
        RandomListNode *newHead = NULL, *preNode = NULL, *newNode = NULL;

        ///  ���ȸ���ԭ����ָ����
        while(currNode != NULL)
        {
            newNode = new RandomListNode(currNode->label);
            currNode = currNode->next;

            if(preNode == NULL)
            {
                newHead = newNode;
            }
            else
            {
                preNode->next = newNode;
            }

            preNode = newNode;
        }

        //  ���Ÿ������ָ����
        currNode = pHead;
        newNode = newHead;
        while(currNode != NULL && newNode != NULL)
        {
            RandomListNode *randNode = currNode->random;
            RandomListNode *newRandNode = FindInNew(pHead, newHead, randNode);
            newNode->random = newRandNode;

            currNode = currNode->next;
            newNode = newNode->next;
        }

        return newHead;
    }

};


int __tmain( )
{

    return 0;
}
