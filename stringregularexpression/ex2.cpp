// 문자열을 바이너리 데이터로 변환하기

#include <iostream>
#include <vector>
#include <string_view>
#include <cassert>
#include <stdexcept>

unsigned char hexchar_to_int(char const ch) {
    if (ch >= '0' && ch <= '9') return ch - '0';
    if (ch >= 'A' && ch <= 'F') return ch - 'A' + 10;
    if (ch >= 'a' && ch <= 'f') return ch - 'a' + 10;
    throw std::invalid_argument("Invalid hexadecimal character");
}

std::vector<unsigned char> hexstr_to_bytes(std::string_view str) {
    if (str.size() % 2 != 0) {
        throw std::invalid_argument("Hexadecimal string must have an even length");
    }
    std::vector<unsigned char> result;

    for (size_t i = 0; i < str.size(); i += 2) {
        result.push_back((hexchar_to_int(str[i]) << 4) | hexchar_to_int(str[i + 1]));
    }
    return result;
}

int main() {
    std::vector<unsigned char> expected{ 0xBA, 0xAD, 0xFD, 0x0D, 0x42 };
    try {
        assert(hexstr_to_bytes("BAADFD0D42") == expected);
        assert(hexstr_to_bytes("BaaDf00d42") == expected);
        std::cout << "Assertions passed." << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Assertion failed: " << e.what() << std::endl;
    }
    return 0;
}
