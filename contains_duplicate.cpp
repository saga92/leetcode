#include<unordered_set>
#include<vector>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size()<2)
            return false;
        unordered_set<int> s;
        for(int n:nums){
            if(s.find(n)!=s.end()){
                return true;
            }
            s.insert(n);
        }
        return false;
    }
};
