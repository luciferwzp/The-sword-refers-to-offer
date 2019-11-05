//思路
//两个链表的第一个公共结点

//这道题有两个解法。
//方法一：
//我们可以把两个链表拼接起来，一个pHead1在前pHead2在后，一个pHead2在前pHead1在后。
//这样，生成了两个相同长度的链表，那么我们只要同时遍历这两个表，就一定能找到公共结点。时间复杂度O(m+n)，空间复杂度O(m+n)。

//方法二：
//我们也可以先让把长的链表的头砍掉，让两个链表长度相同，这样，同时遍历也能找到公共结点。
//此时，时间复杂度O(m+n)，空间复杂度为O(MAX(m,n))。
//这里使用方法二。


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
        ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2 ) {
            // 如果有一个链表为空，则返回结果为空
            if(pHead1 == NULL || pHead2 == NULL){
                return NULL;
            }
            // 获得两个链表的长度
            unsigned int len1 = GetListLength(pHead1);
            unsigned int len2 = GetListLength(pHead2);
            // 默认 pHead1 长， pHead2短，如果不是，再更改
            ListNode* pHeadLong = pHead1;
            ListNode* pHeadShort = pHead2;
            int LengthDif = len1 - len2;
            // 如果 pHead1 比 pHead2 小
            if(len1 < len2){
                ListNode* pHeadLong = pHead2;
                ListNode* pHeadShort = pHead1;
                int LengthDif = len2 - len1;
            }
            // 将长链表的前面部分去掉，使两个链表等长

            for(int i = 0; i < LengthDif; i++){
                pHeadLong = pHeadLong->next;
            }

            while(pHeadLong != NULL && pHeadShort != NULL && pHeadLong != pHeadShort){
                pHeadLong = pHeadLong->next;
                pHeadShort = pHeadShort->next;
            }
            return pHeadLong;
        }
    private:
        // 获得链表长度
        unsigned int GetListLength(ListNode* pHead){
            if(pHead == NULL){
                return 0;
            }
            unsigned int length = 1;
            while(pHead->next != NULL){
                pHead = pHead->next;
                length++;
            }
            return length;
        }
};
