// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        if(n==1)
            return n;
        int i=1,j=n;
        while(i<j){
            int mid=i+(j-i)/2;
            if(guess(mid)==-1){
                j=mid-1;
            }else if(guess(mid)==1){
                i=mid+1;
            }else{
                return mid;
            }
        }
        return i;
    }
};
