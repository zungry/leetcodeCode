class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int N = gas.size();
        for (int i = 0; i < N; i++) {
            bool flag = circular(i, N, gas, cost);
            if (flag) {
                return i;
            }
        }
        return -1;
    }
    
    bool circular(int start,int N,vector<int> &gas,vector<int> &cost){
        if (gas[start] < cost[start]) {
            return false;
        }
        int gasSum = 0;
        int costSum = 0;
        for (int i = start; i < N + start; i++) {
            gasSum += gas[i%N];
            costSum += cost[i%N];
            if (gasSum < costSum) {
                return false;
            }
        }
        return true;
    }
    
};
