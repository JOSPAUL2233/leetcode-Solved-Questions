class Solution {
public:
    
    //this function returns the reverse of n
    int reverse(int n){
        
        int rev = 0;
        
        while(n != 0){
            
            rev = rev * 10 + (n%10);
    
            n /= 10;
            
        }
        
        return rev;
        
    }
    
    //this function reverse all the elements of nums and returns the same
    vector<int> getRev(vector<int> nums){
        
        vector<int> ans;
        
        for(int i : nums){
            
            ans.push_back(reverse(i));
            
        }
        
        return ans;
        
    }
    
    int countNicePairs(vector<int>& nums) {
        
        //define a mod
        int mod = 1000000007;
        
        vector<int> rev;
        vector<int> sub(nums.size(),-1);
        map<int,long long> freq;
        
        rev = getRev(nums);
        
        //keep a count of all the pairs
        int count = 0;
        
        for(int i = 0;i<nums.size();i++){
            
            //store the subtracted value of (nums - rev(nums))
            sub[i] = nums[i] - rev[i];
            
            //count the number of pairs it can be formed.
            if(freq.find(sub[i]) != freq.end()){
                
                count = (count + freq[sub[i]]) % mod;
                
            }
            
            //increase the frequency of current number.
            freq[sub[i]]++;
            
        }
        
        //return the count
        return count;
        
    }
};