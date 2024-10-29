#include <iostream>
#include <vector>

using namespace std;

void backtrack(const vector<char>& S, vector<char>& current_combination, int start) {
    // Nếu hiện tại đã chọn đủ 6 ký tự, in ra kết quả
    if (current_combination.size() == 6) {
        for (char c : current_combination) {
            cout << c;
        }
        cout << endl;
        return;
    }

    // Duyệt qua các ký tự trong S bắt đầu từ vị trí 'start'
    for (int i = start; i < S.size(); i++) {
        current_combination.push_back(S[i]);  // Thêm ký tự vào kết quả hiện tại
        backtrack(S, current_combination, i + 1);  // Tiếp tục với ký tự tiếp theo
        current_combination.pop_back();  // Loại bỏ ký tự cuối cùng để thử các khả năng khác
    }
}

int main() {
    vector<char> S = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    vector<char> current_combination;

    backtrack(S, current_combination, 0);

    return 0;
}
