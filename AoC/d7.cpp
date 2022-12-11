    #include <bits/stdc++.h>
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

int sum = 0;
int score = 0;
int main() {
    vector<int> dirs;
	while (true) {
		string input;
		getline(cin, input);
		if (input == "q" || input == "") {
            for (int i = 0; i < dirs.size(); i++) {
                if (dirs[i] < 100000) {
                    cout << dirs[i] << endl;
                    sum+=dirs[i];
                }
            }
			cout << sum;
            return 0;
		}
        
        if (getNumberFromString(input) != -1 && input.find(".") !=  string::npos) {
            score+=getNumberFromString(input);
        } else if (getNumberFromString(input) != -1) {
            score+=getNumberFromString(input);
            dirs.push_back(score);
            score = 0;
        } else {
            dirs.push_back(score);
            score = 0;
        }

	}
    
	return 0;
}
