class Solution{
public:
    int lengthOfLongestSubstring(string s){
        int locs[300];//记录上次字符出现的位置。
        int ret = 0;
        int idx = -1;
        memset(locs,-1,sizeof(locs));

        for(int i = 0; i < s.size(); i++){
            if(locs[s[i]] > idx)
                idx = locs[s[i]];
            ret = max(ret,i - idx);
            locs[s[i]] = i;
        }
        return ret;
    }
};