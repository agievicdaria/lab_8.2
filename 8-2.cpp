#include <iostream>
#include <string>
using namespace std;
size_t MaxLength(const string s) {
    int k = 0;
    size_t len = 0,
           max;
    size_t start = 0,
           finish;
    while ((start = s.find_first_of(" ", start)) != -1) {
        finish = s.find_first_not_of(" ", start + 1);
        if (finish == -1)
            finish = s.length();
        len = finish - start;
        if (k == 0)
            max = len;
        k++;
        if (len > max)
            max = len;
        start = finish + 1;
    }
    return max;
}
int main() {
    string str;
    cout << "Enter string:" << endl;
    getline(cin, str);
    cout << "Length of max groups of gaps: " << MaxLength(str) << endl;
    return 0;
}