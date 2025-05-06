// Geesaman_Daniel_M2_CSC_222.cpp : This file contains the 'main' function. Program execution begins and ends there.
//This program reverses the constant array created at the inception of the program, and prints the output.

#include <iostream>
using namespace std;

//these are my function prototypes
int* reverseArray(int const arr[], int sizeArr);
void print(int const arr[], int sizeArr);

int main()
{
    int sizeArr = 10;
    int const arr[] = { 1,2,3,4,5,6,7,8,9,10 };

    int* returnFcn = reverseArray(arr, sizeArr);
    print(returnFcn, sizeArr);
}

/*This function accepts my defined constant array and the variable for the size of the array.

The preconditions are that the constant array must be created, and that its size must be greater than 0.

The postcondition is that the constant array has had its contents copied in reverse order to a dynamically created array,
the function then returns a pointer to the newly reversed array.
*/
int* reverseArray(int const arr[], int sizeArr)
{   
    int* revArr = new int[sizeArr];
    int j = sizeArr;
    for (int i = 0; i < sizeArr; i++)
    {
        j--;
        revArr[i] = arr[j];
    }
    
    return revArr;
}

/*
This function recieves the pointer to the reversed array created in the reverseArray function as well as the variable stating 
the length of the original array.

The preconditions of this function are that the pointer from the reversedArray function must have been created and passed into this print function,
and the length of the sizeArr variable must be greater than 0.

The postcondition of this function is that the reversed array will be printed to the screen.
*/
void print(int const arr[], int sizeArr)
{
    for (int i = 0; i < sizeArr; i++)
    {
        cout << *(arr + i) << " ";
    }
}


