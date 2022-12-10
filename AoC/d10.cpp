#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define endl '\n'
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>  
#define vl vector<ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define vvi vector<vi>
#define vvl vector<vl>
using namespace std;

int getNumberFromString(string s) {
   stringstream str_strm;
   str_strm << s; //convert the string s into stringstream
   string temp_str;
   int temp_int;
   while(!str_strm.eof()) {
      str_strm >> temp_str; //take words into temp_str one by one
      if(stringstream(temp_str) >> temp_int) { //try to convert string to int
        //  cout << temp_int << " ";
        return temp_int;
      }
      temp_str = ""; //clear temp string
   }
   return -1;
}

int sum = 1;
int strength = 0;
int instr = 0;
void check(int i) {
    if ( (i - 20) % 40 == 0) {
        strength+=sum*i;
        cout << strength << endl;
    }
}


void solve(string a) {
    
    if (a.substr(0,4) == "noop") {
        instr++;
        check(instr);

    } else if (a.substr(0,4) == "accx") {
        instr++;
        check(instr);
        instr++;
        check(instr);
        sum+=getNumberFromString(a);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    while(true) {
        string input;
        getline(cin, input);
		if (input == "q" || input == "") {
            cout << strength;
            return 0;
		}
        else {
            solve(input);
        }
    }

    return 0;
}
