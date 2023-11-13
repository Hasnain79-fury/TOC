#include <iostream>
#include <string>
using namespace std;

void leftmostDerivation(const string& input) {
    string S = "S";
    string A = "A";
    string B = "B";

    string leftmost = S;
    cout << "Leftmost: " << leftmost;

    for (char c : input) {
        if (c == '0') {
            leftmost.replace(leftmost.find(A), A.length(), "0A");
        } else {
            leftmost.replace(leftmost.find(B), B.length(), "1B");
        }
        cout << " => " << leftmost;
    }

    cout << endl;
}

void rightmostDerivation(const string& input) {
    string S = "S";
    string A = "A";
    string B = "B";

    string rightmost = S;
    cout << "Rightmost: " << rightmost;

    for (char c : input) {
        if (c == '0') {
            size_t posA = rightmost.rfind(A);
            rightmost.replace(posA, A.length(), "0A");
        } else {
            size_t posB = rightmost.rfind(B);
            rightmost.replace(posB, B.length(), "1B");
        }
        cout << " => " << rightmost;
    }

    cout << endl;
}

int main() {
    string input;
    cout << "Input: ";
    cin >> input;

    leftmostDerivation(input);
    rightmostDerivation(input);

    return 0;
}
