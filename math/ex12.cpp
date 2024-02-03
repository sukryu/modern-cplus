/*
- 가장 킨 콜라츠 수열 출력 프로그램 구현하기.
- 울람 추측, 카쿠타니의 문제, 스웨이츠 추측, 하스 알고리즘, 시라큐스 문제 등의 이름으로 불리는
- 콜라츠 추측은 다음에 설명하는 수열이 언제나 1에 도달하게 된다는 검증되지 않은 추측이다.
- 이 수열은 다음과 같이 정의된다.

- 어떤 양의 정수 n에서 출발해 이전 항으로부터 다음 항을 산출한다.
- 이전 항이 짝수면 다음 항은 이전 항의 절반이며, 그렇지 않을 경우 다음 항은 이전 항의 값에 세 배를 해 1을 더한 것이 된다.
*/

#include <iostream>
#include <vector>

std::pair<unsigned long long, long> longest_collatz(
    unsigned long long const limit
) {
    long length = 0;
    unsigned long long number = 0;
    std::vector<int> cache(limit + 1, 0);
    for (unsigned long long i = 2; i <= limit; i++) {
        auto n = i;
        long steps = 0;
        while (n != 1 && n >= i)
        {
            if ((n % 2) == 0) n = n / 2;
            else n = n * 3 + 1;
            steps++;
        }
        cache[i] = steps + cache[n];

        if (cache[i] > length) {
            length = cache[i];
            number = i;
        }
    }

    return std::make_pair(number, length);
}

int main() {
    return 0;
}