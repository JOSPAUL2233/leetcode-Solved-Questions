class Solution {
public:
    
    void reverse(string& s,int left,int right){
        
        // for(int i = left;i<=right;i++)
        //     cout<<s[i];
        
        while(left < right){
            
            swap(s[left],s[right]);
            
            left++;
            right--;
        }
        
    }
    
    string reverseWords(string s) {
        
        //INTUITION
        //reverse the whole string and then reverse word by word
        
        int i = 0;
        
        string str = "";
        
        int n = s.size();
        
        while(i < n){

            //find the 1st non-space character
            while(i < n && s[i] == ' ')i++;
            
            //if i has reached the last index
            if(i == n)
                break;

            //find the first space after i
            int j = i;
            while(j < n && s[j] != ' ')j++;

            string word = s.substr(i,j-i);
            
            if(str.size() == 0)
                str = word;
            else
                str = word + " " + str;
            
            i = j+1;
            
        }
        
        return str;
        
    }
};