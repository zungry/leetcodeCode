class Solution {
private:
    bool canUse[100];
    int a[100];
    vector<vector<int> > ret;
public:
    void dfs(int dep, int maxDep, vector<int> &num)
    {
        if (dep == maxDep)
        {
            vector<int> ans;
            for(int i = 0; i < maxDep; i++)
                ans.push_back(a[i]);
            ret.push_back(ans);
            return;
        }
        
        for(int i = 0; i < maxDep; i++)
            if (canUse[i])
            {
                if (i != 0 && num[i] == num[i-1] && canUse[i-1])
                    continue;
                    
                canUse[i] = false;
                a[dep] = num[i];
                dfs(dep + 1, maxDep, num);
                canUse[i] = true;
            }
    }
    
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(), num.end());
        memset(canUse, true, sizeof(canUse));
        ret.clear();
        dfs(0, num.size(), num);
        return ret;
    }
};