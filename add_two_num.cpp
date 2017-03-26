struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL, *p=NULL;
        ListNode* p1=l1, *p2=l2;
        int total=0, sup = 0;
        while(p1!=NULL && p2 !=NULL){
            total = p1->val+p2->val+sup;
            sup = total/10;
            if(head == NULL){
                head = new ListNode(total%10);
                p=head;
            }else{
                p->next=new ListNode(total%10);
                p=p->next;
            }
            p1=p1->next;
            p2=p2->next;
        }
        while(p1!=NULL){
            total=p1->val+sup;
            sup=total/10;
            p->next = new ListNode(total%10);
            p=p->next;
            p1=p1->next;
        }
        while(p2!=NULL){
            total=p2->val+sup;
            sup=total/10;
            p->next=new ListNode(total%10);
            p=p->next;
            p2=p2->next;
        }
        if(sup!=0){
            p->next=new ListNode(1);
        }
        return head;
    }
};

int main(){
    Solution solution;
    ListNode* l1=new ListNode(1);
    l1->next=new ListNode(8);
    ListNode* l2=new ListNode(0);
    solution.addTwoNumbers(l1,l2);
}

