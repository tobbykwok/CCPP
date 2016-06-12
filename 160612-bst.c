#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	struct node *left;
	struct node *right;
	int val;
	int height;
	int frequency;
} Node;

#define MAX(a,b) (((a)>(b))?(a):(b))

Node* NewNode(int val){
	Node* newnode = NULL;
	if(NULL == (newnode = (Node*)malloc(sizeof(Node)))){
		return NULL;
	}
	newnode->val = val;
	newnode->left = newnode->right = NULL;
	newnode->height = 0;
	newnode->frequency = 1;
	return newnode;
}

int Height(Node* root){
	if(root == NULL){
		return -1;
	}
	return root->height;
}

void FreeNode(Node* node){
	free(node);
	node = NULL;
}

Node* PickMaxNode(Node* root){
	if(root == NULL){
		return root;
	}
	if(root->right == NULL){
		return root;
	} else{
		return PickMaxNode(root->right);
	}
}

Node* PickMinNode(Node* root){
	if(root == NULL){
		return NULL;
	}
	if(root->left == NULL){
		return root;
	} else{
		return PickMinNode(root->left);
	}
}

Node* PickNodeByVal(Node* root, int val){
	if(root == NULL){
		return NULL;
	} else if(root->val > val){
		return PickNodeByVal(root->left, val);
	} else if(root->val < val){ 
		return PickNodeByVal(root->right, val);
	} else{
		return root;
	}
}

int ExistVal(Node* root, int val){
	return (PickNodeByVal(root, val) == NULL)? -1:1;
}

Node* Insert(Node* root, int val){
	if(root == NULL){
		return NewNode(val);
	}
	if(root->val > val){
		root->left = Insert(root->left, val);
		root->height = MAX(Height(root->left), Height(root->right)) + 1;
		return root;
	} else if(root->val < val){
		root->right = Insert(root->right, val);
		root->height = MAX(Height(root->left), Height(root->right)) + 1;
		return root;
	} else{
		root->frequency++;
		return root;
	}
}

void RemoveVal(Node* root, int val){
	if(root == NULL){
		return;
	} else if(root->val > val){
		RemoveVal(root->left, val);
		root->height = MAX(Height(root->left), Height(root->right)) + 1;
	} else if(root->val < val){ 
		RemoveVal(root->right, val);
		root->height = MAX(Height(root->left), Height(root->right)) + 1;
	} else{
		if(root->left == NULL && root->right == NULL){
			FreeNode(root);
			root = NULL;
		} else if(root->left == NULL){
			Node* t = root->right;
			*root = *(root->right);
			FreeNode(t);
		} else if(root->right == NULL){
			Node* t = root->left;
			*root = *(root->left);
			FreeNode(t);
		} else{
			Node* t = PickMaxNode(root->left);
			root->val = t->val;
			RemoveVal(t, t->val);
			root->height = MAX(Height(root->left), Height(root->right)) + 1;
		}
	}
}

void PrintNode(Node* node){
	printf("%d\theight:%d\tfrequency:%d\r\n", node->val, node->height, node->frequency);
}

void InorderTraversal(Node* root){
	if(root != NULL){
		InorderTraversal(root->left);
		PrintNode(root);
		InorderTraversal(root->right);
	}
}

void PreorderTraversal(Node* root){
	if(root != NULL){
		PrintNode(root);
		PreorderTraversal(root->left);
		PreorderTraversal(root->right);
	}
}

void PostorderTraversal(Node* root){
	if(root != NULL){
		PostorderTraversal(root->left);
		PostorderTraversal(root->right);
		PrintNode(root);
	}
}

int main(){
	Node* root = Insert(NULL, 20);
	int j = 0;
	for(int i =0;i<20;i++){
		j = rand()%40;
		Insert(root, j);
		printf("%d\t", j);
	}
	printf("\r\nInorder Traversal\r\n-----------------------------\r\n");
	InorderTraversal(root);
	printf("-----------------------------\r\n");

	printf("\r\nPreorder Traversal\r\n-----------------------------\r\n");
	PreorderTraversal(root);
	printf("-----------------------------\r\n");

	printf("\r\nPostorder Traversal\r\n-----------------------------\r\n");
	PostorderTraversal(root);
	printf("-----------------------------\r\n");

	RemoveVal(root, 20);
	printf("\r\nAfter remove 20: Inorder Traversal\r\n-----------------------------\r\n");
	InorderTraversal(root);
	printf("-----------------------------\r\n");

	system("pause");
	return 0;
}
