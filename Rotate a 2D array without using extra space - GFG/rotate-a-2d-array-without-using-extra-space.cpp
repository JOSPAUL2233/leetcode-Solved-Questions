//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	void rotate(vector<vector<int>>& arr,int n){
	    
	    for(int i = 0;i<n;i++){
	        
	        for(int j = 0;j<i;j++){
	            
	            swap(arr[i][j],arr[j][i]);
	            
	        }
	        
	    }
	    
	}
	
	void reverse(vector<int> &arr,int left, int right){
	    
	    while(left < right){
	        
	        swap(arr[left],arr[right]);
	        
	        left++;
	        right--;
	    }
	    
	}
	
	void rotate90(vector<vector<int>>& arr,int n){
	    
        //rotate 90 degree three times to right
        rotate(arr,n);

        //reverse row wise
        for(int i = 0;i<n;i++){
            
            reverse(arr[i],0,n-1);
            
        }   	    
	}
	
	void rotateMatrix(vector<vector<int>>& arr, int n) {

        //rott
        rotate90(arr,n);
        rotate90(arr,n);
        rotate90(arr,n);

	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; i++) {
            vector<int> a;
            for (int j = 0; j < n; j++) {
                cin >> x;
                a.push_back(x);
            }
            arr.push_back(a);
        }
        Solution ob;
        ob.rotateMatrix(arr, n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << arr[i][j] << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends