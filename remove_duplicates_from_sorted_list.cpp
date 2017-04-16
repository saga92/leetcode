struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode* pre_ptr=head;
        ListNode* ptr=head->next;
        ListNode* next_ptr=NULL;
        while(ptr!=NULL){
            next_ptr=ptr->next;
            if(pre_ptr->val==ptr->val){
                pre_ptr->next=next_ptr;
                free(ptr);
                ptr=next_ptr;
            }else{
                ptr=next_ptr;
                pre_ptr=pre_ptr->next;
            }
        }
        return head;
    }
};