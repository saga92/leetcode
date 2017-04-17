#include<vector>
#include<cstdio>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        vector<TreeNode*> treeNodes;
        vector<TreeNode*> newTreeNodes;
        vector<int> vec;
        treeNodes.push_back(root);
        while(!treeNodes.empty()){
            for(TreeNode* treeNode:treeNodes){
                vec.push_back(treeNode->val);
                if(treeNode->left) newTreeNodes.push_back(treeNode->left);
                if(treeNode->right) newTreeNodes.push_back(treeNode->right);
            }
            treeNodes.clear();
            treeNodes.insert(treeNodes.end(), newTreeNodes.begin(), newTreeNodes.end());
            newTreeNodes.clear();
            res.insert(res.begin(), vec);
            vec.clear();
        }
        return res;
    }
};

int main(){
    return 0;
}