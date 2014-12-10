class Solution {
    
private:
    const int index_count;
    vector<vector<int> > results;
public:
    Solution():index_count(10000){};
    
    void backtrace(int target,int sum,vector<int>&candidates,int index[],int n){
        if (sum > target) {
            return;
        }
        
        if (sum == target) {
            vector<int> result;
            for (int i = 1; i <= n; i++) {
                result.push_back(candidates[index[i]]);
            }
            
            results.push_back(result);
            return;
        }
        
        for (int i = index[n]; i < candidates.size(); ++i) {
            index[n+1] = i;
            backtrace(target, sum+candidates[i], candidates, index, n+1);//深度遍历
            
        }
        
        
    }
    
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int *index = new int[index_count];
        memset(index, 0, sizeof(int)*index_count);
        results.clear();
        
        backtrace(target, 0, candidates, index, 0);
        delete[] index;
        
        return results;
    }
};