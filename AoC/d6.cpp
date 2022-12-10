#include <bits/stdc++.h>
using namespace std;
int score = 0;


void calculate(string a) {
    for (int i = 0; i < a.length() - 13; i++) {
        set<char> s;
        string word = a.substr(i,14);
        for (char c : word) {
            s.insert(c);
        }
        if (s.size() == 14) {
            cout << i+14 << endl;
            return;
        }
    }    
}




int main() {
	while (true) {
		string input;
		getline(cin, input);
		if (input == "q" || input == "") {
			cout << score;
            return 0;
		}
        calculate(input);
	}
	return 0;
}
