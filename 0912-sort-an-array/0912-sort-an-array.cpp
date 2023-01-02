class Solution {
public:
    
    void merge(vector<int>& nums,int s,int e){

        int mid = (s+e)/2;

        int len1 = mid-s+1;

        int len2 = e-mid;

        int *arr1 = new int[len1];
        int *arr2 = new int[len2];

        int k = s;


        //assigning value to the two newly created arrays

        for(int i = 0;i<len1;i++){
            arr1[i] = nums[k++];
        }

        k = mid+1;

        for(int i = 0;i<len2;i++){
            arr2[i] = nums[k++];
        }

        //sort the two sorted arrays

        int ind1 = 0;
        int ind2 = 0;
        k = s;

        while(ind1<len1 && ind2<len2){

            if(arr1[ind1] < arr2[ind2]){
                nums[k++] = arr1[ind1++];
            }else{
                nums[k++] = arr2[ind2++];
            }

        }

        while(ind1<len1){
            nums[k++] = arr1[ind1++];
        }
        while(ind2<len2){
            nums[k++] = arr2[ind2++];
        }

    }
    
    void mergeSort(vector<int>& nums,int s,int e){

        //base case
        if(s>=e)return;

        int mid = (s+e)/2;

        //split left part
        mergeSort(nums,s,mid);

        //split right part
        mergeSort(nums,mid+1,e);

        //merge two sorted arrays

        merge(nums,s,e);

    }
    
    vector<int> sortArray(vector<int>& nums) {
        
        int n = nums.size();
        
        mergeSort(nums,0,n-1);
        
        return nums;
        
        
        
    }
};