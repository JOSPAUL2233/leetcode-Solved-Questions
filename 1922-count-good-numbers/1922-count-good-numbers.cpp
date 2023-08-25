class Solution {
public:
    
    
    
    long long power(long long a,long long b,int mod){
        
        
        //base case
        if(b == 0)
            return 1;
        
        //get the value of a^(b/2);
        long long subAns = power(a,b/2,mod);
        
        //get the value of a^(b/2) * a^(b/2)
        subAns *= subAns;
        subAns %= mod;
        
        //if b is odd, multiply a with it once again
        if(b%2 == 1){
            
            subAns = subAns * a;
            subAns %= mod;
            
        }
        
        return subAns; 
        
    }
    
    int countGoodNumbers(long long n) {
        
    //from 0 - 9,
    //there are 4 prime numbers(2,3,5,7)
    //there are 5 even numbers(0,2,4,6,8)
        
    long long evenPlaces = n/2 + n%2; // positions are 1,3,5 etc. since it is 0 indexed
    long long oddPlaces = n/2;//positions are 0,2,4 etc.

        
    //keep the mod value as given in question
    int mod = pow(10,9) + 7;
        
        
    //we should writer power function instead of using pow because of mod    
    long long ans = power(5,evenPlaces,mod) * power(4,oddPlaces,mod);
        
    return ans % mod;
        
    }
};