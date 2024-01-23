class Solution {
public:
    int solve(vector<string> arr,string &path,int index){
        
        //base cases
        
        //check for duplicate chars in path
        unordered_set<char> st(path.begin(),path.end());
        if(st.size() != path.size())
            return 0;

        //if it has reached the end
        if(index == arr.size())
            return path.size();
        
        for(char c : arr[index]) path.push_back(c);
        int left = solve(arr,path,index+1);
        for(char c : arr[index]) path.pop_back();

        int right = solve(arr,path,index+1);
        
        return max(left,right);
        
    }
    int maxLength(vector<string>& arr) {
                
        string path = "";
        int index = 0;
        
        int ans = solve(arr,path,index);
        
        return ans;
        
    }
};