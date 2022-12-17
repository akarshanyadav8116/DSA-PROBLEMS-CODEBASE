//Wap to find whether the string is a palindrome
#include<stdio.h>
int main(){
	char i=0,n=0,s[100],st[100]={'\0'},top=-1;
	printf("Enter the string :");
	scanf("%s",s);
	while(s[n]!='\0'){
		n++;
	}
	if((n%2)==0){
	while(s[i]!='\0'){
		if(top!=-1&&s[i]==st[top]){
			st[top]='\0';
			top--;
		}
		else{
			if(top!=99){
				st[top+1]=s[i];
				top++;
			}
			else{
				printf("Overflow");
				break;
			}
		}
		i++;
	}
	}
	else{
		while(s[i]!='\0'){
			if(i!=(n-1)/2){
		if(top!=-1&&s[i]==st[top]){
			st[top]='\0';
			top--;
		}
		else{
			if(top!=99){
				st[top+1]=s[i];
				top++;
			}
			else{
				printf("Overflow");
				break;
			}
		}
		}
		i++;
	}
	}
	if(top==-1){
		printf("It is a palindrome");	
	}
	else{
		printf("It is not a palindrome");
	}
	return 0;
}
