class Solution {
public:
    string convert(string s, int nRows) {
        int b_s=2*nRows-2;
        int len = s.length();
        string str;
        str.resize(len);
        int i=0,j=0;
        //0
        if(nRows == 1){
            return s;
        }
        if (i==0) {
            str[j] = s[i];
            j++,i++;
            int k=0;
            while (k < len) {
                k +=b_s;
                if (k >= len) {
                    break;
                }
                str[j] = s[k];
                j++;
            }
        }
        //0-nRows-2
        for (; i < nRows-1; i++) {
            str[j] = s[i];
            j++;
            
            int k=1;
            int m=i;
            while (m< len ) {
                m+=b_s-2*i;
                if (m>=len) {
                    break;
                }
                str[j]=s[m];
                j++;
                if (m>=len) {
                    break;
                }
                k++;
                m+=2*i;
                str[j]=s[m];
                if (m>=len) {
                    break;
                }
                j++;
                k++;
            }
        }
    
        //nrow -1
        if (i == nRows -1) {
            int k=i;
            str[j++] = s[nRows-1];
            while (j<len) {
                if (j>=len) {
                    break;
                }
                k+=b_s;
                str[j] = s[k];
                if (j>=len) {
                    break;
                }
                j++;
            }
        }
        return str;

    }
};