#include<iostream>
using namespace std;
int search(int arr[], int n, int target){
    for(int i = 0; i < n; i++){
        if(arr[i] == target) return i; 
    }

    return -1;
}

int main(){
    int arr[] = {2, 4, 6, 7, 9, 11, 45, 68};
    int n = sizeof(arr) / sizeof(arr[0]);

    int target = 7;
    cout<<search(arr, n, target);

    cout<<endl;
}