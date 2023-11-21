class Solution {
public:
    
    int reverse(int n){
        
        int rev = 0;
        
        while(n != 0){
            
            rev = rev * 10 + (n%10);
    
            n /= 10;
            
        }
        
        return rev;
        
    }
    
    vector<int> getRev(vector<int> nums){
        
        vector<int> ans;
        
        for(int i : nums){
            
            ans.push_back(reverse(i));
            
        }
        
        return ans;
        
    }
    
    int countNicePairs(vector<int>& nums) {
        
        int mod = 1000000007;
        
        vector<int> rev;
        vector<int> sub(nums.size(),-1);
        map<int,long long> freq;
        
        rev = getRev(nums);
        int count = 0;
        
        for(int i = 0;i<nums.size();i++){
            
            sub[i] = nums[i] - rev[i];
            
            if(freq.find(sub[i]) != freq.end()){
                
                count = (count + freq[sub[i]]) % mod;
                
            }
            
            freq[sub[i]]++;
            
        }
        
        return count;
        
    }
};