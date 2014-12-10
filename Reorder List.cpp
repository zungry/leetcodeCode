class Solution {
public:
    void reorderList(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;


        if(head != NULL && head->next != NULL){
            while(fast != NULL && fast->next !=NULL){
                slow = slow->next;
                fast = fast->next->next;
            }

            ListNode *tmp = slow->next;
            slow->next = NULL;

            ListNode *p1 = head;
            ListNode *p2 = NULL;
            while(tmp != NULL){
                ListNode *next = p2;
                p2 = tmp;
                tmp = tmp->next;
                p2->next = next;
            }

            tmp = NULL;

            while(p2 != NULL && p1 != NULL){
                tmp = p1->next;
                p1->next = p2;
                p2 = p2->next;
                p1->next->next = tmp;
                p1 = tmp;
                tmp = p1->next;
            }
        }
    }
};