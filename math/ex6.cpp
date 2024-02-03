// 과잉수 출력 프로그램 구현하기.
/*
- 과잉수 또는 초과수는 진약수 들의 합이 수 자신보다 작은 수를 말한다.
- 어떤 수의 진약수란 그 수 자신을 제외한 양의 양수를 의미한다.
- 어떤 수의 진약수들의 합이 그 수를 초과하는 양을 과잉이라고 한다.
*/

#include <iostream>
#include <cmath>

int sum_proper_divisors(int const number) {
    int result = 1;
    for (int i = 2; i < std::sqrt(number); i++) {
        if (number % i == 0) {
            result += (i == (number / i)) ? i : (i + number / i);
        }
    }
    return result;
}

void print_abundant(int const limit) {
    for (int number = 10; number <= limit; ++number) {
        auto sum = sum_proper_divisors(number);
        if (sum > number) {
            std::cout << number << ", abundant = " << sum - number << std::endl;
        }
    }
}

int main() {
    int limit = 0;
    std::cout << "Upper limit: ";
    std::cin >> limit;

    print_abundant(limit);
    return 0;
}