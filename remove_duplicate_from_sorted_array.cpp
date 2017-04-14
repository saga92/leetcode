#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pre_pos(0), len(nums.size());
        if(len<2) return len;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]){
                if(pre_pos<(i-1)){
                    nums[pre_pos+1]=nums[i];
                }
                pre_pos++;
            }else len--;
        }
        nums.resize(len);
        return len;
    }
};

int main(){
    vector<int> vec={1,1,2,2,3,3,3};
    Solution solution;
    int res=solution.removeDuplicates(vec);
    return 0;
}
