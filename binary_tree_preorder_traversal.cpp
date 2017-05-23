#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vals;
        if(!root)
            return vals;
        stack<TreeNode*> sta;
        sta.push(root);
        while(!sta.empty()){
            TreeNode* tn=sta.top();
            sta.pop();
            vals.push_back(tn->val);
            if(tn->right)
                sta.push(tn->right);
            if(tn->left)
                sta.push(tn->left);
        }
        return vals;
    }
};
