#include<iostream>
using namespace std;
int main(){
    int arr[] = {4, 1 , 6, 7, 54, 32, 89, 10, 67};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(arr[i]>arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }   
        }
    }

    for(int x: arr){
        cout<<x<<" ";
    }

    cout<<endl;
}