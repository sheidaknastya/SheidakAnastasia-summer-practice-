#include <iostream>
using namespace std;

bool isLatinSquare(int** matrix, int n) {
    for (int i = 0; i < n; ++i) {
        bool* rowCheck = new bool[n](); 
        bool* colCheck = new bool[n]();

        for (int j = 0; j < n; ++j) {
            int rowVal = matrix[i][j];
            int colVal = matrix[j][i];

            if (rowVal < 1 || rowVal > n || colVal < 1 || colVal > n) {
                delete[] rowCheck;
                delete[] colCheck;
                return false;
            }

            if (rowCheck[rowVal - 1] || colCheck[colVal - 1]) {
                delete[] rowCheck;
                delete[] colCheck;
                return false;
            }

            rowCheck[rowVal - 1] = true;
            colCheck[colVal - 1] = true;
        }

        delete[] rowCheck;
        delete[] colCheck;
    }
    return true;
}

int main() {
    int n;
    cout << "Введите размер квадратной матрицы: ";
    cin >> n;

    int** matrix = new int*[n];
    for (int i = 0; i < n; ++i)
        matrix[i] = new int[n];

    cout << "Введите элементы матрицы через пробел (" << n << " x " << n << "):\n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> matrix[i][j];

    if (isLatinSquare(matrix, n))
        cout << "\nМатрица является латинским квадратом.\n";
    else
        cout << "\nМатрица НЕ является латинским квадратом.\n";

    for (int i = 0; i < n; ++i)
        delete[] matrix[i];
    delete[] matrix;

    return 0;
}
