class Solution {
public:
    int countHomogenous(string s) {
        
        int sum = 0;
        int mod = pow(10,9)+7;
        
        int left = 0;
        int right = 0;
        
        while(right < s.size()){
            
            while(right < s.size() && s[left] == s[right])
                right++;
            
            long long size = right - left;
            
            long long subSum = ((size*(size+1))/2) % mod;
            
            sum += subSum % mod;
            
            left = right;
            
        }
        
        return sum % mod;
        
    }
};