class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int ret=0;
        sort(num.begin(), num.end());
        
        bool first = true;
        for (int i=0; i<num.size(); i++) {
            int j=i+1;
            int k=num.size()-1;
    
            while (j<k) {
                int sum=num[i]+num[j]+num[k];
                
                if (first) {
                    ret=sum;
                    first=false;
                }
                else{
                    if (abs(sum-target) < abs(ret-target)) {
                        ret=sum;
                    }
                }
                
                if (ret == target) {
                    return target;
                }
                
                if (sum < target) {
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        return ret;
    }
};