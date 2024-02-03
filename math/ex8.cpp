// 암스트롱 수 출력 프로그램 구현하기.
/*
- 나르시스트 수, 완전 자릿수 불변, 플러스 완전수 등의 다른 이름으로도 불리는
- 암스트롱 수의 자릿수 각각을 전체 자릿수만큼 제곱한 것의 합이 자신과 같은 수를 말한다.
- 가장 작은 암스트롱 수는 153이다.
*/

#include <iostream>

void print_narcissistics(bool const printResults) {
    for (int a = 1; a <= 9; a++) {
        for (int b = 0; b <= 9; b++) {
            for (int c = 0; c <= 9; c++) {
                auto abc = a * 100 + b * 10 + c;
                auto arm = a * a * a + b * b * b + c * c * c;
                if (abc == arm) {
                    std::cout << arm << std::endl;
                }
            }
        }
    }
}

int main() {
    int num = 10000;
    print_narcissistics(num);
    return 0;
}