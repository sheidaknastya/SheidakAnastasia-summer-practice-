#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void generateSortedArray(int arr[], int n) {
    arr[0] = rand() % 5;
    for (int i = 1; i < n; ++i) {
        arr[i] = arr[i - 1] + rand() % 4;  
    }
}

void distortArray(int arr[], int n) {
    int distortCount = n / 10;
    for (int i = 0; i < distortCount; ++i) {
        int index = 1 + rand() % (n - 2); 

        if (rand() % 2 == 0) {
            arr[index] ^= arr[index - 1];
            arr[index - 1] ^= arr[index];
            arr[index] ^= arr[index - 1];
        } else {
            arr[index] ^= arr[index + 1];
            arr[index + 1] ^= arr[index];
            arr[index] ^= arr[index + 1];
        }
    }
}

int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1; 
}

int main() {
    srand(time(0));

    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    if (n < 2) {
        cout << "Размер массива должен быть >= 2.\n";
        return 1;
    }

    int* arr = new int[n];
    generateSortedArray(arr, n);

    cout << "\nИсходный отсортированный массив:\n";
    for (int i = 0; i < n; ++i) cout << arr[i] << " ";
    cout << "\n";

    distortArray(arr, n);

    cout << "\nМассив после искажения:\n";
    for (int i = 0; i < n; ++i) cout << arr[i] << " ";
    cout << "\n";

    int value;
    cout << "\nВведите значение для поиска: ";
    cin >> value;

    int result = binarySearch(arr, n, value);

    if (result != -1)
        cout << "Элемент найден по индексу: " << result << "\n";
    else
        cout << "Элемент не найден в массиве.\n";

    delete[] arr;
    return 0;
}
