class Solution {
public:
    void sortColors(int A[], int n) {
        if(n <= 1) return;
        int start = -1, end = n;
        int p = 0;
        while(p < n){
            if(A[p] == 0){
                if(p > start) swap(A, ++start, p);
                else ++p;
            }else if(A[p] == 2){
                if(p < end) swap(A, p, --end);
                else ++p;
            }else ++p;
        }
    }
private:
    void swap(int A[], int i, int j){
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
};
