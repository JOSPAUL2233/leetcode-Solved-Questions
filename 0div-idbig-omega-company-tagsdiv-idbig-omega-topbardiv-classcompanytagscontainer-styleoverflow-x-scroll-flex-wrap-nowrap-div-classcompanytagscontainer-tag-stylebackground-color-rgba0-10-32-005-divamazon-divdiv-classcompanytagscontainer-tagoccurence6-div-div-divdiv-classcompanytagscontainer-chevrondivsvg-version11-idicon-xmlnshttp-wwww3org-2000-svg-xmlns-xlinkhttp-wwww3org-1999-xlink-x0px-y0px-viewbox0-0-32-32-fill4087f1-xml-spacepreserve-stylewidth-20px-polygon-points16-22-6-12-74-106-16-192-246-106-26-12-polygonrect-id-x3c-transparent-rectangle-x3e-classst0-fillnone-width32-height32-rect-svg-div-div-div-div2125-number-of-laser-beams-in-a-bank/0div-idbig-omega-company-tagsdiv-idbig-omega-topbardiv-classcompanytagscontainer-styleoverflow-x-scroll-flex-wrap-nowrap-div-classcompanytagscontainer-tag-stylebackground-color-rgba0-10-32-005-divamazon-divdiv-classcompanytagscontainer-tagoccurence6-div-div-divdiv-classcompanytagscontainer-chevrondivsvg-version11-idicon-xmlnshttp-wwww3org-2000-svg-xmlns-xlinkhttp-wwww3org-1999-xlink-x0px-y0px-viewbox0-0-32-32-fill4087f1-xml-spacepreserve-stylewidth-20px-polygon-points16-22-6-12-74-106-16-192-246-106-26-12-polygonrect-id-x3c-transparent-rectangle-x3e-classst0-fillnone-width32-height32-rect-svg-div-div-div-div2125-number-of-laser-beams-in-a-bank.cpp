class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        
        int prev = 0;
        int ans = 0;
        
        for(int i = 0;i<bank.size();i++){
            
            int count = 0;
            
            for(int j = 0;j<bank[0].size();j++){
                
                if(bank[i][j] == '1')
                    count++;
                
            }
            
            if(count > 0){
                
                ans += (prev * count);
                prev = count;
            }
            
        }
        
        return ans;
        
    }
};