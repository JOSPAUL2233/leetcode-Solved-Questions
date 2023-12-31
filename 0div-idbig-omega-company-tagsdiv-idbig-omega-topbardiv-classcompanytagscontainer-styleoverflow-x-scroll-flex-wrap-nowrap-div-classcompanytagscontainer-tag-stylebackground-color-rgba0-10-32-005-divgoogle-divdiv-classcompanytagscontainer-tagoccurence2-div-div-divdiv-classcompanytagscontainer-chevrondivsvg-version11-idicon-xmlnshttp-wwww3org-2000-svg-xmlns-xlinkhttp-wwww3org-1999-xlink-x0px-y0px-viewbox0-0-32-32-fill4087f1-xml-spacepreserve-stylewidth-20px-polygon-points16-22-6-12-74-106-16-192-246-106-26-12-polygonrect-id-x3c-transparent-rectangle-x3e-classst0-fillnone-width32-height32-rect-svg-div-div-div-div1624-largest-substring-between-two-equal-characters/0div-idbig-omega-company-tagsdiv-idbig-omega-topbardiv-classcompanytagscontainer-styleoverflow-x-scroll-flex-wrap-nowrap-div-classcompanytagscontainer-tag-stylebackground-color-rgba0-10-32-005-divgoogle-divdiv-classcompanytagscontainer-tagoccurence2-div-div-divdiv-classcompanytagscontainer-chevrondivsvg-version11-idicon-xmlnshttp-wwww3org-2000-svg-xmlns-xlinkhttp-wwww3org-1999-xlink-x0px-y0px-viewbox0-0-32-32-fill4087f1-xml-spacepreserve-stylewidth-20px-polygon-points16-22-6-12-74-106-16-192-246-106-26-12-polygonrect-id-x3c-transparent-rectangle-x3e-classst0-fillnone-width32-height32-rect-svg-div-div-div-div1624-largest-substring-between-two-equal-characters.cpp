class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s){
        
        map<char,int> index;//char,index
        int maxi = -1;
        
        for(int i = 0;i<s.size();i++){
            
            //first time appearance
            if(index[s[i]] == 0)
                index[s[i]] = i+1;
            else
                maxi = max(maxi,(i - index[s[i]]));
            
        }
        
        return maxi;
        
    }
};