#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    int totalNQueens(int n) {
        vector<vector<string>> res;
        vector<string> strVec(n,string(n,'.'));
        solveRecursive(res,strVec,0,n);
        return res.size();
    }

    void solveRecursive(vector<vector<string>> &res,vector<string> &strVec,int row,int n){
        if(row==n){
            res.push_back(strVec);
        }else{
            for(int col=0;col<n;col++){
                if(isValid(strVec,row,col,n)){
                    strVec[row][col]='Q';
                    solveRecursive(res,strVec,row+1,n);
                    strVec[row][col]='.';
                }
            }
        }
    }

    bool isValid(vector<string> strVec, int row, int col, int n){
        for(int i=0;i<row;i++){
            if(strVec[i][col]=='Q')
                return false;
        }

        for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
            if(strVec[i][j]=='Q')
                return false;
        }

        for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++){
            if(strVec[i][j]=='Q')
                return false;
        }
        return true;
    }
};

