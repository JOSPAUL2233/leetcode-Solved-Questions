//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        int size1 = array1.size();
        int size2 = array2.size();
        int totalSize = size1 + size2;
        
        //initialize the pointers
        int ptr1 = 0;
        int ptr2 = 0;
        int count = 0;
        
        int middleIndex = totalSize / 2;
        
        //take out the middle indices
        int index2 = totalSize/2;
        int index1 = index2-1;
        
        int ele1 = -1;
        int ele2 = -1;
        
        while(ptr1 < size1 && ptr2 < size2){
            
            if(array1[ptr1] < array2[ptr2]){
                
                //checking for the index
                if(count == index1)
                    ele1 = array1[ptr1];
                
                if(count == index2)
                    ele2 = array1[ptr1];
                    
                ptr1++;

            }else{
                
                //checking for the index
                if(count == index1)
                    ele1 = array2[ptr2];
                
                if(count == index2)
                    ele2 = array2[ptr2];
                    
                ptr2++;                
            }
            
            count++;

        }
        
        while(ptr1 < size1){
            
                //checking for the index
                if(count == index1)
                    ele1 = array1[ptr1];
                
                if(count == index2)
                    ele2 = array1[ptr1];
                    
                ptr1++;  
                count++;
        }
        
        while(ptr2 < size2){
            
                //checking for the index
                if(count == index1)
                    ele1 = array2[ptr2];
                
                if(count == index2)
                    ele2 = array2[ptr2];
                    
                ptr2++; 
                count++;
        }
        
        
        
        //check if the total size is even or odd and return answer accordingly
        if(totalSize % 2 == 0)
            return (double)(ele1+ele2) / 2.0;
        else
            return ele2;
    
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends