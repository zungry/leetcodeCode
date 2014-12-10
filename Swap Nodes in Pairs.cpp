class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if(head == NULL)
            return NULL;

        ListNode *pPP = NULL;
        ListNode *pP = NULL;
        ListNode *p = head;

        while(p && p->next){
            pP = p;
            p = p->next;

            ListNode *pN = p->next;

            if(pP == head)
                head = p;

            if(pPP)
                pPP->next = p;
            
            p->next = pP;
            pP->next = pN;

            pPP = pP;
            p = pN;
        }
        return head;
    }
};