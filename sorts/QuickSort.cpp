#include <iostream>
#include <vector>
#include <random>

std::mt19937 generator(207);

std::vector<int> partition(std::vector<int>& arr, int pivot, int begin, int end){
    int l = 0, m = 0, r = 0;
    for(int k = begin; k < end; ++k){
        if(arr[k] < pivot){++l;}
        if(arr[k] == pivot){++m;}
        if(arr[k] > pivot){++r;}
    }

    int i = begin;
    int j = end-1;
    while(i < j){
        if(arr[i] < pivot) {++i;}
        else{std::swap(arr[i], arr[j]);j--;}
    }

    i = begin + l;
    j = end - 1;

    while(i < j){
        if(arr[j] == pivot){std::swap(arr[i], arr[j]);i++;}
        else{j--;}
    }

    return {l, m, r}; // размеры массивов L, M, R
}

void QuickSort(std::vector<int>& arr, int begin, int end){
    if(end - begin <= 1){return;}
    std::uniform_int_distribution<int> distr(begin, end-1);
    int index = distr(generator);
    int pivot = arr[index];

    std::vector<int> sizes(3);
    sizes = partition(arr, pivot, begin, end);

    QuickSort(arr, begin, begin + sizes[0]);
    QuickSort(arr, end - sizes[2], end);
}

void QuickSort(std::vector<int>& arr){
    QuickSort(arr, 0, arr.size());
}

int main(){
    std::vector<int> arr = {2, 3, 6, 1, 8, 9, 7, -1, -11, 100, 1,10,10,10,10,10,10,100,1000,100,1000,100};
    QuickSort(arr);
    for(auto el: arr)
        std::cout <<  el << ' ';
    std::cout << '\n';
}