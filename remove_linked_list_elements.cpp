#include <cstdio>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)
            return NULL;
        ListNode *ptr=head, *pre=NULL;
        while(ptr){
            if(ptr->val==val){
                ListNode *tmp=ptr;
                if(!pre){
                    head=ptr->next;
                }else{
                    pre->next=ptr->next;
                }
                ptr=ptr->next;
                delete tmp;
            }else{
                pre=ptr;
                ptr=ptr->next;
            }
        }
        return head;
    }
};
