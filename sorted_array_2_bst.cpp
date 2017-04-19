#include<cstdio>
#include<vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0) return NULL;
        else if(nums.size()==1) return new TreeNode(nums[0]);
        else{
            int middle=nums.size()/2;
            vector<int> ln, rn;
            ln.insert(ln.begin(), nums.begin(), nums.begin()+middle);
            rn.insert(rn.begin(), nums.begin()+middle+1, nums.end());
            TreeNode *leN=sortedArrayToBST(ln);
            TreeNode *riN=sortedArrayToBST(rn);
            TreeNode *node=new TreeNode(nums[middle]);
            node->left=leN;
            node->right=riN;
            return node;
        }
    }
};