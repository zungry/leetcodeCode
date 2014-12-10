class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int len=n;
        int cur=0;
        if(n<=2){
            return n;
        }
        bool is_same = false;
        for (int i=1; i<n; i++) {
            if (A[i]==A[cur]) {
               // is_same = true;
                if (!is_same) {
                    is_same = true;
                    cur++;
                }else{
                    len--;
                }
            }else{
                is_same = false;
                cur++;
            }
            if (A[cur+1] != A[i+1]) {
                A[cur+1] = A[i+1];
            }

        }
            return len;
}
};