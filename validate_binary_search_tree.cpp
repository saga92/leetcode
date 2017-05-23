#include <cstdio>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev=NULL;
        return validate(root,prev);
    }

    bool validate(TreeNode* node,TreeNode* &prev){
        if(!node) return true;
        if(!validate(node->left,prev)) return false;
        if(prev!=NULL&&prev->val>=node->val) return false;
        prev=node;
        return validate(node->right,prev);
    }
};

int main(){
    TreeNode* root=new TreeNode(2);
    root->left=new TreeNode(1);
    root->right=new TreeNode(3);
    Solution solution;
    bool res=solution.isValidBST(root);
    return 0;
}
