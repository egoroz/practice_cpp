#include <iostream>
#include <vector>

void merge(std::vector<int>& L, std::vector<int>& R, std::vector<int>& arr){
    int i = 0, j = 0;
    while(i < L.size() || j < R.size()){
        if(j == R.size() || (i < L.size() && L[i] <= R[j])){
            arr[i+j] = L[i];
            ++i;
        }
        else{
            arr[i+j] = R[j];
            ++j;
        }
    }
}

void mergeSort(std::vector<int>& arr){
    if(arr.size() == 1){return;}
    std::vector<int> L(arr.begin(), arr.begin() + arr.size()/2);
    std::vector<int> R(arr.begin() + arr.size()/2, arr.end());
    mergeSort(L);
    mergeSort(R);
    merge(L, R, arr);

}

int main(){
    std::vector<int> arr = {2, 3, 6, 1, 8, 9, 7, 4, 5, 2};
    mergeSort(arr);
    for(auto el: arr)
        std::cout <<  el << ' ';
}