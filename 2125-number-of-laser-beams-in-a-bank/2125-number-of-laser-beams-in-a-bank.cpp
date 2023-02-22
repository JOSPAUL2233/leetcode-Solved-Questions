class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        
        
        vector<int> beams;
        
        for(int i = 0;i<bank.size();i++){
            
            int count = 0;
            string s = bank[i];
            
            for(int j = 0;j<s.size();j++){
                
                if(s[j]=='1')count++;
                
            }
            
            if(count!=0)beams.push_back(count);
            
            
        }
        int ans = 0;
        
        if(beams.size()==0)return 0;
        
        for(int i = 0;i<beams.size()-1;i++){
            
            ans += beams[i]*beams[i+1];
            
        }
        return ans;
        
        
    }
};