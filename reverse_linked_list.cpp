/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <cstdio>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* res=head;
        if(res==NULL){
            return NULL;
        }
        while(res->next!=NULL){
            res=res->next;
        }
        reverse(head)->next=NULL;
        return res;
    }

    ListNode* reverse(ListNode* head){
        if(head->next != NULL){
            reverse(head->next)->next=head;
        }
        return head;
    }
};

int main(){
    ListNode *head=new ListNode(1);
    ListNode *next=new ListNode(2);
    head->next=next;
    Solution solution;
    head=solution.reverseList(head);
    return 0;
}