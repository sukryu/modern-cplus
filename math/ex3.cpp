// 최소공배수 프로그램 작성.

#include <iostream>
#include <numeric>
#include <vector>

int lcm(int const a, int const b) {
    int h = std::gcd(a, b);
    return h ? (a * (b / h)) : 0;
}

template<typename InputIt>
int lcmr(InputIt first, InputIt last) {
    return std::accumulate(first, last, 1, [](int a, int b) {
        return lcm(a, b);
    });
}

int main() {
    std::vector<int> numbers = {4, 6, 8};
    std::cout << "LCM: " << lcmr(numbers.begin(), numbers.end()) << std::endl;
    return 0;
}
