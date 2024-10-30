#include <iostream>
#include <stack>
#include <string>

std::string expandString(const std::string& s) {
    std::stack<int> counts;
    std::stack<std::string> patterns;
    std::string result = "";

    int i = 0;
    while (i < s.length()) {
        if (isalpha(s[i])) {
            result += s[i];
            i++;
        } else if (isdigit(s[i])) {
            // Xử lý số lần lặp
            int count = 0;
            while (i < s.length() && isdigit(s[i])) {
                count = count * 10 + (s[i] - '0');
                i++;
            }
            counts.push(count);
        } else if (s[i] == '[') {
            patterns.push(result);
            result = "";
            i++;
        } else if (s[i] == '|') {
            i++;
        } else if (s[i] == ']') {
            std::string pattern = patterns.top();
            patterns.pop();
            int count = counts.top();
            counts.pop();

            for (int j = 0; j < count; j++) {
                pattern += result;
            }
            result = pattern;
            i++;
        }
    }

    return result;
}

int main() {
    std::string input_str = "AB[E[2C]D]";
    std::string output_str = expandString(input_str);
    std::cout << output_str << std::endl;

    return 0;
}
