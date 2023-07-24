//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        
        //get sumArr and sqSumArr from the array
        
        long long sumArr = 0;
        long long sqSumArr = 0;
        
        for(int i = 0;i<n;i++){
            
            sumArr += (long long)arr[i];
            sqSumArr += ((long long)arr[i]*arr[i]);
            
        }
        
        //get sumAp and sqSumAp using formula
        //sum of n natureal numbers = n(n+1)/2
        //sum of squares of n natureal number =( n(n+1)(2n+1) )/ 6
        
        long long sumAp = (long long)n*(n+1)/2;
        long long sqSumAp = ((long long)n*(n+1)*(2*n+1))/6;
        
        
        //let x be repeating element and y be missing element
        //now do sumArr - sumAp to get x - y and store it in ele1
        //and do sqSumArr - sqSumAp to get x^2 - y^2 and store it in ele2
        long long ele1 = sumArr - sumAp;
        long long ele2 = sqSumArr - sqSumAp;
        
        //put divide ele2 from using ele1 to get x + y and store it in ele3
        long long ele3 = ele2 / ele1;
        
        //now, we have got ele1 as x-y and ele3 as x+y
        
        //by adding x-y and x+y , we will get 2x, then divide it by 2 to
        //get the value of x
        int x = (ele1 + ele3)/2;
        
        //subtract x from x + y(ie. ele3) to get the value of y
        int y = ele3 - x;
        
        return {x,y};
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends