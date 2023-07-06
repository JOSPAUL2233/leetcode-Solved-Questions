class Solution {
public:
    
    int reverse(int x){
        
        int ans = 0;
        int rem = 0;
        
        while(x != 0){

            rem = x % 10;

            //if number exceeds integer maximum or minimum limit return false
            if(ans>INT_MAX/10 || ans<INT_MIN/10 )return false;
            
            ans =ans * 10 + rem;
            
            x /= 10;
        }
        
        return ans;
}
    
    bool isPalindrome(int x) {
     
        int n = x;
        int ans;
        
        // if the number is less than 0 not accepted as a pallindrome
        if(x < 0 ) return false;

        // reversing a number i.e [ 123 reversed to 321 ]
        ans = reverse(n);

        //if number is pallindrome return true
        if(ans == x)
            return true;
        else
            return false;
         
    }
};



