/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<cstdio>
#include <cstdlib>

struct ListNode {
    int val;
    ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
private:
    ListNode* head;
public:
    Solution(ListNode* head) {
        this->head=head;
    }

    int getRandom() {
        int res=head->val;
        ListNode* nextNode=head->next;
        int i=2,j=0;
        while(nextNode){
            j=rand()%i;
            if(j==0)
                res=nextNode->val;
            i++;
            nextNode=nextNode->next;
        }
        return res;
    }
};

