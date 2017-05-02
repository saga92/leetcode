#include<string>
#include<sstream>
#include<unordered_map>
#include <iostream>

using namespace std;
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<string, int> ms;
        unordered_map<char, int> mp;
        int i=0, n=pattern.length();
        istringstream is(str);
        for(string s;is>>s;i++){
            if(i==n||mp[pattern[i]]!=ms[s]){
                return false;
            }
            mp[pattern[i]]=ms[s]=i+1; // map init element with 0.
        }
        return i==n;
    }
};

int main(){
    Solution solution;
    bool res=solution.wordPattern("abba","dog cat cat fish");
    return 0;
}
