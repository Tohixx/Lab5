#include <iostream>
#include <stdio.h>
#include <vector>
#include <list>
#include <sstream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;


string convertToString(char a)
{
	string s = "";
	s = s + a;
	return s;
}

bool in_array(string *my_array, string findthis) {
	int len = sizeof my_array;
	for (int i = 0;i < len;i++) {
		if (my_array[i] == findthis) {
			return true;
		}
	}
	return false;
}

int main()
{
	string userInput = "-h -hvl -hhh --version";
	string commands[2][3] = {
		{"help", "version", "list"},
		{"h","v","l"}
	};

	//spliter for userInput
	list<string> result;
	list<string> result2;
	list<string> result3;
	istringstream iss(userInput);

	for (string s; iss >> s;) {
		//x[0] == "-"
		if (s[0] == '-' && sizeof s >= 2) {
			int counter = count(s.begin(), s.end(), '-');
			if (counter >= 1 && counter <= 2) {
				result.push_back(s);
			}
		}
	}
	for (auto v : result) {
		int counter = count(v.begin(), v.end(), '-');
		if (counter == 1 && bool(in_array(commands[1], convertToString(v[1])))) {
			v = v.substr(1, v.length() - 1);
		} else if (counter == 2 && bool(in_array(commands[0], v.substr(2, v.length() - 1)))) {
			v = v.substr(2, 1);
		}
		result2.push_back(v);
	}

	string st = "";
	
	for (auto v : result2) {
		st += v;
	}

	set<char> setsk(begin(st), end(st));
	string answer; 
 
	for(auto i : setsk){
		switch (i) {
			case 'h':
			{
				answer = "Had been used 'help' command";
				break;
			}
			case 'v':
			{
				answer = "Had been used 'version' command";
				break;
			}
			case 'l':
			{
				answer = "Had been used 'list' command";
				break;
			}
			default:
				answer = "Unknown command";		
		} 
	cout << answer << endl;
	}

	return 0;
}
