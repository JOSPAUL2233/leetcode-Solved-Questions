class Solution {
public:
    
    string repeatChar(char c,int size){
        
        string s = "";
        
        for(int i = 0;i<size;i++)
            s += c;
        
        return s;
        
    }
    
    string frequencySort(string s) {
        //count frequency
        map<char,int> freq;
        
        for(char c : s){
            
            freq[c]++;
            
        }
        
        
        //push freq into heap based on frequency
        priority_queue<pair<int,char> > que;
        
        for(auto p : freq){
            
            que.push({p.second,p.first});
            
        }
        
        //now, place the elements into new string after sorting characters by freq
        string str = "";
        while(!que.empty()){
            
            //store char frequency times
            str += repeatChar( que.top().second , que.top().first );
            que.pop();
            
        }
        
        return str;
    
    }
};