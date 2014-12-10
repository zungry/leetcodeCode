class Solution{
public:
    void collect(vector<vector<int>>& mark, int ind, const string& s, string path, vector<string>& result){
             //ind是s中子字符串开始的下标，mark里第ind项存放子字符串结束的下标+1即stop。
        for(int i=0;i<mark[ind].size();i++){
            int stop = mark[ind][i];
            string sub=s.substr(ind,stop-ind);
            string newpath=path+(ind==0?sub:" "+sub);   ////此句写的很简洁
            if(stop==s.length()) 
               result.push_back(newpath);
            else 
               collect(mark,stop,s,newpath,result);
    }//end for
}//end collect
vector<string> wordBreak(string s, unordered_set<string> &dict) {

    vector<vector<int>> mark(s.length(),vector<int>());
    for(int stop=s.length();stop>=0;stop--){    //用两个for循环给mark赋值，中间用了if...continue..大大节省了时间

        if(stop<s.length() && mark[stop].empty())continue;//本句最节省时间！！！
//如果没有以下标stop开始的字符串，就不必有下面for循环中以stop-1结束的字符串了，所以continue
        for(int start=stop-1;start>=0;start--)//以下标start开始，stop结束的字符串，即s中[start,stop)之间;
            if(dict.count(s.substr(start,stop-start)))
                mark[start].push_back(stop);
    }//end for
    vector<string> result;
    collect(mark,0,s,"",result);
    return result;
}//end wordBreak
};