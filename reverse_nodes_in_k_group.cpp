struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};

class Solution{
public:
    ListNode* reverseKGroup(ListNode* head, int k){
        if(head==NULL||k==1)
            return head;
        int num=0;
        ListNode *preheader=new ListNode(-1);
        preheader->next=head;
        ListNode *cur=preheader,*next,*pre=preheader;
        while(cur=cur->next)
            num++;
        while(num>=k){
            cur=pre->next;
            next=cur->next;
            for(int i=1;i<k;i++){
                cur->next=next->next;
                next->next=pre->next;
                pre->next=next;
                next=cur->next;
            }
            pre=cur;
            n-=k;
        }
        return preheader->next;
    }
};
