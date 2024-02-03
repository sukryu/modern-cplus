/*
- 범위 안에 있는 IPv4 주소 열거하기.
- 주어진 범위 안에서 IPv4 주소를 열거하려면 먼저 IPv4 값들을 비교할 수 있어야 하므로
- 적어도 < 연산자를 구현할 필요가 있다.
*/

#include <iostream>
#include <array>
#include <sstream>

class ipv4 {
    std::array<unsigned char, 4> data;

public:
    constexpr ipv4() : data{{0}} {}
    constexpr ipv4(unsigned char const a, unsigned char const b,
                    unsigned char const c, unsigned char const d): data{{a, b, c, d}} {}

    explicit constexpr ipv4(unsigned long a) : data{ 
        {static_cast<unsigned char>((a >> 24) & 0xFF),
         static_cast<unsigned char>((a >> 16) & 0xFF),
         static_cast<unsigned char>((a >> 8) & 0xFF),
         static_cast<unsigned char>(a & 0xFF)} } {}

    ipv4(ipv4 const & other) noexcept : data(other.data) {}
    ipv4& operator=(ipv4 const & other) noexcept {
        if (this != &other) { // 자기 자신에 대한 대입 연산을 방지
            data = other.data;
        }
        return *this;
    }

    std::string to_string() const {
        std::stringstream sstr;
        sstr << *this;
        return sstr.str();
    }

    constexpr unsigned long to_ulong() const noexcept {
        return (static_cast<unsigned long>(data[0] << 24) |
                static_cast<unsigned long>(data[1] << 16) |
                static_cast<unsigned long>(data[2] << 8) |
                static_cast<unsigned long>(data[3]));
    }

    friend std::ostream& operator<<(std::ostream& os, const ipv4& a) {
        os << static_cast<int>(a.data[0]) << '.'
           << static_cast<int>(a.data[1]) << '.'
           << static_cast<int>(a.data[2]) << '.'
           << static_cast<int>(a.data[3]);
        return os;
    }

    friend std::istream& operator>>(std::istream& is, ipv4& a) {
        char d1, d2, d3;
        int b1, b2, b3, b4;
        is >> b1 >> d1 >> b2 >> d2 >> b3 >> d3 >> b4;
        if (d1 == '.' && d2 == '.' && d3 == '.' && b1 <= 255 && b2 <= 255 && b3 <= 255 && b4 <= 255) {
            a = ipv4(static_cast<unsigned char>(b1), static_cast<unsigned char>(b2),
                     static_cast<unsigned char>(b3), static_cast<unsigned char>(b4));
        } else {
            is.setstate(std::ios_base::failbit);
        }

        return is;
    }

    ipv4& operator++() {
        *this = ipv4(1 + to_ulong());
        return *this;
    }

    ipv4& operator++(int) {
        ipv4 temp(*this);
        ++(*this);
        return temp;
    }

    friend bool operator==(ipv4 const & a1, ipv4 const & a2) noexcept {
        return a1.data == a2.data;
    }

    friend bool operator!=(ipv4 const & a1, ipv4 const & a2) noexcept {
        return !(a1 == a2);
    }

    friend bool operator<(ipv4 const & a1, ipv4 const & a2) noexcept {
        return a1.to_ulong() < a2.to_ulong();
    }

    friend bool operator>(ipv4 const & a1, ipv4 const & a2) noexcept {
        return a2 < a1;
    }

    friend bool operator<=(ipv4 const & a1, ipv4 const & a2) noexcept {
        return !(a1 > a2);
    }

    friend bool operator>=(ipv4 const & a1, ipv4 const & a2) noexcept {
        return !(a1 < a2);
    }
};

int main() {
    std::cout << "input range: ";
    ipv4 a1, a2;
    std::cin >> a1 >> a2;
    if (a2 > a1) {
        for (ipv4 a = a1; a <= a2; a++) {
            std::cout << a << std::endl;
        }
    } else {
        std::cerr << "invalid range!" << std::endl;
    }
}