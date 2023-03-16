class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        vector<int>nums = nums1;
        int i = 0;
        int j = 0;
        int k = 0;
        while(i<m && j<n){
            if(nums[i]<=nums2[j]){

                    nums1[k++] = nums[i++];
                    

            }else{

                    nums1[k++] = nums2[j++];

            }
        }

            while(j<n){
                nums1[k++] = nums2[j++];
            }

            while(i<m){
                nums1[k++] = nums[i++];
            }

    }
        
};