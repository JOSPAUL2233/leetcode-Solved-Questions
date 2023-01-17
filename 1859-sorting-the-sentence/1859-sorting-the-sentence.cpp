class Solution {
public:
    string sortSentence(string s) {
        
        vector<string> vec(10,"");
        
        for(int i = 0;i<s.size();i++){
            
            int j = i;
            
            string temp = "";
            
            while(!isdigit(s[j])){
                temp+=s[j];
                j++;
            }
            
            vec[s[j]-'0'] = temp;
            i = j+1;
            
        }
        
        string ans;
        
        for(int i = 1;i<10;i++){
            
            if(vec[i].size()>0){
            ans+=vec[i];
            ans+=' ';
            }
        }
        
        ans.pop_back();
        return ans;
        
    }
};