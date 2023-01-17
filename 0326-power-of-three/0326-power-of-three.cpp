class Solution {
public:
    
    void solve(long p,int n,bool &ans){
        
        if(p==n){
        ans = true;
        return;
        }
        if(p>n){
            ans = false;
            return;
        }
        
        solve(p*3,n,ans);
        
        return;
    }
    bool isPowerOfThree(int n) {
        
        bool ans = false;
        
        if(n<=0)return false;
        
        if(n==1)return true;
        
        solve(3,n,ans);
        
        return ans;
        
    }
};