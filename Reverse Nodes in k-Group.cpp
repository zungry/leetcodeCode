class Solution {
public:
    Node reverseK(ListNode *first,ListNode *end){
        ListNode *pPre = NULL;
        ListNode *p = first;
        
        while (p != end) {
            ListNode *pNext = p->next;
            p->next = pPre;
            pPre = p;
            p = pNext;
        }
        
        p->next = pPre;
        
        return Node(end ,first);
        
    }
    
    ListNode *reverseKGroup(ListNode *head, int k) {
        //链表长度
        if(head == NULL || k == 1) return head;
        int len = 0;
        ListNode *pPre = NULL;
        ListNode *p =   head;
        
        while (p) {
            ListNode *q = p;
            for (int i = 0 ; i < k - 1; i++) {
                q = q->next;
                if (q == NULL) {
                    return head;
                }
            }
            
            ListNode *qNext =q->next;
            
            Node ret = reverseK(p, q);
            
            if (pPre == NULL) {
                head = ret.beg;
            }else{
                pPre->next = ret.beg;
            }
            
            ret.end->next = qNext;
            pPre = ret.end;
            p = qNext;
            
        }
        return head;
    }
};