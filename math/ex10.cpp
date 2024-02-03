/*
- 그레이 코드 출력 프로그램 구현하기.
반사 이진 코드이나 반사 이진수로도 알려진 그레이 코드는 연속된 두 수가 오직 한 비트 차이가 나도록
만드는 이진 인코딩 방법이다.

그레이 코드 인코딩을 위해 다음과 같은 공식을 사용한다.
if b[i-1] = i then g[i] = not b[i]

이는 다음과 같다.
g = b xor (오른쪽으로 한 번 논리 쉬프트된 b)

그레이 코드 디코딩을 위해 다음과 같은 공식을 사용한다.
b[0] = g[0]
b[i] = g[i] xor b[i-1]
*/

#include <iostream>
#include <bitset>

unsigned int gray_encode(unsigned int const num) {
    return num ^ (num >> 1);
}

unsigned int gray_decode(unsigned int gray) {
    for (unsigned int bit = 1U << 31; bit > 1; bit >>= 1) {
        if (gray & bit) gray ^= bit >> 1;
    }

    return gray;
}

std::string to_binary(unsigned int value, int const digits) {
    return std::bitset<32>(value).to_string().substr(32 - digits, digits);
}

int main() {
    std::cout << "Number\tBinary\tGray\tDecoded\n";
    std::cout << "------\t------\t------\t------\n";

    for (unsigned int n = 0; n < 32; ++n) {
        auto encg = gray_encode(n);
        auto decg = gray_decode(encg);

        std::cout << n << "\t" << to_binary(n, 5) << "\t" << to_binary(encg, 5) << "\t" << decg << "\n";
    }

    return 0;
}