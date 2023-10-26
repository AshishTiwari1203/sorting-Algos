#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void bubbleSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void insertionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void sortWithAlgorithm(vector<int> &arr, int algorithm)
{
    switch (algorithm)
    {
    case 1:
        bubbleSort(arr);
        break;
    case 2:
        selectionSort(arr);
        break;
    case 3:
        insertionSort(arr);
        break;
    default:
        cout << "Invalid algorithm choice" << endl;
    }
}

int main()
{
    vector<int> data = {64, 34, 25, 12, 22, 11, 90};

    cout << "Select a sorting algorithm:" << endl;
    cout << "1. Bubble Sort" << endl;
    cout << "2. Selection Sort" << endl;
    cout << "3. Insertion Sort" << endl;

    int choice;
    cin >> choice;

    sortWithAlgorithm(data, choice);

    cout << "Sorted array: ";
    for (int num : data)
    {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}
