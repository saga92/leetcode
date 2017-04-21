#include<vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result=0;
        for(int n:nums){
            result^=n;
        }
        return result;
    }
};

int main(){
    vector<int> vec={1,1,2,3,3,4,4};
    Solution solution;
    int res=solution.singleNumber(vec);
    return 0;
}
