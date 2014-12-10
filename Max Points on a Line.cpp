class Solution {
public:
    int maxPoints(vector<Point> &points) {
        unordered_map<float,int> mp;
        int ret = 0;


        for(int i = 0 ; i < points.size(); i++){
            mp.clear();
            mp[INT_MIN] = 0;


            int duplicate = 1;
            for(int j = 0; j < points.size(); j++){
                if(i == j) continue;
                if(points[i].x == points[j].x && points[i].y == points[j].y){
                    duplicate++;
                    continue;
                }
                float k = points[i].x == points[j].x ? INT_MAX : (float)(points[i].y - points[j].y)/(points[i].x - points[j].x);
                mp[k]++;
            }
            unordered_map<float,int>::iterator it = mp.begin();
            for(;it != mp.end();it++){
                if(it->second + duplicate > ret){
                    ret = it->second + duplicate;
                }
            }
        }
        return ret;
    }
};