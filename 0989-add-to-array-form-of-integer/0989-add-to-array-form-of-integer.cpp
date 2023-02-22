class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        
        //iterating from the last index till the 1st index
        
        for(int i = num.size()-1;i>=0;i--){
            
            num[i]+=k;
            
            k = num[i]/10;
            
            num[i]%=10;
               
            
        }
        
        //if k is greater, then insert it one by one at the begining
        
        while(k>0){
            
            num.insert(num.begin(),k%10);
            k/=10;
            
        }
        
        return num;
        
    }
};