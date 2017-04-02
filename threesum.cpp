#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> resVec;
        set<vector<int>> mset;
        set<int> nset;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();++i){
            if(nset.end() != nset.find(nums[i])){
                continue;
            }
            nset.insert(nums[i]);
            int ts=0-nums[i];
            int j=i+1,k=nums.size()-1;
            while(j<k){
                int jud=nums[j]+nums[k]-ts;
                if(jud>0){
                    k--;
                }else if(jud<0){
                    j++;
                }else{
                    vector<int> tmp={nums[i],nums[j],nums[k]};
                    mset.insert(tmp);
                    k--;j++;
                }
            }
        }
        for(set<vector<int>>::iterator iter=mset.begin(); iter!=mset.end();++iter){
            resVec.insert(resVec.end(), *iter);
        }
        return resVec;
    }
};

int main(){
    Solution solution;
    vector<int> nums={-1, 0, 1, 2, -1, -4};
    solution.threeSum(nums);
}
