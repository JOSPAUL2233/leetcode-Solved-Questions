class Solution {
public:
    
    string getString(int index,string path, vector<string> nums,set<string> st){
        
        //base case will be reached when the index exceeds the last index of nums
        if(index == nums.size()){
            
            if(st.find(path) == st.end())//if the answer is found
                return path;
            else//if the answer is not found
                return "";
            
        }
        
        //recursive calls
        
        //try taking 0 in the path and go for further calls---------------
        path.push_back('0');
        string str1 = getString(index+1,path,nums,st);
        
        //if we cound find the answer, return that answer itself
        if(str1.size() > 0)
            return str1;
        
        //if we cound'nt find the answer,remove 0 and try putting 1 inplace of 0
        //and go for further calls
        path.pop_back();
        path.push_back('1');
        
        string str2 = getString(index+1,path,nums,st);
        
        //if we cound find the answer, return that answer itself
        if(str2.size() > 0)
            return str2;
        
        //if non of str1 or str2 gave the answer, return an empty string
        return "";
    }
    
    string findDifferentBinaryString(vector<string>& nums) {
        
        //push all the elements to a hashSet so to check for the answer further
        set<string> st;
        for(string s: nums)
                st.insert(s);
        
        //do generate recursively all the possible binary strings with the same length
        //and get the one which is not present in set
        int index = 0;
        
        //this gets the answer from the recursive function 'getString' and returns it
        string ans = getString(index,"",nums,st);
            
        return ans;
        
    }
};