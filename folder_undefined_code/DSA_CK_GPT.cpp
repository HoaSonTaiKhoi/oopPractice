#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Hàm để tìm tổng giá trị lớn nhất của 4 món quà khác nhau
int maxGiftValue(vector<int> &prices, int N, int X, vector<int> &gifts) {
    // Tạo một mảng 2 chiều để lưu giá trị tối ưu của các bộ phận con
    // dp[i][j] là giá trị lớn nhất có thể đạt được khi chọn i món quà từ j mặt hàng đầu tiên
    vector<vector<int>> dp(5, vector<int>(N + 1, 0));

    // Tạo một mảng 2 chiều để lưu lại các chỉ số của các món quà được chọn
    // choice[i][j] là chỉ số của món quà thứ i được chọn khi chọn i món quà từ j mặt hàng đầu tiên
    vector<vector<int>> choice(5, vector<int>(N + 1, -1));

    // Duyệt qua các bộ phận con
    for (int i = 1; i <= 4; i++) { // Số lượng món quà
        for (int j = i; j <= N; j++) { // Số lượng mặt hàng
            // Nếu không chọn mặt hàng thứ j, giá trị tối ưu bằng với bộ phận con trước đó
            dp[i][j] = dp[i][j - 1];
            choice[i][j] = choice[i][j - 1];

            // Nếu chọn mặt hàng thứ j, kiểm tra xem có vượt quá khả năng chi trả không
            if (prices[j - 1] <= X) {
                // Nếu có, cập nhật giá trị tối ưu nếu nó lớn hơn giá trị hiện tại
                if (dp[i - 1][j - 1] + prices[j - 1] > dp[i][j]) {
                    dp[i][j] = dp[i - 1][j - 1] + prices[j - 1];
                    choice[i][j] = j - 1; // Lưu lại chỉ số của món quà được chọn
                }
            }
        }
        // Giảm số tiền còn lại sau mỗi lần chọn một món quà
        X -= dp[i][N];
    }

    // Nếu không thể chọn được 4 món quà, trả về -1
    if (dp[4][N] == 0) return -1;

    // Ngược lại, trả về tổng giá trị lớn nhất và lưu lại các chỉ số của các món quà vào vector gifts
    int i = 4, j = N;
    while (i > 0 && j > 0) {
        if (choice[i][j] != choice[i][j - 1]) {
            gifts.push_back(choice[i][j]);
            j = choice[i][j];
            i--;
        } else {
            j--;
        }
    }
    sort(gifts.begin(), gifts.end()); // Đảo ngược thứ tự của các chỉ số
    return dp[4][N];
}

int main() {
    int N, X; // Số lượng mặt hàng và số tiền có thể chi tối đa
    cin >> N >> X;
    vector<int> prices(N); // Mảng lưu giá của các mặt hàng
    for (int i = 0; i < N; i++) {
        cin >> prices[i];
    }
    vector<int> gifts; // Vector lưu các chỉ số của các món quà được chọn
    int ans = maxGiftValue(prices, N, X, gifts); // Tổng giá trị lớn nhất của 4 món quà
    if (ans == -1) { // Nếu không thể chọn được 4 món quà
        cout << "Impossible" << endl;
    } else { // Ngược lại, in ra kết quả
        cout << ans << endl;
        for (int i = 0; i < 4; i++) {
            cout << gifts[i] + 1 << " "; // Cộng 1 vì chỉ số bắt đầu từ 0
        }
        cout << endl;
    }
    return 0;
}