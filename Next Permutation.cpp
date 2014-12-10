class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int end = num.size() - 1;
        int povit = end;
        
        while (povit > 0) {
            if (num[povit] > num[povit - 1]) {
                break;
            }
            povit--;
        }
        
        if (povit > 0) {
            povit--;
            int large = end;
            
            while (num[large] <= num[povit]) {
                large--;
            }
            swap(num[large], num[povit]);
            reverse(num.begin()+povit+1, num.end());
        }else{
            reverse(num.begin(), num.end());
        }
    }
};