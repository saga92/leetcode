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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> vals;
        TreeNode* pCurrent=root;
        TreeNode* lastNode=NULL;
        stack<TreeNode*> sta;
        while(pCurrent||!sta.empty()){
            if(pCurrent){
                sta.push(pCurrent);
                pCurrent=pCurrent->left;
            }else{
                TreeNode* topNode=sta.top();
                if(topNode->right&&lastNode!=topNode->right){
                    pCurrent=topNode->right;
                }else{
                    vals.push_back(topNode->val);
                    lastNode=topNode;
                    sta.pop();
                }
            }
        }
        return vals;
    }
};
