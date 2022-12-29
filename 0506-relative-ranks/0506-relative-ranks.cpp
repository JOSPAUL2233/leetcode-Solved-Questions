class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        
        vector<string> s(score.size(),"0");
        
        priority_queue<int> q;
        
        for(auto x:score){
            q.push(x);
        }
        
        int position = 1;
        
        while(!q.empty()){
            
            int x = q.top();
            q.pop();
            
            int index = 0;
            
            for(int i = 0;i<score.size();i++){
                
                if(score[i]==x){
                    index = i;
                    break;
                }
                
            }
            
            s[index] = to_string(position);
            
            position++;
            
        }
        
        for(int i = 0;i<s.size();i++){
            if(s[i] == "1")s[i] = "Gold Medal";
            if(s[i] == "2")s[i] = "Silver Medal";
            if(s[i] == "3")s[i] = "Bronze Medal";
        }
        
        return s;
        
    }
};