#include <iostream>
#include <vector>

void generateLatinSquare(int n) {
    std::vector<std::vector<int>> latinSquare(n, std::vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            latinSquare[i][j] = (i + j) % n + 1;
        }
    }

    std::cout << "Латинский квадрат размером " << n << ":\n";
    for (const auto& row : latinSquare) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int n;
    std::cout << "Введите размерность латинского квадрата (n): ";
    std::cin >> n;

    generateLatinSquare(n);

    return 0;
}
