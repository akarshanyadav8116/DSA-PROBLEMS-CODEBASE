#include<iostream>
#include<stack>
using namespace std;
int precedence(char ch){
	if(ch=='+'||ch=='-'){
		return 1;
	}
	else if(ch=='/'||ch=='*'){
		return 2;
	}
	else if(ch=='^'){
		return 3;
	}
	return 0;
}
void infixtopostfix(string s){
	string res;
	int i=0;
	stack<char> st;
	while(i<s.length()){
		if(s[i]=='('){
			st.push('(');
		}
		else if(st.empty()){
			st.push(s[i]);
		}
		else if(s[i]==')'){
			while(!st.empty()&&st.top()!='('){
				res.push_back(st.top());
				st.pop();
			}
			if(st.empty()){
				cout<<"Invalid String";		
			}
			else{
				st.pop();
			}
		}
		else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='^'){
			if(st.top()!='('&&precedence(s[i])<=precedence(st.top())){
				while(!st.empty()&&precedence(s[i])<=precedence(st.top())){
					res.push_back(st.top());
					st.pop();
				}
				st.push(s[i]);
			}
			else{
				st.push(s[i]);
			}
		}
		else{
			res.push_back(s[i]);
		}
		i++;
	}
	while(!st.empty()){
		res.push_back(st.top());
		st.pop();
	}
	cout<<res;
}
int main(){
	string s="(a+b)/c*d^e*f+g";
	infixtopostfix(s);
	return 0;
}
