#include<cstdio>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        if(!node->next){
            delete node;
            node=NULL;
        }
        ListNode *ptr=node;
        ListNode *pre=NULL;
        while(ptr->next){
            ListNode *next=ptr->next;
            ptr->val=next->val;
            pre=ptr;
            ptr=ptr->next;
        }
        delete ptr;
        ptr=NULL;
        pre->next=NULL;
    }
};
