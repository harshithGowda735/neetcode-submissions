class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int total = 0;
        vector<int>prefixsum(n);
        prefixsum[0]=height[0];
        for(int i=1;i<n;i++){
            prefixsum[i]=max(prefixsum[i-1] , height[i]);
        }
        vector<int>suffixsum(n);
        suffixsum[n-1]=height[n-1];
        for(int i= n-2;i>=0;i--){
            suffixsum[i]=max(suffixsum[i+1],height[i]);
        }
        for(int i=0;i<n;i++){
            int left = prefixsum[i];
            int right = suffixsum[i];
             total+= min(left , right)-height[i];
        }
        return total;

    }
};
