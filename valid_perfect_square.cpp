class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num<1)
            return false;
        long long r=num;
        while(r*r>num){
            r=(r+num/r)/2;
        }
        return r*r==num;
    }
};

/*
class Solution {
public:
    bool isPerfectSquare(int num) {
        for(long long i=0;i<=num;i++){
            if(i*i>num){
                return false;
            }else if(i*i==num){
                return true;
            }
        }
        return false;
    }
};
 */
