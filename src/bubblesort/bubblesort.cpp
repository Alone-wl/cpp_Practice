/*
* 数组值传递方式
* sizeof(T)
*/
#include <iostream>
#include <stdio.h>

template <class T>
int sizeOfArray(T &array){
    return sizeof(array) / sizeof(array[0]);
}

template <class T>
void swap(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}

void bubblesort(int *a, int size) {//非升排列

    for (bool sorted = false; sorted = !sorted; size--){

        for (int i = 1; i < size; i++){

            if(a[i-1]<a[i]){
                swap(a[i - 1], a[i]);
                sorted = false;
            }
        }
    }
}

void reverse(int* A, int lo, int hi){

    if(hi >= lo){
        swap(A[lo], A[hi]);
        reverse(A, ++lo, --hi);
    }else {
        return;
    }
}

template <class T>
void printArray(T &a){
    int length = sizeOfArray(a);
    for (int i = 0; i < length; i++){
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

int main(){
    int a[] = {3, 6, 7, 2, 0, 5, 8, 4, 8, 30, 4, 45};
    printArray(a);

    bubblesort(a, sizeOfArray(a));   //冒泡排序
    printArray(a);

    reverse(a, 0, sizeOfArray(a)-1);   //数组倒置
    printArray(a);

    while(getchar() != 'b');
    return 0;
}