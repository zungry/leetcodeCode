class Solution {
private:
    vector<vector<int> > ret;
public:
    void dfs(int dep, int maxDep, vector<int> &num, vector<int> a, int start)
    {
        ret.push_back(a);
        
        if (dep == maxDep)
            return;
            
        for(int i = start; i < num.size(); i++)
        {
            a.push_back(num[i]);
            dfs(dep + 1, maxDep, num, a, i + 1);
            a.pop_back();
        }
    }
    
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(S.begin(), S.end());
        ret.clear();
        vector<int> a;
        dfs(0, S.size(), S, a, 0);
        
        return ret;
    }
};