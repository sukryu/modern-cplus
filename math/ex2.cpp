// 최대공약수 프로그램.

#include <iostream>

// 1. 재귀 함수
unsigned int gcd(unsigned int const a, unsigned int const b) {
    return b == 0 ? a : gcd(b, a % b);
}

// 2. 유클리드 알고리즘의 비재귀적인 구현
unsigned int gcd2(unsigned int a, unsigned int b) {
    while (b != 0) {
        unsigned int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    unsigned int a, b = 0;
    unsigned long long gcdresult = 0;
    unsigned long long gcd2result = 0;
    std::cout << "Input number : ";
    std:: cin >> a, b;

    gcdresult = gcd(a, b);
    std::cout << "gcd : " << gcdresult << std::endl;
    gcd2result = gcd2(a, b);
    std::cout << "gcd2 : " << gcd2result << std::endl;

    return 0;
}