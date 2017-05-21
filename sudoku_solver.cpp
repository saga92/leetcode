#include<vector>
using namespace std;
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solveRecursive(board, 0);
    }

    bool solveRecursive(vector<vector<char>>& board, int pos){
        if(pos==81)
            return true;
        int row=pos/9, col=pos%9;
        if(board[row][col]=='.'){
            for(int i=1;i<=9;i++){
                board[row][col]=i+'0';
                if(isValid(board,pos)){
                    if(solveRecursive(board, pos+1)){
                        return true;
                    }
                }
                board[row][col]='.';
            }
        }else{// board[row][col]!='.'
            if(solveRecursive(board, pos+1)){
                return true;
            }
        }
        return false;
    }

    bool isValid(vector<vector<char>>& board, int pos){
        int i=pos/9,j=pos%9;
        for(int k=0;k<board.size();k++){
            if(k!=j&&board[i][k]==board[i][j])
                return false;
        }
        for(int k=0;k<board.size();k++){
            if(k!=i&&board[k][j]==board[i][j])
                return false;
        }
        int m1=0,m2=2,n1=0,n2=2;
        while(i<m1||i>m2){
            m1+=3;
            m2+=3;
        }
        while(j<n1||j>n2){
            n1+=3;
            n2+=3;
        }
        for(int m=m1;m<=m2;m++){
            for(int n=n1;n<=n2;n++){
                if((m!=i || n!=j)&&board[i][j]==board[m][n])
                    return false;
            }
        }
        return true;
    }
};
