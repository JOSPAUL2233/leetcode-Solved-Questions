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
            if(position==1){
                s[index] = "Gold Medal";
            }else if(position==2){
                s[index] = "Silver Medal";
            }else if(position==3){
                s[index] = "Bronze Medal";
            }else{
                s[index] = to_string(position);
            }
            
            
            position++;
            
        }

        return s;
        
    }
};