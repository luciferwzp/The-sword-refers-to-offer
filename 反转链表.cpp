//输入一个链表，反转链表后，输出链表的所有元素。

//思路
//这个很简单，我们使用三个指针，分别指向当前遍历到的结点、它的前一个结点以及后一个结点。
//在遍历的时候，做当前结点的尾结点和前一个结点的替换。

/*
 * struct ListNode {
 *     int val;
 *         struct ListNode *next;
 *             ListNode(int x) :
 *                         val(x), next(NULL) {
 *                             }
 *                             };*/
class Solution {
    public:
        ListNode* ReverseList(ListNode* pHead) {
            ListNode* pReversedHead = NULL;
            ListNode* pNode = pHead;
            ListNode* pPrev = NULL;
            while(pNode != NULL){
                ListNode* pNext = pNode->next;
                if(pNext == NULL){
                    pReversedHead = pNode;
                }
                pNode->next = pPrev;
                pPrev = pNode;
                pNode = pNext;
            }
            return pReversedHead;
        }
};
