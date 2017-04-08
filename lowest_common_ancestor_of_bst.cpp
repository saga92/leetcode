#include <cstdio>
#include <vector>
using namespace std;
struct TreeNode{
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pvalvec, qvalvec;
        traceTree(root, p, pvalvec);
        traceTree(root, q, qvalvec);
        int n=pvalvec.size()<qvalvec.size()? pvalvec.size():qvalvec.size();
        int i;
        for(i=0;i<n;++i){
            if(pvalvec.at(i)->val!=qvalvec.at(i)->val)
                break;
        }
        return pvalvec.at(i-1);
    }
    vector<TreeNode*> traceTree(TreeNode* root, TreeNode* p, vector<TreeNode*>& valvec){
        TreeNode* node=root;
        while(node){
            valvec.insert(valvec.end(), node);
            if(node->val==p->val){
                break;
            }else if(node->val>p->val){
                node=node->left;
            }else{
                node=node->right;
            }
        }
        return valvec;
    }
};

int main(){
    TreeNode *root=new TreeNode(2);
    TreeNode *left=new TreeNode(1);
    root->left=left;
    Solution solution;
    TreeNode *res=solution.lowestCommonAncestor(root, root, left);
    return 0;
}