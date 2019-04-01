//BRUTCE FORCE APPROACH
//Efficient approach - build max heap by frequency of each character
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define nl printf("\n")
#define INT_MAX 100000
void swap(char *a,char *b) {
	char temp = *a;
	*a = *b;
	*b = temp;
}
char str[INT_MAX]; int length;
int check() {
	for(int i=0;i<length-1;i++) {
		if(str[i]==str[i+1])
			return 0;
	}
	return 1;
}
int flag=0;
void permute(int start,int end) {
	if(start == end) {
		//Permutation ready
		if(check()) {
			flag=1;
			return;
		}
	}
	else {
		for(int i=start;i<=end;i++) {
			swap(&(str[start]),&(str[i]));
			permute(start+1,end);
			swap(&(str[start]),&(str[i]));
		}
	}
}
int main() {
	#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen("input.txt","r",stdin);
	//for writing output to output.txt
	freopen("output.txt","w",stdout);
	#endif
	scanf("%s",str);
	length = strlen(str);
	permute(0,length-1);
	if(flag==0)
		printf("Not Possible\n");
	else
		printf("Possible\n");
    return 0;	
}

