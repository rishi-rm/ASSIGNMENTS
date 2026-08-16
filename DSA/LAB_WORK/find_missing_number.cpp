#include<iostream>
using namespace std;
int find_missing_number(int arr[], int n, int flag){
    int missing_number = -1;

    if(flag == 0){
        for(int i = 0; i < n-1; i++){
            if(arr[i+1]!=arr[i]+1){
                missing_number = arr[i]+1;
                break;
            } 
        }
    }

    if(flag==1){
        int low = 0;
        int high = n-1;
        int start_value = arr[0];
        while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == mid + start_value) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    missing_number = low + start_value;
}
    return missing_number;
}
int main(){
    int arr[] = {2, 3, 4, 5, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout<<find_missing_number(arr, n, 0)<<endl;
    cout<<find_missing_number(arr, n, 1)<<endl;

}