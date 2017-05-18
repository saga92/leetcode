#include<vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<bool> used(nums.size(), false);
        vector<int> temp;
        sort(nums.begin(), nums.end());
        permuteDFS(res, nums, temp, used);
        return res;
    }

    void permuteDFS(vector<vector<int>>& res, vector<int> &nums, vector<int> &temp, vector<bool> &used){
        if(temp.size()==nums.size()){
            vector<int> nnums(temp);
            res.push_back(nnums);
        }else{
            for(int i=0;i<nums.size();i++){
                if(used[i])
                    continue;
                used[i]=true;
                temp.push_back(nums[i]);
                permuteDFS(res,nums,temp,used);
                temp.pop_back();
                used[i]=false;
                while(i<nums.size()-1 && nums[i]==nums[i+1]){
                    i++;
                }
            }
        }
    }
};
