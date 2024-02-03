// 친화수 짝을 출력하는 프로그램 구현하기.
/*
- 한 숫자의 진약수의 합이 다른 수와 같은 두 수를 친화수라고 한다.
- 친화수를 친구수로 혼동해서는 안 된다.
*/

#include <iostream>
#include <cmath>

int sum_proper_divisors(int const number) {
    int result = 1;
    for (int i = 2; i <= std::sqrt(number); i++) {
        if (number % i == 0) {
            result += (i == (number / i)) ? i : (i + number / i);
        }
    }
    return result;
}

void print_amicables(int const limit) {
    for (int number = 4; number < limit; ++number) {
        auto sum1 = sum_proper_divisors(number);
        if (sum1 > number && sum1 < limit) {
            auto sum2 = sum_proper_divisors(sum1);
            if (sum2 == number) {
                std::cout << number << "," << sum1 << std::endl;
            }
        }
    }
}

int main() {
    int limit = 10000;
    print_amicables(limit);
    return 0;
}
