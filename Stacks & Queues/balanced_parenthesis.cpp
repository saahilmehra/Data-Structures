/*
Balanced Parenthesis

Given a string expression, check if brackets present in the expression are balanced or not. Brackets are balanced if the bracket which opens last, closes first.
You need to return true if it is balanced, false otherwise.
Note: This problem was asked in initial rounds in Facebook

Sample Input 1 :
{ a + [ b+ (c + d)] + (e + f) }

Sample Output 1 :
true

Sample Input 2 :
{ a + [ b - c } ]

Sample Output 2 :
false
*/

#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

bool checkBalanced(char *exp) {
	stack<char> s;
	int len = strlen(exp);
	for(int i = 0; i < len; i++) {
		if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
			s.push(exp[i]);
		}
		else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
			if(s.empty()) {
				return false;
			}
			char ch = s.top();
			s.pop();
			if(exp[i] == ')' && ch == '(') {
				continue;
			}
			else if(exp[i] == '}' && ch == '{') {
				continue;
			}
			else if(exp[i] == ']' && ch == '[') {
				continue;
			}
			else {
				return false;
			}
		}
	}
	if(s.empty()) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
    char input[100000];
    cin.getline(input, 100000);
    if(checkBalanced(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
