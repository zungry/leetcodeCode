class Solution {
public:
    int reverse(int x) {
        bool isPositive = true;
        if(x < 0){isPositive = false; x *= -1;}
        long long res = 0;//为了防止溢出，用long long
        while(x >0)
        {
            res = res*10 + x%10;
            x = x / 10;
        }
        if(res > INT_MAX){
            return 0;
        }
        if(!isPositive)return res*-1;
        else return (int)res;
    }
};