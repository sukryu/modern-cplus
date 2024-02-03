/*
- 파이 값 계산 프로그램 구현하기.
*/

#include <iostream>
#include <random>
#include <cmath>
#include <array>
#include <algorithm>

template <typename E = std::mt19937,
          typename D = std::uniform_real_distribution<>>
double compute_pi(E& engine, D& dist, int const samples = 100000000) {
    auto hit = 0;
    for (auto i = 0; i < samples; ++i) {
        auto x = dist(engine);
        auto y = dist(engine);
        if (y <= std::sqrt(1 - std::pow(x, 2))) hit += 1;
    }
    return 4.0 * hit / samples;
}

int main() {
    std::random_device rd;
    auto seed_data = std::array<int, std::mt19937::state_size> {};
    std::generate(seed_data.begin(), seed_data.end(), std::ref(rd)); // std::ref를 사용하여 rd를 참조로 전달
    std::seed_seq seq(std::begin(seed_data), std::end(seed_data)); // seed_data를 사용하여 seed_seq를 생성
    auto eng = std::mt19937{ seq }; // seed_seq를 사용하여 mt19937을 초기화
    auto dist = std::uniform_real_distribution<>{ 0, 1 }; // 0부터 1 사이의 실수 분포

    // 파이 값을 10번 계산하여 출력
    for (auto j = 0; j < 10; j++) {
        std::cout << "Approximation of Pi: " << compute_pi(eng, dist) << std::endl;
    }
    return 0;
}
