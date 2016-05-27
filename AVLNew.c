#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define TREE_TYPE int
#define MAX(a,b) a>b?a:b

typedef struct AVL_NODE{
	int height;
	int frequency;
	int val;
	struct AVL_NODE *p;
	struct AVL_NODE *left;
	struct AVL_NODE *right;
} Node;

int AVL_height(Node* node){
	return (node==NULL)? -1: node->height;
}

int AVL_Balance(Node* left, Node* right){
	return AVL_height(left) - AVL_height(right);
}

Node* New_node(int val, Node* l, Node* r, Node* p){
	Node* t = (Node*)malloc(sizeof(Node));
	t->val = val;
	t->left = l;
	t->right = r;
	t->height = 1;
	t->frequency = 0;
	t->p = p;
	return t;
}

Node* LL(Node* root){
	Node* l = root->left;
	if(l->right != NULL){
		root->left = l->right;
		l->right->p = root;
	}
	root->p = l;
	l->right = root;
	return l;
}

Node* RR(Node* root){
	Node* r = root->right;
	if(r->left!=NULL){
		root->right = r->left;
		r->left->p = root;
	}
	root->p = r;
	r->left = root;
	return r;
}

Node* LR(Node* root){
	Node* l = root->left, *lr = l->right;
	if(lr->left != NULL){
		lr->left->p = l;
		l->right = lr->left;
		l->right->right = lr;
		lr->p = l->right;
		lr->left = NULL;
	}
	
	root->left = RR(l);
	return LL(root);
}

Node* RL(Node* root){
	Node* r = root->right, *rl = r->left;
	if(rl->right != NULL){
		rl->right->p = r;
		r->left = rl->right;
		r->left->left = rl;
		rl->p = r->left;
		rl->right = NULL;
	}
	
	root->right = LL(r);
	return RR(root);
}

Node* Add(Node* root, Node* parent, TREE_TYPE val){
	Node* t = NULL;
	if(root == NULL){
		root = New_node(val, NULL, NULL, parent);
		root->height = 1;
		root->frequency = 0;
	} else {	
		if(root->val > val){
			root->left = Add(root->left, root, val);
			if(AVL_Balance(root->left, root->right) == 2){
				if(val < root->left->val){
					root = LL(root);
				} else if (val >root->left->val){
					root = LR(root);
				}
			}
		} else if(root->val < val){
			root->right = Add(root->right, root, val);
			if(AVL_Balance(root->left, root->right) == -2){
				if(val > root->right->val){
					root = RR(root);
				} else if (val < root->right->val){
					root = RL(root);
				}
			}
		} else{
			root->frequency++;
		}
	}
	
	root->height = MAX(AVL_height(root->left), AVL_height(root->right));
	return root;
}

Node* Delete(Node* root, Node* p){
	if(root == NULL){
		return NULL;
	}
	if(root->val > p->val){
		Delete(root->left, p);
		if(AVL_Balance(root->left, root->right) == -2){
			
		}
	} else if(root->val < p->val){
		Delete(root->right, p);
	} else{
		
	}
}

void Print_all(Node* root){
	if(root!= NULL){
		Print_all(root->left);
		printf("%d\r\n", root->val);
		Print_all(root->right);
	}
}



void Remove_node(Node* node){
	if(node != NULL){
		if(node->p != NULL){
			if(node->p->left == node){
				node->p->left = NULL;
			}else{
				node->p->right = NULL;
			}
		}
		if(node->left != NULL){
			Remove_node(node->left);
		}
		if(node->right != NULL){
			Remove_node(node->right);
		}
		free(node);
		node = NULL;
	} else{
		return;
	}
}

int main(){
	Node* root = New_node(20, NULL, NULL, NULL);
	Add(root, NULL, 10);

	for(int i = 0; i< 10; i++){
		Add(root, NULL, rand() %100 + 1);
	}

	Print_all(root);
	Remove_node(root);
	system("pause");
	return 0;
}
