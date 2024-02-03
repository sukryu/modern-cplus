// 여러 수를 인자로 받는 최소 함수 작성하기.

#include <iostream>
#include <functional>

template <class Compare, typename T>
T mininumc(Compare comp, T const a, T const b)
{ return comp(a, b) ? a : b; }

template <class Compare, typename T, typename... Args>
T mininumc(Compare comp, T a, Args... args) {
    return mininumc(comp, a, mininumc(comp, args...));
}


int main() {
    auto y = mininumc(std::less<>(), 3, 2, 1, 0);
    std::cout << y << std::endl;
    return 0;
}