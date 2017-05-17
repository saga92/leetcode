#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        permuteRecursive(res,0,nums);
        return res;
    }

    void permuteRecursive(vector<vector<int>>& res, int begin, vector<int>& nums){
        if(begin>=nums.size()){
            res.push_back(nums);
        }else{
            for(int i=begin;i<nums.size();i++){
                swap(nums[begin], nums[i]);
                permuteRecursive(res, begin+1,nums);
                swap(nums[begin], nums[i]);
            }
        }
    }
};
