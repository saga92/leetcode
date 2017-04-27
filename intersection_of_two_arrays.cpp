#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1,s2;
        vector<int> res;
        s1.insert(nums1.begin(), nums1.end());
        s2.insert(nums2.begin(), nums2.end());
        for(int x:s2){
            if(s1.find(x)!=s1.end()){
                res.insert(res.end(), x);
            }
        }
        return res;
    }
};
