class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
      
        //USING A VECTOR SPACE (ADDITIONAL)
        
//         vector<int> beams;
        
//         for(int i = 0;i<bank.size();i++){
            
//             int count = 0;
//             string s = bank[i];
            
//             for(int j = 0;j<s.size();j++){
                
//                 if(s[j]=='1')count++;
                
//             }
            
//             if(count!=0)beams.push_back(count);
            
            
//         }
//         int ans = 0;
        
//         if(beams.size()==0 || beams.size()==1)return 0;
        
        
//         for(int i = 0;i<beams.size()-1;i++){
            
//             ans += beams[i]*beams[i+1];
            
//         }
//         return ans;
        
        
        //WITHOUT USING EXTRA SPACE
        
    int prev = 0;
    int ans = 0;
        for(string s: bank){
            
            int curr = 0;
            
            for(int i = 0;i<s.size();i++)
                if(s[i]=='1')
                    curr++;
            
            if(curr>0){
                
                ans += prev*curr;
                prev = curr;
                
            }
            
            
        }
        
        return ans;
        
    }
};