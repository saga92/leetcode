#include<vector>
#include<unordered_map>
#include <cmath>

using namespace std;
class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int booms=0;
        for(auto p:points){
            unordered_map<double,int> m(points.size());
            for(auto q:points){
                booms+=2*m[hypot(p.first-q.first,p.second-q.second)]++;
            }
        }
        return booms;
    }
};
