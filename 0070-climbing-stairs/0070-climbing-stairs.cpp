class Solution {
public:
    int number(int n,vector<int> &dp){
        
        if(n <= 1)
            return 1;
        
        if(dp[n] != -1)
            return dp[n];
        
        dp[n] = number(n-1,dp) + number(n-2,dp);
        
        return dp[n];
        
    }
    
    int climbStairs(int n) {
        
        vector<int> dp(n+1,-1);
        
        int ans = number(n,dp);
        return ans;
        
    }
};