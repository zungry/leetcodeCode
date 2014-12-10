class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL)
            return NULL;
            
        RandomListNode *head_ = new RandomListNode(INT_MAX);
        head_->next = head;
        
        while(head){
            int label =head->label;
            RandomListNode *head1 = new RandomListNode(label);
            RandomListNode *temp = head->next;
            head->next = head1;
            head1->next = temp;
            head = temp;
        }
        
        RandomListNode *tmp = head_;
        head = head_->next;
        while(head){
            if(head->random){
                head->next->random = head->random->next;
            }
            head = head->next->next;
        }
        
        head_ = tmp;
        head = head_->next;
        while(head){
            head_->next = head->next;
            head->next = head->next->next;
            head = head->next;
            head_ = head_->next;
        }
        return tmp->next;
    }
};