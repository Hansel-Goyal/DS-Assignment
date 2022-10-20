//Hansel Goyal
//ECE
//21105098


// Ans1

/*
An "In-Place" sorting algorithm is an algorithm whose space complexity lies between O(1) and O(logn) both included.
We can say that it is an algorithm that does need a small extra space and produces an output in the same memory that
contains the data by transforming the input ‘in-place’.
Whereas an "Out-Place" sorting algorithm is an algorithm whose space complexity is greater than O(logn).
*/

// Ans2

// Insertion Sort Using In-Place Algorithm
#include <iostream>
using namespace std;

void insertion_sort_IP(int arr[], int n)
{ // Creating Insertion Sort void function
    int i = 0, j = i + 1;
    while (j <= n - 1)
    {
        int temp = arr[j];
        while (i >= 0)
        {
            if (arr[i] > temp)
            {
                arr[i + 1] = arr[i];
                i--;
            }
            if (i == -1)
            {
                arr[0] = temp;
                break;
            }
            if (arr[i] <= temp)
            {
                arr[i + 1] = temp;
                break;
            }
        }
        j++;
        i = j - 1;
    }
    return;
}

// Insertion Sort Using Out-Place Algorithm
void insertion_sort_OP(int arr[], int s, int e)
{
    // s=starting index
    // e=ending index
    if (s == e)
    {
        return;
    }
    int j = s + 1;
    int temp = arr[j];
    while (s >= 0)
    {
        if (arr[s] > temp)
        {
            arr[s + 1] = arr[s];
            s--;
        }
        if (s == -1)
        {
            arr[0] = temp;
            break;
        }
        if (arr[s] <= temp)
        {
            arr[s + 1] = temp;
            break;
        }
    }
    insertion_sort_OP(arr, s + 1, e);
}

// Function to print array
void pfun(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int n;
    cout << "ENTER NUMBER OF ELEMENTS IN THE ARRAY: "; // Taking Input array
    cin >> n;
    int arr[n], arr2[n]; // Two array with same size and elements
    cout << "ENTER ELEMENTS OF ARRAY SEPERATED BY SPACE: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // copying arr to arr2
    for (int i = 0; i < n; i++)
    {
        arr2[i] = arr[i];
    }
    cout << endl;
    cout << "ARRAY BEFORE SORTING : ";
    pfun(arr, n);
    // Calling insertion sort using in-place algorithm.
    insertion_sort_IP(arr, n);
    cout << endl;
    cout << "ARRAY AFTER SORTING USING IN-PLACE ALGORITHM : ";
    // printing the array
    pfun(arr, n);
    cout << endl;
    // calling insertiong sort using out-place algorithm.
    insertion_sort_OP(arr2, 0, n - 1);
    cout << "ARRAY AFTER SORTING USING OUT-PLACE ALGORITHM : ";
    // printing the array
    pfun(arr, n);
    cout << endl;
}

// ANS3

/*
In-place techniques have lesser space complexity but are difficult to
apply in algorithm whereas out-place techniques are easy to aplly but
increases the space complexity of algorithm.
For exapmle if we want to reverse an array then its in-place algorithm
will be swaping the first and last element of array until we reach the
middle of array,If we want to solve the same problem using out-place
algorithm we have to create one extra array of same size and copy
elements of original array from back to the front of new array,this
algorith increases the space complexity to O(n) as we have creaed an
extra array.

IN-PLACE algorithm are used in Bubble sort, Selection Sort, Insertion Sort, Heapsort.
NOT IN-PLACE algorithm is used in Merge Sort, Because merge sort requires O(n) extra space.
*/
