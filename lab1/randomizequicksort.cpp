#include <iostream>
#include <cstdlib>

using namespace std;

// Function to swap two elements
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Function to partition the array
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Function to choose a random pivot and partition the array
int randomPartition(int arr[], int low, int high)
{

    int randomIndex = low + rand() % (high - low + 1);
    swap(arr[randomIndex], arr[high]);
    return partition(arr, low, high);
}

// Function to perform Randomized Quicksort
void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = randomPartition(arr, low, high);
        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
}

// Function to print the array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{

    int size;
    cin >> size;
    int arr[size];
    for (int x = 0; x < size; x++)
    {
        cin >> arr[x];
    }
    cout << "Original array: ";
    printArray(arr, size);
    quicksort(arr, 0, size - 1);
    cout << "Sorted array: ";
    printArray(arr, size);

    return 0;
}