class Solution {
    
public:
    vector<string> restoreIpAddresses(string s) {
        ret.clear();
        dfs(0, 4, s, 0);
        return ret;
    };
    vector<string> ret;
    int f[4];
    
private:
    bool is_ip(string t,int start,int end){
        string s(t,start,end-start+1);
        
        if (s.length()!=1 && s[0]=='0') {
            return false;
        }
        
        int num=0;
        int n;
        if(s.size()>3){
            return false;
        }
        for(int i=0;i<s.size();i++){
            n = s[i]-'0';
            num = num * 10 + n;
        }
        //cout << num << endl;
        if (num < 256) {
            return true;
        }
        return false;
    };
    
    void dfs(int depth,int max_depth,string &s, int start){
        if (depth == max_depth) {
            if(start == s.size()){
                
                int beg = 0;
                string str;
                for (int i=0; i<4; i++) {
                    string ip(s,beg,f[i]-beg+1);
                    beg = f[i] +1;
                    str += i==0 ? ip : ("."+ip);
                    
                }
                ret.push_back(str);
                // cout << str << endl;
            }
            return;
        }
        for (int i=start; i<s.size(); i++) {
            if (is_ip(s, start, i)) {
                f[depth]=i;
                dfs(depth+1, max_depth, s, i+1);
            }
        }
    }
};