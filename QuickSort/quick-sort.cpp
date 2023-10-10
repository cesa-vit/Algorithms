#include <iostream>
#include <vector>

// Function to partition the array and return the pivot index
int partition(std::vector<int> &arr, int low, int high)
{
    int pivot = arr[high]; // Choose the last element as the pivot
    int i = low - 1;       // Index of the smaller element

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Function to perform Quick Sort
void quickSort(std::vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);

        // Recursively sort elements before and after the pivot
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main()
{
    std::vector<int> arr = {12, 11, 13, 5, 6, 7};

    std::cout << "Original array: ";
    for (int num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    int n = arr.size();
    quickSort(arr, 0, n - 1);

    std::cout << "Sorted array: ";
    for (int num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
