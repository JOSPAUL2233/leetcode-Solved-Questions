class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        
        int n = arr.size();
        
        //calculatee the frequency
        map<int,int> freq;
        
        for(int i : arr)
            freq[i]++;
        
        //make a count sort vector in which , index = freq and count[freq] = count of freq
        vector<int> count(n+1,0);
        
        for(auto p : freq){
            count[p.second]++;
        }
        
        //total number of unique elements
        int uniqueEle = freq.size();
        
        for(int f = 1;f<=n;f++){
            
            int allowed = k/f;//number of unique elements that's allowed to remove according to k
            int canRemove = count[f];//number of unique elements that can be removed
            
            //get number of unique elements that can be removed
            int removed = min(allowed,canRemove);
            
            //total elements that needs to be removed
            k -= (removed*f);
            
            //remaining unique elements
            uniqueEle -= removed;
            
            //if number of elements is lesser than current frequency
            if(k < f)
                return uniqueEle;
        }
        
        return 0;
        
    }
};