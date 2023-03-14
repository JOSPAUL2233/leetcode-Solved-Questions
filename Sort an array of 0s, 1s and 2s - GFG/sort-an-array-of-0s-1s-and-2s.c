// { Driver Code Starts
//Initial Template for C

#include <stdio.h>


 // } Driver Code Ends
//User function Template for C

void sort012(int a[], int n)
{
    
    int start = 0;
    int mid = 0;
    int end = n-1;
    int temp = -1;
    
    while(mid<=end){
        
        if(a[mid] == 1)mid++;
        else if(a[mid] == 0){
            
            //SWAP a[mid] and a[start]
            temp = a[mid];
            a[mid] = a[start];
            a[start] = temp;
            
            mid++;
            start++;
            
        }else{
            
            //SWAP a[mid] and a[end]
            temp = a[mid];
            a[mid] = a[end];
            a[end] = temp;
            
            end--;
            }
         
    }
    
}

// { Driver Code Starts.

int main() {

    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);
        int arr[n];
        for(int i=0;i<n;i++){
            scanf("%d", &arr[i]);
        }

        sort012(arr, n);

        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
    return 0;
}
  // } Driver Code Ends