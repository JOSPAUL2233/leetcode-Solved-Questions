class Solution {
public:
    
    bool check(map<char,string> &left,map<string,char> &right,char c,string str){
        
        //check for left
        if(left.find(c) != left.end()){
            if(left[c] != str){
                // cout<<"fail"<<endl;
                return false;
            }
        }else
            left[c] = str;
        
        //check for right
        if(right.find(str) != right.end()){
            if(right[str] != c){
                // cout<<"fail2"<<endl;
                return false;
            }
        }else
            right[str] = c;
        
        
        // cout<<"success"<<endl;
        return true;
        
    }
    bool wordPattern(string pattern, string s) {
        
        //make two mapps for both the directions
        map<char,string> left;
        map<string,char> right;
        
        int i = 0;
        
        int ptr1 = 0;
        int ptr2 = 0;
        
        while(ptr2 < s.size()){
            
            //take care of last index
            if(ptr2 == s.size()-1){
                
                char c = pattern[i++];
                int strLen = ptr2 - ptr1 + 1;//only this makes difference
                                
                string str = s.substr(ptr1,strLen);
                
                // cout<<c<<" "<<str<<endl;
                
                if(!check(left,right,c,str))
                    return false;
                
                if(i < pattern.size())
                    return false;
                
            }
            
            if(s[ptr2] == ' '){
                
                char c = pattern[i++];
                int strLen = ptr2 - ptr1;//only this makes difference
                
                // cout<<strLen<<endl;
                
                string str = s.substr(ptr1,strLen);
                
                // cout<<c<<" "<<str<<endl;
                
                if(!check(left,right,c,str))
                    return false;
            
                ptr1 = ptr2+1;
            
            }
            
            ptr2++;
                                    
        }
        
        return true;
        
    }
};