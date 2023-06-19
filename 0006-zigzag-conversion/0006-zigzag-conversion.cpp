class Solution {
public:
    string convert(string s, int numRows) {
        
        //edge case
        if(numRows == 1)
            return s;
        
        map<int,string> raws;
        
        int count = 1;
        bool down = true;
        
        for(int i = 0;i<s.size();i++){
            
            raws[count] += s[i];
            
            if(count == numRows)
                down = false;
            else if(count == 1)
                down = true;
            
            if(down)
                count++;
            else
                count--;
                
        }
        
        string ans = "";
        
        for(int i = 1;i<=numRows;i++){
            
            ans += raws[i];
            
        }
        
        return ans;
        
    }
};
