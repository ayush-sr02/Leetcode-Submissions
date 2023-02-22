//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	

	void segregateEvenOdd(int arr[], int n) {
	    // code here
	    int odd=0,even=0;
	    for(int i=0;i<n;i++){
	        if(arr[i]&1) odd++;
	        else even++;
	    }
	    int a1[odd],a2[even];
	    int i=0,j=0;
	    int k=0;
	    while(k<n){
	        if(arr[k]&1){
	            a1[i++]=arr[k];
	        }else{
	            a2[j++]=arr[k];
	        }
	        k++;
	    }
	    sort(a1,a1+odd);
	    sort(a2,a2+even);
	    i=0,j=0;
	    k=0;
	    while(i<even){
	        arr[k++]=a2[i++];
	    }
	    while(j<odd){
	        arr[k++]=a1[j++];
	    }
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.segregateEvenOdd(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends