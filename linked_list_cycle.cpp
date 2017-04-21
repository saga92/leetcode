#include <cstdio>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        ListNode *walker=head;
        ListNode *runner=head;
        while(runner->next&&runner->next->next){
            walker=walker->next;
            runner=runner->next->next;
            if(walker->val==runner->val) return true;
        }
        return false;
    }
};