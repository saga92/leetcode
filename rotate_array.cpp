#include<vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.empty()||(k%=nums.size())==0) return;
        reverse(nums.begin(), nums.begin()+nums.size()-k);
        reverse(nums.begin()+nums.size()-k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};

int main(){
    vector<int> vec={1,2,3,4,5,6,7};
    Solution solution;
    solution.rotate(vec,3);
    return 0;
}
