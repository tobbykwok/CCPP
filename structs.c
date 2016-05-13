#include<stdio.h>
#include<stdlib.h>

typedef struct G_Node{		
	struct G_Node* left;
	struct G_Node* right;
	int value;
} Node;

int main(){	
	Node* a = (Node*)malloc(sizeof(Node));
	printf("%d", a);
	return 0;
}
