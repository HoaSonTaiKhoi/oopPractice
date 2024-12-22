#include <stdio.h>
#include <iostream>
#include <stack>

int  check_dau(char input)
{
    if(input=='+' || input=='-' || input=='*' || input=='/' || input=='^' || input=='sqrt') return 1;
    return 0;
}


float convertUSDToVND(float usd) {
    if (usd == 1) return 20000;
    if (usd == 2) return 20500;
    if (usd == 5) return 21000;
    if (usd == 10) return 21500;
    if (usd == 20) return 22000;
    if (usd == 50) return 23000;
    if (usd == 100) return 24000;

    return usd * 24000; // Trường hợp không tìm thấy tỷ giá, áp dụng tỷ giá 24000 cho mọi giá trị khác
}

int main() {
    int n, i;

    std::stack<float> num;
    std::stack<char> dau;
    
    // Chuyển đổi kết quả sang VND
    float resultVND = convertUSDToVND(resultUSD);

    // In kết quả
    printf("Ket qua cua phep tinh = %f USD = %f VND\n", resultUSD, resultVND);

    return 0;
}