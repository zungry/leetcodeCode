class Solution {
public:
    string addBinary(string a, string b) {
        int alen = a.length();
        int blen = b.length();
        
        if(alen == 0)
            return b;
        if(blen == 0)
            return a;
            
        vector<char> tmp;
        int i = alen - 1;
        int j = blen - 1;
        int carry = 0;
        while(i >= 0 && j>= 0){
            int digit = a[i]-'0'+b[j]-'0'+carry;
            carry = digit / 2;
            digit %= 2;
            tmp.push_back(digit+'0');
            i--;
            j--;
        }
        while(i >= 0){
            int digit = a[i]-'0'+carry;
            carry = digit/2;
            digit %= 2;
            tmp.push_back(digit+'0');
            i--;
        }
        
        while(j >= 0){
            int digit = b[j]-'0'+carry;
            carry = digit/2;
            digit %= 2;
            tmp.push_back(digit+'0');
            j--;
        }
        
        if(carry == 1)
            tmp.push_back(carry+'0');
        string ret;
        for(int i = tmp.size()-1;i >=0;i--){
            ret.push_back(tmp[i]);
        }
        return ret;
    }
};