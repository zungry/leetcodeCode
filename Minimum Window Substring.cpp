class Solution {
public:
    string minWindow(string S, string T) {
        if (S.size() == 0 || T.size() == 0) {
            return "";
        }
        
        int start = 0;
        //int end = 0;
        int count = T.size();
        int minSize = INT_MAX;
        int minStart;
        memset(pattern, 0, sizeof(pattern));
        memset(text, 0, sizeof(text));
        
        
        for (int i = 0; i < T.size(); i++) {
            pattern[T[i]]++;
            text[T[i]]++;
        }
        
        for (int end = 0; end < S.size(); ++end) {
            if (pattern[S[end]] > 0) {
                text[S[end]]--;
                if (text[S[end]] >= 0)
                    count--;
            }
            
            if (count == 0) {
                while (true) {
                    if (pattern[S[start]] > 0) {
                        if(text[S[start]] < 0)
                            text[S[start]]++;
                        else
                            break;
                    }
                    ++start;
                }
                
                if (minSize > end - start + 1) {
                    minSize = end - start + 1;
                    minStart = start;
                }
            }
        }
        
        if (minSize == INT_MAX) {
            return "";
        }
        string ret(S,minStart,minSize);
        return ret;
    }
private:
    int pattern[256];
    int text[256];
};