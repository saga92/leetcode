#include<vector>
#include <cstdio>
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vals;
        stack<TreeNode*> sta;
        TreeNode* pCurrent=root;
        while(!sta.empty() || pCurrent){
            if(pCurrent){
                sta.push(pCurrent);
                pCurrent=pCurrent->left;
            }else{
                TreeNode* tn=sta.top();
                vals.push_back(tn->val);
                sta.pop();
                pCurrent=tn->right;
            }
        }
        return vals;
    }
};

/*
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vals;
        inorderTraversalRecursive(root,vals);
        return vals;
    }

    void inorderTraversalRecursive(TreeNode* root, vector<int>& vals){
        if(root){
            inorderTraversalRecursive(root->left, vals);
            vals.push_back(root->val);
            inorderTraversalRecursive(root->right,vals);
        }
    }
};
 */
