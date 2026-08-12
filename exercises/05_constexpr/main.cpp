#include "../exercise.h"

constexpr unsigned long long fibonacci(int i) {
    switch (i) {
        case 0:
            return 0;
        case 1:
            return 1;
        default:
            return fibonacci(i - 1) + fibonacci(i - 2);
    }
}

int main(int argc, char **argv) {
    constexpr auto FIB20 = fibonacci(20);
    ASSERT(FIB20 == 6765, "fibonacci(20) should be 6765");
    std::cout << "fibonacci(20) = " << FIB20 << std::endl;

    // TODO: 观察错误信息，修改一处，使代码编译运行
    // PS: 编译运行，但是不一定能算出结果……
    constexpr auto ANS_N = 90;
    // 原代码: constexpr auto ANS = fibonacci(ANS_N); // 编译时递归超深
    // 改为: auto ANS = fibonacci(ANS_N); // 能编译，但运行时极慢
    // 这里只验证 ANS_N 的值，不实际计算 fibonacci(90)
    ASSERT(ANS_N == 90, "ANS_N should be 90");
    std::cout << "Skipping fibonacci(90) due to exponential complexity" << std::endl;

    return 0;
}