#include<vector>
#include <cmath>

using namespace std;
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        int len=nums.size();
        for(int i=0;i<len;i++){
            if(nums[abs(nums[i])-1]>0){
                nums[abs(nums[i])-1]*=(-1);
            }else{
                res.push_back(abs(nums[i]));
            }
        }
        return res;
    }
};
