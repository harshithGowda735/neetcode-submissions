class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit =0;
        vector<int>prefixsum(n);
        prefixsum[0]=prices[0];
        for(int i=1;i<n;i++){
            prefixsum[i]=min(prefixsum[i-1] , prices[i]);
        }
        vector<int>suffixsum(n);
        suffixsum[n-1]=prices[n-1];
        for(int i=n-2;i>=0;i--){
            suffixsum[i]=max(suffixsum[i+1] , prices[i]);
        }
        for(int i=0;i<n;i++){
            int left = prefixsum[i];
            int right = suffixsum[i];
           profit = max(profit , right-left);
        }
        return profit;
    }
};
