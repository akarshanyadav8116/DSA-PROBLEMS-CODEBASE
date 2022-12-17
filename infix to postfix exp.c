#include<stdio.h>
int main(){
	char s[100];
	char stack[100]={'\0'},output[100]={'\0'};
	int i=0,top=-1,k=0;
	printf("Enter the infix expression :");
	scanf("%s",s);
	while(s[i]!='\0'){
		if(s[i]!='+'&&s[i]!='-'&&s[i]!='/'&&s[i]!='*'&&s[i]!='('&&s[i]!=')'){
			output[k]=s[i];
			k++;
		}
		else if(s[i]=="("){
			stack[top+1]=s[i];
			top++;
		}
		else if(s[i]==")"){
			while(top!=-1&&stack[top]!='('){
				output[k]=stack[top];
				stack[top]='\0';
				top--;
			}
			stack[top]='\0';
			top--;
		}
	}
}
