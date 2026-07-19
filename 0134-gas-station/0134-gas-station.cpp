class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int in = 0;
        int out = 0;
        for(int i=0 ; i<n ; i++){
            in += gas[i];
            out += cost[i];
        }
        if(out > in) return -1;

        int profit = 0;
        int ans = 0;
        for(int i=0 ; i<n ; i++){
            profit += gas[i] - cost[i];
            if(profit < 0){
                profit=0;
                ans = i+1;
            }
        }
        return ans;
    }
};