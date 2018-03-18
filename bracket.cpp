#include <iostream>
#include <stack>
#include <fstream>

char reverseBrackets(char x){
	if(x == '(') return ')';
	if(x == '{') return '}';
	if(x == '[') return ']';
	if(x == ')') return '(';
	if(x == '}') return '{';
	if(x == ']') return '[';
	return x;
}
bool matchBrackets(char x, std::stack<char>& bracket){
	if(x == '(' || x == '{' || x == '['){
		bracket.push(x);
		return true;
	}
	if(x == ')' || x == '}' || x == ']'){
		if(reverseBrackets(x) == bracket.top()){
			bracket.pop();
			return true;
		}
		else{
			return false;
		}
	}
	return true;
}	
int main(){
	std::stack<char> bracket;
	std::ifstream myFile("test.txt");
	bool allCorrect = true;
	if(myFile.is_open()){
		char x;
		while(myFile.get(x)){
			if(!matchBrackets(x, bracket)){
				allCorrect = false;
				break;
			}
		}
		myFile.close();
	}
	if(allCorrect && bracket.size() == 0) std::cout << "All correct." << std::endl;
	else std::cout << "Fail" << std::endl;
	return 0;	
}
