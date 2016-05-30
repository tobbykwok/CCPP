#include<stdio.h>
#include<stdlib.h>
int main(){
	int a = 123;
	int b = 321;
	int *c = &a;
	int *d = &b;
	
	printf("&a: %d\r\n", &a);
	printf("c: %d\r\n", c);
	printf("&c: %d\r\n", &c);
	printf("&d: %d\r\n", &d);
	*d = *c;
	printf("*d=*c ==> &c: %d\r\n", &c);
	printf("*d=*c ==> &d: %d\r\n", &d);
	printf("*d=*c ==> c: %d\r\n", c);
	printf("*d=*c ==> d: %d\r\n", d);
	printf("*d=*c ==> *c: %d\r\n", *c);
	printf("*d=*c ==> *d: %d\r\n", *d);
	
	d = c;
	printf("----------------\r\n");
	printf("d=c ==> &c: %d\r\n", &c);
	printf("d=c ==> &d: %d\r\n", &d);
	printf("d=c ==> c: %d\r\n", c);
	printf("d=c ==> d: %d\r\n", d);
	printf("d=c ==> *c: %d\r\n", *c);
	printf("d=c ==> *d: %d\r\n", *d);
	
	//printf("d: %d\r\n", *d);
	
	return 0;
}
