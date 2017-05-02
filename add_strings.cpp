class Solution {
public:
    string addStrings(string num1, string num2) {
        string s = "";
        int c = 0, i = num1.size() - 1, j = num2.size() - 1;
        while(i >= 0 || j >= 0 || c != 0){
            c += i >= 0 ? num1[i --] - '0' : 0;
            c += j >= 0 ? num2[j --] - '0' : 0;
            s = char(c % 10 + '0') + s;
            c /= 10;
        }
        return s;
    }
};
