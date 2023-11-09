class Solution {
public:
    int numSub(string s) {
        
        int ind = 0;
        int sum = 0;
        
        long long mod = 1000000007;
        
        while(ind < s.size()){
            
            if(s[ind] == '1'){
             
                char c = s[ind];
                long long count = 0;
                
                while(ind < s.size() && c == s[ind]){
                    count++;
                    ind++;
                }
                
                long long subSum = (count*(count+1)/2) % mod;
                sum += subSum % mod;
                
            }else{
                ind++;
            }
            
        }
        
        return sum;
        
    }
};