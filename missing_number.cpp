#include<vector>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i=0,result=0;
        for(int n:nums){
            result^=n;
            result^=i;
            i++;
        }
        result^=i;
        return result;
    }
};
