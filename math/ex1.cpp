#include <iostream>

int main() {

    unsigned int limit = 0;
    std::cout << "Upper lilmit: ";
    std::cin >> limit;

    unsigned long long sum = 0;
    for (unsigned int i = 3; i < limit; ++i) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }

    std::cout << "sum = : "<< sum << std::endl;

    return 0;
}

// 3이나 5로 나누어 떨어지는 자연수의 합을 계산하는 프로그램.