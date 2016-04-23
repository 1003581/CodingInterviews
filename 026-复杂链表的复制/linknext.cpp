#include <iostream>

using namespace std;

//  ���Կ���
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain

struct RandomListNode
{
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x)
    :label(x), next(NULL), random(NULL)
    {
    }
};


class Solution
{
public:

    ///  ���Ʋ���
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == NULL)
        {
            return NULL;
        }

        RandomListNode *currNode = pHead;
        RandomListNode *newHead = NULL, *preNode = NULL, *newNode = NULL;

        ///  ���ȸ���ԭ�������ָͨ����, һ�α����������
        ///  ���µĽڵ�������ԭ���ڵ��ĩβ
        while(currNode != NULL)
        {
            newNode = new RandomListNode(currNode->label);

            /// ���µĽڵ�newNode������currNode�ĺ���
            newNode->next = currNode->next;
            currNode->next = newNode;

            ///  ָ��ָ����һ���ڵ�
            currNode = newNode->next;
        }

        ///  ���Ÿ������ָ����
        ///  ԭ���ڵ����һ��λ�þ������Ӧ���½ڵ�
        currNode = pHead;
        newNode = NULL;
        while(currNode != NULL)
        {
            RandomListNode *randNode = currNode->random;                        ///  ���ָ����randNode
            RandomListNode *newNode = currNode->next;
            newNode->random = randNode->next;

            ///  ����ͬ���ƶ�
            currNode = newNode->next;
        }

        /// ��������һ����¾����������ֿ�
        currNode = pHead;
        newNode = pHead->next;
        while(currNode != NULL)
        {
            /// currNode  newNode newNode->next
            newNode = currNode->next;
            currNode->next = newNode->next;
        }
        return newHead;
    }

};






int __tmain( )
{
    debug <<"test" <<endl;
    return 0;
}
