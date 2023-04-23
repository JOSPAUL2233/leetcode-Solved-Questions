class Solution {
public:
    double myPow(double x, int n) {
        
        long num;
        double ans =1;
        
        if(n<0)num=(-1)*(long)n;
        else num=n;
        
        while(num>0){
            
            if(num%2==0){
                
                x = x * x;
                
                num /= 2;
                
            }else{
                
                ans = ans * x;
                
                num = num - 1;
                
            }
            
        }
        
        
        if(n<0)return (1/ans);
        else return ans;
        
    }
};