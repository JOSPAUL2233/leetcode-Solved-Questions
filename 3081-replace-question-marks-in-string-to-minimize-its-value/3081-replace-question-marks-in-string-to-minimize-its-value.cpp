class Solution {
public:
    string minimizeStringValue(string s) {
        
        //calculate freq and store it in multiset
        map<char,int> freq;
        multiset<pair<int,char>> st;
        
        string ans = "";
        
        string str ="";//store all the replaced elements in this
        
        for(char c : s)freq[c]++;
        for(char c = 'a';c<='z';c++) st.insert({freq[c],c});
        
        for(char c : s){
            
            if(c=='?'){
                
                auto p = *st.begin();
                st.erase(p);
                
                char ch = p.second;
                
                str.push_back(ch);
                freq[ch]++;
                
                st.insert({freq[ch],ch});
                
            }else{
                ans.push_back(c);
            }
            
        }

        //sort the replaced elements
        sort(str.begin(),str.end());
        
        int ptr = 0;
        
        for(int i = 0;i<s.size();i++){
            if(s[i]=='?'){
                s[i] = str[ptr++];
            }
        }
        
        return s;
    }
};