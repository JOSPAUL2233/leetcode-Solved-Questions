class Solution {
public:
    
    
    
    long long power(long long a,long long b,int mod){
        
        
        //base case
        if(b == 0)
            return 1;
        
        
        if(b % 2 == 0){
            
            return power(a*a % mod,b/2,mod) % mod;
            
        }else{
            
            return a * power(a,b-1,mod) % mod;
            
        }
        
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