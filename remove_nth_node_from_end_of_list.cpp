#include <cstdio>
#include <stack>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode** t1 = &head, *t2 = head;
        for(int i = 1; i < n; ++i)
        {
            t2 = t2->next;
        }
        while(t2->next != NULL)
        {
            t1 = &((*t1)->next);
            t2 = t2->next;
        }
        *t1 = (*t1)->next;
        return head;
    }
};

/*
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        stack<ListNode*> sta;
        ListNode* pCurrent=head;
        while(pCurrent){
            sta.push(pCurrent);
            pCurrent=pCurrent->next;
        }
        for(int i=0;i<n;i++){
            sta.pop();
        }
        if(sta.empty()){
            return head->next;
        }
        ListNode* topNode=sta.top();
        if(!topNode->next)
            return head;
        topNode->next=topNode->next->next;
        return head;
    }
};
