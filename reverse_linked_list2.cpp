#include <cstdio>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int i=0;
        ListNode*mnode=NULL,*nnode=NULL,*prem=NULL,*lastn=NULL,*pre=NULL,*ptr=head;
        while(ptr!=NULL){
            if(++i == m)
                mnode=ptr;
            if(i==(m-1))
                prem=ptr;
            if(i==(n+1)){
                lastn=ptr;break;
            }
            if(i==n)
                nnode=ptr;
            ptr=ptr->next;
        }
        ptr=mnode;
        while(ptr!=lastn){
            ListNode *next=ptr->next;
            ptr->next=pre;
            pre=ptr;
            ptr=next;
        }
        mnode->next=lastn;
        if(prem==NULL)
            return pre;
        prem->next=nnode;
        return head;
    }
};

int main(){
    ListNode *head=new ListNode(1);
    ListNode *next=new ListNode(2);
    head->next=next;
    Solution solution;
    head=solution.reverseBetween(head, 1, 2);
    return 0;
}
