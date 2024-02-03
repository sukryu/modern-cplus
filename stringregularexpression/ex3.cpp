// 문자열을 제목 형식으로 바꾸기

#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <cassert>

template <class Elem>
using tstring = std::basic_string<Elem, std::char_traits<Elem>, std::allocator<Elem>>;

template <class Elem>
using tstringstream = std::basic_stringstream<Elem, std::char_traits<Elem>, std::allocator<Elem>>;

template <class Elem>
tstring<Elem> capitalize(tstring<Elem> const &text) {
    tstringstream<Elem> result;
    bool newWord = true;

    for (auto const ch : text) {
        if (std::ispunct(ch) || std::isspace(ch)) {
            newWord = true;
            result << ch;
        } else if (std::isalpha(ch)) {
            if (newWord) {
                result << static_cast<Elem>(std::toupper(ch));
                newWord = false;
            } else {
                result << static_cast<Elem>(std::tolower(ch));
            }
        } else {
            result << ch;
        }
    }

    return result.str(); // `return`을 루프 밖으로 옮김
}

int main() {
    using namespace std::string_literals;
    assert("The C++ Challenger"s == capitalize("the c++ challenger"s));
    assert("This Is An Example, Should Work!"s == capitalize("THIS IS an Example, should wORK!"s));
}
