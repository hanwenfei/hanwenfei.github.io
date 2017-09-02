#include <iostream>
#include "SortTestHelper.h"
#include "SelectionSort.h"

using namespace std;

template<typename T>
void insertionSort(T arr[], int n){

 /*交换方式插入
        for( int j = i ; j > 0 && arr[j] < arr[j-1] ; j -- )
            swap( arr[j] , arr[j-1] );
    }

    return;
}
*/
//赋值方式插入
    for(int i=1; i<n; i++){
       
        T e=arr[i];
        int j;
        for(j=i; j>0 && e<arr[j-1]; j--)
           arr[j]=arr[j-1];
        arr[j] = e;
    }
    return ;
}
int main() {

    int n = 10000;
   // 测试1 一般测试
   cout<<"Test for Random Array, size = "<<n<<", random range [0, "<<n<<"]"<<endl;
   int *arr1 = SortTestHelper::generateRandomArray(n,0,n);
   int *arr2 = SortTestHelper::copyIntArray(arr1, n);

   SortTestHelper::testSort("Insertion Sort", insertionSort,arr1,n);
   SortTestHelper::testSort("Selection Sort", selectionSort,arr2,n);

   delete[] arr1;
   delete[] arr2;

   cout<<endl;


   // 测试2 有序性更强的测试
   cout<<"Test for More Ordered Random Array, size = "<<n<<", random range [0, 3]"<<endl;
   arr1 = SortTestHelper::generateRandomArray(n,0,3);
   arr2 = SortTestHelper::copyIntArray(arr1, n);

   SortTestHelper::testSort("Insertion Sort", insertionSort,arr1,n);
   SortTestHelper::testSort("Selection Sort", selectionSort,arr2,n);

   delete[] arr1;
   delete[] arr2;

   cout<<endl;


   // 测试3 测试近乎有序的数组
   int swapTimes = 1;
   cout<<"Test for Random Nearly Ordered Array, size = "<<n<<", swap time = "<<swapTimes<<endl;
   arr1 = SortTestHelper::generateNearlyOrderedArray(n,swapTimes);
   arr2 = SortTestHelper::copyIntArray(arr1, n);

   SortTestHelper::testSort("Insertion Sort", insertionSort,arr1,n);
   SortTestHelper::testSort("Selection Sort", selectionSort,arr2,n);

   delete(arr1);
   delete(arr2);

   return 0;
}