#include<vector>
#include<unordered_map>
#include <queue>

using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(int n:nums){
            map[n]++;
        }
        vector<int> res;
        priority_queue<pair<int,int>> pq;
        for(auto it=map.begin();it!=map.end();it++){
            pq.push({it->second,it->first});
            if(pq.size()>map.size()-k){
                res.push_back(pq.top().second);
                pq.pop();
            }
        }
        return res;
    }
};

int main(){
    vector<int> vec={2,1,1};
    Solution solution;
    solution.topKFrequent(vec,1);
    return 1;
}
