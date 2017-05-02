#include<string>
#include<unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> map;
        for(char cs:s)
            map[cs]++;
        priority_queue<pair<int, char>> pq;
        for(auto it=map.begin();it!=map.end();it++){
            pq.push(make_pair(it->second,it->first));
        }
        string res;
        while(!pq.empty()){
            for(int i=0;i<pq.top().first;i++)
                res+=pq.top().second;
            pq.pop();
        }
        return res;
    }
};
