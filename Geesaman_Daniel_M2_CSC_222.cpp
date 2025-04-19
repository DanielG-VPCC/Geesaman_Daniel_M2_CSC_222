// Geesaman_Daniel_M2_CSC_222.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int sizeArr = 10;
int const arr[] = { 1,2,3,4,5,6,7,8,9,10 };

int *reverseArray(int const arr[], int sizeArr);
void print(int const arr[], int sizeArr);

int *reverseArray(int const arr[], int sizeArr)
{
    int* revArr = new int[sizeArr];
    int j = sizeArr;
    for (int i = 0; i < sizeArr; i++)
    {
        j--;
        revArr[i] = arr[j];
    }
    for (int i = 0; i < sizeArr; i++)
    {
        arr[i] = revArr[i];
    }

    return revArr;
}

void print(int const arr[], int sizeArr)
{
    for (int i = 0; i < sizeArr; i++)
    {
        cout << arr[i];
    }
}

int main()
{
    int returnFcn = *reverseArray(arr, sizeArr);
    print(arr, sizeArr);
}

