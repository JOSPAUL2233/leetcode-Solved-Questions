class Solution {
public:
    bool buddyStrings(string s, string goal) {        
        
        //return false if the length is different
        if(s.size() != goal.size())
            return false;    
        
        if(s==goal){
            //-- if the strings are same,
            //check if they have duplicate chars(return true)

            map<int,int> freq;
            
            int count = 0;
            for(int i = 0;i<s.size();i++){
                freq[s[i]]++;
                
                if(freq[s[i]] == 2)
                    return true;
            }

            return false;
            
        }else{
            //-- if the strings are different
            //check if they have two different characters and match
            //it with the other string characters in rev order(return true)
            
            int index1 = -1;
            int index2 = -1;
            
            for(int i = 0;i<s.size();i++){
                
                if(s[i] != goal[i]){
                    
                    if(index1 == -1){
                        index1 = i;
                    }else if(index2 == -1){
                        index2 = i;
                    }else
                        return false;
                    
                }
                
            }
            
            if(index1 == -1 || index2 == -1)
                return false;

            swap(s[index1],s[index2]);
            
            if(s==goal)
                return true;
            else
                return false;
            
        }
        
    }
};