//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        
        //declare a max heap
        priority_queue<int> pq;
        
        
        //push first k elements into the heap
        for(int i = l;i<l+k;i++){
            
            pq.push(arr[i]);
            
        }
        //push elements to pq keeping the strictly k sized heap
        for(int i = l+k;i<=r;i++){

            //check if the curr element is smaller than
            //top element in the heap
            if(arr[i] < pq.top()){
                
                pq.pop();
                pq.push(arr[i]);
                
            }
            
        }
        
        //now, top k smallest elemnts will be in the heap
        //get the top (kth) element so that we will get the greatest
        //among them which is kth smallest element
        return pq.top();
        
    }
};

//{ Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends