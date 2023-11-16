class Solution {
public:
    
    string getString(int index,string path, vector<string> nums,set<string> st){
        
        //base case
        if(index == nums.size()){
            
            if(st.find(path) == st.end())
                return path;
            else
                return "";
            
        }
        
        //recursive calls
        path.push_back('0');
        string str1 = getString(index+1,path,nums,st);
        
        if(str1.size() > 0)
            return str1;
        
        path.pop_back();
        
        path.push_back('1');
        string str2 = getString(index+1,path,nums,st);
        
        if(str2.size() > 0)
            return str2;
        
        return "";
    }
    
    string findDifferentBinaryString(vector<string>& nums) {
        
        //push all the elements to a set
        set<string> st;
        for(string s: nums)
                st.insert(s);
        
        //do generate recursively all the possible binary strings with the same length
        //and get the one which is not present in set
        int index = 0;
        
        string ans = getString(index,"",nums,st);
            
        return ans;
        
    }
};