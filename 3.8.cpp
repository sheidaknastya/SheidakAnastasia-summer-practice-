#include <iostream>

unsigned long long powerOfTwo(int n) {
    if (n == 0)
        return 1;

    return 2 * powerOfTwo(n - 1);
}

int main() {
    int n;

    std::cout << "Введите значение n (до 63): ";
    std::cin >> n;

    if (n < 0 || n > 63) {
        std::cout << "n должно быть от 0 до 63, иначе произойдет переполнение." << std::endl;
        return 1;
    }

    unsigned long long result = powerOfTwo(n);
    std::cout << "2^" << n << " = " << result << std::endl;

    return 0;
}
