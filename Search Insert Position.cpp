class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int left = 0;
        int right = n - 1;
        
        
        while(left <= right){
            int mid = (left + right) / 2;
            if(A[mid] == target) return mid;
            if(A[mid] < target){
                if(A[mid + 1] >target || mid + 1 == n)
                    return mid + 1;
                else
                    left = mid+1;
            }else{
                if(A[mid - 1] < target)
                    return mid;
                else
                    right = mid - 1;
            }
        }
    }
};