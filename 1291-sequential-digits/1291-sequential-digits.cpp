class Solution {
public:
    vector<int> sequentialDigits(int low, int high){
        
        vector<int> ans;
        
        for(int i = 1;i<10;i++){
            
            for(int j = 1;j<10;j++){
                
                int num = 0;
                
                for(int it = i;it<=j;it++){
                    
                    num = (num*10) + it;
                    
                }
                
                if(num>=low && num<=high)
                    ans.push_back(num);
                
            }
            
        }
        
        sort(ans.begin(),ans.end());
        
        return ans;
        
    }
};