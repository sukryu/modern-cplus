// 섹시 소수 짝을 출력하는 프로그램 작성하기.

/*
- 섹시 소수란 두 수의 차가 6인 소수 쌍을 의미한다.
- 두 수의 차가 2인 쌍둥이 소수라는 것도 있고, 두 수의 차가 4인 사촌 소수도 존재.
*/

#include <iostream>

bool is_prime(int const num) {
    if (num <= 3) { return num > 1; }
    else if (num % 2 == 0 || num % 3 == 0) {
        return false;
    } else {
        for (int i = 5; i * i <= num; i += 6) {
            if (num % i == 0 || num % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }
}

int main() {
    int limit = 0;
    std::cout << "Upper limit: ";
    std::cin >> limit;

    for (int n = 2; n <= limit; n++) {
        if (is_prime(n) && is_prime(n+6)) {
            std::cout << "," << n+6 << std::endl;
        }
    }

    return 0;
}