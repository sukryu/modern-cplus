/*
- ISBN 검증 프로그램 구현하기.
- 국제표준도서번호는 서적에 부여되는 고유한 식별 번호다.
- 오늘날에는 13자리 형식이 사용되고 있지만. 이 문제에서는 과거게 사용됐던 10자리 형식을 검증해야 한다.
- 마지막 10번째 숫자는 체크섬 역할을 한다.
- 이 자리에 위치하는 수는 ISBN의 10자리 수 모두에 10부터 1까지의 각각의 가중치를 곱해 더한 값이 11의 배수가 되도록 선택된다.
*/

#include <iostream>
#include <string_view>
#include <numeric>
#include <algorithm>
#include <cctype>

bool validate_isbn_10_with_hyphen(std::string_view isbn) {
    int sum = 0;
    int weight = 10;
    int digitCount = 0; // 실제로 사용된 숫자의 개수를 추적

    for (auto ch : isbn) {
        if (std::isdigit(ch)) {
            if (weight < 1) return false; // 숫자가 10개를 초과하면 유효하지 않음
            sum += (ch - '0') * weight--;
            ++digitCount;
        } else if (ch == 'X' && weight == 1) { // 마지막 자리가 'X'인 경우
            sum += 10; // 'X'는 10을 의미
            ++digitCount;
        } else if (ch != '-') {
            return false; // 숫자, 'X', 하이픈 이외의 문자가 있으면 유효하지 않음
        }
    }

    // 모든 조건을 충족하고, 숫자가 정확히 10개 있으며, 합계가 11로 나누어 떨어지는 경우에만 유효
    return digitCount == 10 && sum % 11 == 0;
}

// 하이픈을 무시하고 ISBN-13 번호를 검증하는 함수
bool validate_isbn_13_with_hyphen(std::string_view isbn) {
    int sum = 0;
    size_t digitCount = 0;

    for (size_t i = 0; i < isbn.size(); ++i) {
        if (std::isdigit(isbn[i])) {
            int digit = isbn[i] - '0';
            sum += ((digitCount % 2 == 0) ? digit : digit * 3);
            ++digitCount;
        } else if (isbn[i] != '-') {
            return false; // 하이픈 이외의 잘못된 문자가 있으면 false
        }
    }

    return digitCount == 13 && sum % 10 == 0;
}

int main() {
    std::string_view isbn10 = "3-16-148410-0"; // 하이픈을 포함하는 ISBN-10
    std::cout << "ISBN-10 " << isbn10 << " is " << (validate_isbn_10_with_hyphen(isbn10) ? "valid" : "invalid") << std::endl;

    // ISBN-13 검증은 이전 로직대로 유효함을 이미 확인
    std::string_view isbn13 = "978-0-306-40615-7"; // 하이픈을 포함하는 ISBN-13
    std::cout << "ISBN-13 " << isbn13 << " is " << (validate_isbn_13_with_hyphen(isbn13) ? "valid" : "invalid") << std::endl;

    return 0;
}



