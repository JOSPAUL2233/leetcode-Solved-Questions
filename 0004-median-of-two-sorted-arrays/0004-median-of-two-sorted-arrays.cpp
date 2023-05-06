class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> add;
        
        double ans = 0;
        
        add.insert(add.begin(),nums1.begin(),nums1.end());
        
        add.insert(add.end(),nums2.begin(),nums2.end());
        
        sort(add.begin(),add.end());
        
        if(add.size()%2 != 0)ans = add[(add.size()/2)];
        else{
            
            ans = add[(add.size()/2)]+add[((add.size()/2)-1)];
            ans /= 2;
            
        }
        
        return ans;
        
        
        
    }
};