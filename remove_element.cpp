#include<vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val){
        int begin=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val) nums[begin++]=nums[i];
        }
        nums.resize(begin);
        return begin;
    }
};

int main(){
    vector<int> vec={3,2,2,3};
    Solution solution;
    int res=solution.removeElement(vec, 3);
    return 0;
}