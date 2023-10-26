#include <iostream>
#include <vector>

using namespace std;

int linearSearch(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            return i; // Return the index of the found element
        }
    }
    return -1; // Return -1 if the element is not found
}

int binarySearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid; // Return the index of the found element
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // Return -1 if the element is not found
}

int searchWithAlgorithm(const vector<int>& arr, int target, int algorithm) {
    switch (algorithm) {
        case 1:
            return linearSearch(arr, target);
        case 2:
            return binarySearch(arr, target);
        default:
            cout << "Invalid algorithm choice" << endl;
            return -1; // Return -1 for an invalid choice
    }
}

int main() {
    vector<int> data = {11, 22, 25, 34, 64, 90};
    
    cout << "Select a search algorithm:" << endl;
    cout << "1. Linear Search" << endl;
    cout << "2. Binary Search" << endl;
    
    int choice;
    cin >> choice;
    
    int target;
    cout << "Enter the element to search for: ";
    cin >> target;
    
    int result = searchWithAlgorithm(data, target, choice);
    
    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found in the array" << endl;
    }
    
    return 0;
}
