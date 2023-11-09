class Solution {
public:
    
    bool check(map<char,string> &left,map<string,char> &right,char c,string str){
        
        //check for left
        if(left.find(c) != left.end()){
            
            if(left[c] != str){
                return false;
            }
            
        }else
            left[c] = str;
        
        
        //check for right
        if(right.find(str) != right.end()){
            
            if(right[str] != c){
                return false;
            }
            
        }else
            right[str] = c;
        
        
        //if everything is fine
        return true;
        
    }
    bool wordPattern(string pattern, string s) {
        
        //make two mapps for both the directions
        map<char,string> left;
        map<string,char> right;
        
        //index in pattern
        int i = 0;
        
        //indices in s
        int ptr1 = 0;
        int ptr2 = 0;
        
        while(ptr2 < s.size()){
            
            //take care of last index
            if(ptr2 == s.size()-1){
                
                int strLen = ptr2 - ptr1 + 1;//get the length of string

                //extract the char and string
                char c = pattern[i++];
                string str = s.substr(ptr1,strLen);
                
                //go for checking
                if(!check(left,right,c,str))
                    return false;
                
                //if ptr2 is the last index but there are still characters left in patter,
                //then it is not a valid matching pattern
                if(i < pattern.size())
                    return false;
                
            }
            
            if(s[ptr2] == ' '){
                
                int strLen = ptr2 - ptr1;//get the length of string
                
                //extract the char and string
                char c = pattern[i++];
                string str = s.substr(ptr1,strLen);
                
                //go for checking
                if(!check(left,right,c,str))
                    return false;
            
                //update the first pointer to starting of next word
                ptr1 = ptr2+1;
            
            }
            
            //keep increasing the second pointer
            ptr2++;
                                    
        }
        
        return true;
        
    }
};