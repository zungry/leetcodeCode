class Solution {
public:
int sqrt(int x){
    unsigned long long begin = 0;
    unsigned long long end = (x+1)/2;
    unsigned long long mid;
    unsigned long long tmp;
    
    while (begin < end) {
        mid = begin + (end - begin)/2;
        tmp = mid*mid;
        if (tmp == x) {
            return mid;
        }
        else if(tmp < x) begin = mid + 1;
        else end = mid - 1;
    }
    tmp = end * end;
    if (tmp > x) {
        return end - 1;
    }
    else return end;
}
};