#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

const int NUMBERS_SIZE = 50000;
int arr1[NUMBERS_SIZE];
int arr2[NUMBERS_SIZE];
int arr3[NUMBERS_SIZE];
int arr4[NUMBERS_SIZE];

#define midpoint 1
#define medianofthree 2

const int CLOCKS_PER_MS = CLOCKS_PER_SEC/1000;

int genRandInt(int low, int high)
{
   return low + rand() % (high - low + 1);
}
void fillArrays(int arr1[], int arr2[], int arr3[], int arr4[])
{
    for(int i = 0; i < NUMBERS_SIZE; ++i){
        arr1[i] = genRandInt(0,NUMBERS_SIZE);
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
        arr4[i] = arr1[i];
    }
}

void Quick_sort(int numbers[], int i, int k, int type)
{
    if(i >= k)
        return;
    int m, p, l, h;
    m = (i+k)/2;
    if(type == medianofthree)
    {
        if(numbers[i] > numbers[k])
            swap(numbers[i],numbers[k]);
        if(numbers[m] < numbers[i])
            m = i;
        else if(numbers[m] > numbers[k])
            m = k;
    }
    p = numbers[m];
    l = i;
    h = k;
    while(1)
    {
        while(numbers[l] < p)
            l++;
        while(p < numbers[h])
            h--;
        if(l >= h)
            break;
        swap(numbers[l],numbers[h]);
        l++;
        h--;
    }
    Quick_sort(numbers, i, h, type);
    Quick_sort(numbers, h+1, k, type);
}
void Quicksort_midpoint(int numbers[], int i, int k)
{
    Quick_sort(numbers, i, k, midpoint);
}
void Quicksort_medianOfThree(int numbers[], int i, int k)
{
    Quick_sort(numbers, i, k, medianofthree);
}

void InsertionSort(int numbers[], int numbersSize)
{
    int i, j;
    for(i = 1; i < numbersSize; i++)
        for(j = i; j > 0 && numbers[j] < numbers[j-1]; j--)
            swap(numbers[j],numbers[j-1]);
}

void MaxHeapPercolateDown(int i, int numbers[], int numbersSize)
{
    int l, r, mx;
    while(i < numbersSize)
    {
        l = 2*i+1;
        if(l >= numbersSize)
            return;
        mx = max(numbers[i], numbers[l]);
        r = 2*i+2;
        if(r < numbersSize)
            mx = max(mx, numbers[r]);
        if(mx == numbers[i])
            return;
        if(mx == numbers[l])
        {
            swap(numbers[i], numbers[l]);
            i = l;
        }
        else
        {
            swap(numbers[i], numbers[r]);
            i = r;
        }
    }
}
void HeapSort(int numbers[], int numbersSize)
{
    int i;
    for(i = numbersSize/2-1; i >= 0; i--)
        MaxHeapPercolateDown(i, numbers, numbersSize);
    for(i = numbersSize-1; i > 0; i--)
    {
        swap(numbers[i],numbers[0]);
        MaxHeapPercolateDown(0, numbers, i);
    }
}

void print(int numbers[], int numbersSize)
{
    for(int i = 0; i < numbersSize; i++)
        printf("%d%c", numbers[i], i == numbersSize-1 ? '\n' : ' ');
}

int main()
{
    srand(time(NULL));
    fillArrays(arr1, arr2, arr3, arr4);

    clock_t Start, End;
    int elapsedTime_midpoint, elapsedTime_medianOfThree, elapsedTime_Insertion, elapsedTime_Heap;

    Start = clock();
    Quicksort_midpoint(arr1, 0, NUMBERS_SIZE-1);
    End = clock();
    elapsedTime_midpoint = (End - Start)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
    //print(arr1,NUMBERS_SIZE);
    cout << "Quicksort_midpoint: " << elapsedTime_midpoint << endl;

    Start = clock();
    Quicksort_medianOfThree(arr2, 0, NUMBERS_SIZE-1);
    End = clock();
    elapsedTime_medianOfThree = (End - Start)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
    //print(arr2,NUMBERS_SIZE);
    cout << "Quicksort_medianOfThree: " << elapsedTime_medianOfThree << endl;

    Start = clock();
    InsertionSort(arr3, NUMBERS_SIZE);
    End = clock();
    elapsedTime_Insertion = (End - Start)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
    //print(arr3,NUMBERS_SIZE);
    cout << "InsertionSort: " << elapsedTime_Insertion << endl;

    Start = clock();
    HeapSort(arr4, NUMBERS_SIZE);
    End = clock();
    elapsedTime_Heap = (End - Start)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
    //print(arr4,NUMBERS_SIZE);
    cout << "HeapSort: " << elapsedTime_Heap << endl;

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << endl;

    Start = clock();
    Quicksort_midpoint(arr1, 0, NUMBERS_SIZE-1);
    End = clock();
    elapsedTime_midpoint = (End - Start)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
    //print(arr1,NUMBERS_SIZE);
    cout << "Quicksort_midpoint: " << elapsedTime_midpoint << endl;

    Start = clock();
    Quicksort_medianOfThree(arr2, 0, NUMBERS_SIZE-1);
    End = clock();
    elapsedTime_medianOfThree = (End - Start)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
    //print(arr2,NUMBERS_SIZE);
    cout << "Quicksort_medianOfThree: " << elapsedTime_medianOfThree << endl;

    Start = clock();
    InsertionSort(arr3, NUMBERS_SIZE);
    End = clock();
    elapsedTime_Insertion = (End - Start)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
    //print(arr3,NUMBERS_SIZE);
    cout << "InsertionSort: " << elapsedTime_Insertion << endl;

    Start = clock();
    HeapSort(arr4, NUMBERS_SIZE);
    End = clock();
    elapsedTime_Heap = (End - Start)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
    //print(arr4,NUMBERS_SIZE);
    cout << "HeapSort: " << elapsedTime_Heap << endl;
}
