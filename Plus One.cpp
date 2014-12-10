class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> ret;
        int dlength = digits.size();
        int carry = 0;
        for(int i = dlength - 1; i >= 0 ;i--){
            int temp;
            if(i == dlength - 1)
                temp = digits[i] + carry + 1;
            else{
                temp = digits[i] + carry;
            }
            int num = temp % 10;
            ret.push_back(num);
            
            carry = 0;
            if(temp >= 10){
                carry = temp / 10;
            }
        }
        if(carry > 0)
            ret.push_back(carry);
            
        reverse(ret.begin(),ret.end());
        return ret;
    }
};