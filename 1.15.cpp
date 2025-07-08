#include <iostream>
#include <cmath>
#include <vector>

bool isPrime(int num) {
    if (num <= 1) return false; 
    if (num <= 3) return true; 

    if (num % 2 == 0 || num % 3 == 0) return false;

    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    int limit;
    std::cout << "Введите предел (максимальное значение n): ";
    std::cin >> limit;

    int count = 0;

    for (int n = 1; n <= limit; ++n) {
        int squarePrime = n * n + 1;
        if (isPrime(squarePrime)) {
            count++;
            std::cout << "n = " << n << ", " << squarePrime << " является простым числом." << std::endl;
        }
    }

    std::cout << "Количество квадратных простых чисел: " << count << std::endl;

    return 0;
}
