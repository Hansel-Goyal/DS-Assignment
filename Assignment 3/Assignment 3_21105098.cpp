#include <iostream>
using namespace std;

/*
HANSEL GOYAL
21105098
ECE 
*/

/*
QUESTION 1

SOLUTION: We can search an element in an array whose size is unknown in O(logn) time complexity provided that the array is in sorted order (here i am taking case of ascending order).We can do this by making some modification in binary search technique.

The concept behind this approach is:
  ->Take inital value of i as 0 and j as 1.
  ->Now increase j to j*2 until arr[j] exceed the key to be searched.
  ->Now search the key using binary search between i and j.
*/

// Simple Binary Search Function
int binary_search(int arr[], int i, int j, int key)
{
    int p = (i + j) / 2;
    while (i <= j)
    {
        if (arr[p] == key)
        {
            return p;
        }
        else
        {
            if (arr[p] < key)
            {
                i = p + 1;
            }
            else
            {
                j = p - 1;
            }
        }
        p = (i + j) / 2;
    }
    return -1;
}

// Enhanced binary search function or Binary search for array with unknown lenght

int binary_search_unknown(int arr[], int key)
{
    int i = 0, j = 1; // Initializing i as 0 and j as 1.
    while (arr[j] < key)
    {
        i = j;
        j = 2 * j;
    }
    return binary_search(arr, i, j, key); // Now calling Simple Binary Search on range i to j.
}
