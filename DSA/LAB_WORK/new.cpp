#include <iostream>
using namespace std;
int bin_search(int arr[], int n, int val){
    int l = 0;
    int u = n - 1;
    while(l <= u){
        int m = l+(u-l)/2;

        if(arr[m] == val) return m;
        else if(arr[m] > val) u = m - 1;
        else l = m + 1;
    }
    return -1;
}

int main(){
    int arr[] = {2, 4, 6, 7, 9, 11, 45, 68};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << bin_search(arr, n, 11);
    cout<<endl;
    return 0;
}