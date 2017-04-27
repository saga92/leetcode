#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>m1;
        unordered_map<int,int>::iterator it;
        vector<int> res;
        for(int n1:nums1){
            if((it=m1.find(n1))!=m1.end()){
                it->second++;
            }else{
                m1.insert({n1,1});
            }
        }
        for(int n2:nums2){
            if((it=m1.find(n2))!=m1.end()){
                res.insert(res.end(), n2);
                it->second--;
                if(!it->second){
                    m1.erase(n2);
                }
            }
        }
        return res;
    }
};
