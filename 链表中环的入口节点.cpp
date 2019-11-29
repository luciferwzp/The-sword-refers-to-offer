//思路
//可以用两个指针来解决这个问题。先定义两个指针P1和P2指向链表的头结点。
//如果链表中的环有n个结点，指针P1先在链表上向前移动n步，然后两个指针以相同的速度向前移动。
//当第二个指针指向的入口结点时，第一个指针已经围绕着揍了一圈又回到了入口结点。


/*
 * struct ListNode {
 *     int val;
 *         struct ListNode *next;
 *             ListNode(int x) :
 *                     val(x), next(NULL) {
 *                         }
 *                         };
 *                         */
class Solution {
    public:
        ListNode* EntryNodeOfLoop(ListNode* pHead)
        {
            if(pHead == NULL){
                return NULL;
            }
            ListNode* meetingnode = MeetingNode(pHead);
            if(meetingnode == NULL){
                return NULL;
            }
            // 回环链表结点个数
            int nodesloop = 1;
            // 找到环中结点个数
            ListNode* pNode1 = meetingnode;
            while(pNode1->next != meetingnode){
                pNode1 = pNode1->next;
                nodesloop++;
            }
            pNode1 = pHead;
            // 第一个指针向前移动nodesloop步
            for(int i = 0; i < nodesloop; i++){
                pNode1 = pNode1->next;
            }
            // 两个指针同时移动，找到环入口
            ListNode* pNode2 = pHead;
            while(pNode1 != pNode2){
                pNode1 = pNode1->next;
                pNode2 = pNode2->next;
            }
            return pNode1;
        }
    private:
        // 使用快慢指针，找到任意的一个环中结点
        ListNode* MeetingNode(ListNode* pHead){
            ListNode* pSlow = pHead->next;
            if(pSlow == NULL){
                return NULL;
            }
            ListNode* pFast = pSlow->next;
            while(pFast != NULL && pSlow != NULL){
                if(pFast == pSlow){
                    return pFast;
                }
                pSlow = pSlow->next;
                pFast = pFast->next;
                if(pFast != NULL){
                    pFast = pFast->next;
                }
            }
            return NULL;
        }
};
