#ifndef INC_03_SELECTION_SORT_GENERATE_TEST_CASES_SORTTESTHELPER_H
#define INC_03_SELECTION_SORT_GENERATE_TEST_CASES_SORTTESTHELPER_H

#include <iostream>
#include <ctime>
#include <cassert>
using namespace std;

namespace SortTestHelper{
    //生成n个元素的随机数组，每个元素的随机范围为[rangeL,rangeR]
    int* generateRandomArray(int n,int rangeL,int rangeR){
        
        assert(rangeR>=rangeL);

        int *arr =new int[n];

        srand(time(NULL));
        for(int i=0;i < n; i++)
            arr[i]=rand() % (rangeR-rangeL+1) +rangeL;
        return arr;
    }
//生成n个元素的近乎有序的数组，先生成有序数组然后选择交换次数n进行交换
    int *generateNearlyOrderedArray(int n,int swapTimes){
        int *arr = new int [n];
        for(int i=0; i<n; i++)
            arr[i]=i;
        srand(time(NULL));
        for(int i=0;i<swapTimes;i++){
            int posx=rand()%n;
            int posy=rand()%n;
            swap(arr[posx],arr[posy]);
        }
        return arr;
    }


    template<typename T>
    void printArray(T arr[],int n){
        for (int i=0;i<n; i++)
            cout << arr[i] << " ";
        cout << endl;

        return;
    }

    template <typename T>
    bool isSorted(T arr[],int n){

        for(int i=0;i<n-1;i++)
            if (arr[i] > arr[i+1])
                return false;
        return true;
    }

    int *copyIntArray(int a[],int n){
        int *arr=new int[n];
        copy(a,a+n,arr);
        return arr;
    }

    template <typename T>
    void testSort(const string &sortName, void (*sort)(T[],int),T arr[],int n){
        clock_t startTime=clock();
        sort(arr,n);
        clock_t endTime=clock();

        assert(isSorted(arr,n));
        cout <<sortName <<" : "<< double(endTime-startTime)/CLOCKS_PER_SEC << " s"<<endl;
        
        return;
    }

};


#endif