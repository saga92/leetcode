#include<vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        sort(nums.begin(), nums.end());
        int j(-1),k(-1),count(0),len(0);
        for(int i=0;i<nums.size();i++){
            if(nums[i]==val){
                count++;
                if(j==-1) j=i;
                k=i;
            }
            if(i>k) nums[j++]=nums[i];
        }
        len=nums.size()-count;
        nums.resize(len);
        return len;
    }
};

int main(){
    vector<int> vec={3,2,2,3};
    Solution solution;
    int res=solution.removeElement(vec, 3);
    return 0;
}