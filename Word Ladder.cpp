class Solution {
public:
    
    struct Node{
        string word;
        int num;
        Node():num(0){};
    };
    
    queue<Node> q;
    unordered_set<string> del;
    
    
    
    
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if (start == end) {
            return 1;
        }
        
        if (diff(start,end) == 1) {
            return 2;
        }
        
        while (!(q.empty())) {
            q.pop();
        }
        
        del.clear();
        
        Node a;
        a.word = start;
        q.push(a);
        
        int ret = -1;
        del.insert(start);
        
        
        
        while (!q.empty()) {
            Node tmp = q.front();
            q.pop();
            
            if (tmp.word == end) {
                ret = tmp.num;
                break;
            }
            
            int length = start.length();
            for (int i = 0; i < length; i++) {
                for (int j = 0; j < 26; j++) {
                    string str =tmp.word;
                    str[i] = 'a'+j;
                    
                    if (str!=tmp.word&&dict.find(str)!=dict.end()&&del.find(str)==del.end()) {
                        Node nd;
                        nd.word = str;
                        nd.num = tmp.num + 1;
                        q.push(nd);
                        del.insert(str);
                    }
                }
            }
        }
        return ret + 1;
    };
    
    
    int diff(string start ,string end){
        int i, len = start.length();
        int ret;
        for (i = 0; i < len; i++) {
            if (start[i] != end[i]) {
                ret++;
            }
        }
        return ret;
    }
    
};