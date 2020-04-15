/*
Minimum bracket Reversal

Given a string expression which consists only ‘}’ and ‘{‘. The expression may not be balanced. You need to find the minimum number of bracket reversals which are required to make the expression balanced.
Return -1 if the given expression can't be balanced.

Input Format :
String S

Output Format :
Required count

Sample Input 1 :
{{{
	
Sample Output 1 :
-1

Sample Input 2 :
{{{{}}

Sample Output 2 :
1
*/

#include <iostream>
#include <stack>
using namespace std;

int length(char input[]) {
    int len = 0;
    for(int i = 0; input[i] != '\0'; i++) {
        len++;
    }
    return len;
}

int countBracketReversals(char input[]){
	int len = length(input);
	if(len == 0){
		return 0;
	}
	if(len % 2 != 0){
		return -1;        // reversal isn't possible
	}
	stack<char> stack;
	for(int i = 0; i < len; i++){
		char currentChar = input[i];
		if(currentChar == '{'){
			stack.push(currentChar);
		}else{
			// pop if there is a balanced pair
			if(!stack.empty() && stack.top() == '{'){
				stack.pop();
			}else{
				stack.push(currentChar);
			}
		}
	}

	int count = 0;

	// only unbalanced brackets are there in stack now
	while(!stack.empty()){
		char char1 = stack.top();
        stack.pop();
		char char2 = stack.top();
        stack.pop();
		// when char1 = } and char2 = {, then we need to reverse both of them so count will increase by 2
		if(char1 != char2){
			count += 2;
		}else{
			count += 1;
		}
	}
	return count;
}

int main() {
    char input[10000];
    cin >> input;
    cout << countBracketReversals(input) << endl;
}
