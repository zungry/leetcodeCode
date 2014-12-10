class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int len = n;
        int i = 0;

        while(i < len){
            if(A[i] == elem){
                if(A[len-1] != elem)
                    swap(len-1,i,A);
                else{
                    len--;
                }
            }else{
                i++;
            }
        }

        return len;
    }

    void swap(int i,int j,int A[]){
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    };
};
