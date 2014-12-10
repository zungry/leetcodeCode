class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode *p = new ListNode(INT_MIN);
        p->next = head;
        head = p;
        
        ListNode *pre;
        
        while(p && p->val < x){
            pre = p;
            p = p->next;
        }
        
        
        if(p){
            ListNode *cur = p;
            ListNode *precur = p;
            while(cur){
                if(cur->val < x){
                    //ListNode *post = cur->next;
                    precur->next = cur->next;
                    cur->next = pre->next;
                    pre->next = cur;
                    pre = pre->next;
                    //pre = pre->next;
                    cur = precur->next;
                }else{
                    precur = cur;
                    cur = cur->next;
                }
            }
        }
        ListNode *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
};