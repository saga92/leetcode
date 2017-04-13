#include<string>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        addpar(res, "", n, 0);
        return res;
    }
    void addpar(vector<string>& vec, string s, int n, int m){
        if(n==0&&m==0){
            vec.push_back(s);
            return;
        }
        if(m>0) addpar(vec, s+")", n, m-1);
        if(n>0) addpar(vec, s+"(", n-1, m+1);
    }
};

int main(){
    Solution solution;
    solution.generateParenthesis(3);
    return 0;
}