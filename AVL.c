#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define TREE_TYPE int
#define size 15
#define max(a,b) a>b?a:b
/*
AVL�����������: TL, TR�߶�ֻ�����1 
��������ɾ��ʱ�临�Ӷ�O(NlogN) 
*/

typedef struct AVL_TREE_NODE{
	TREE_TYPE key;
	struct AVL_TREE_NODE *left;
	struct AVL_TREE_NODE *right;
	struct AVL_TREE_NODE *p;
	int Height;
	int frequency;
} tNode, tTree;

int height(tNode* k){
	if(k == NULL){
		return -1;
	}else{
		return k->Height;
	}
}

int heightInit(tNode* k){
	return max(height(k->left), height(k->right)) + 1;
}

tNode* root;

//�����µ�Node 
tNode* NodeInit(TREE_TYPE val){
	tNode* p = (tNode*)malloc(sizeof(tNode));
	p->frequency = 1;
	p->Height = 0;
	p->left = NULL;
	p->right = NULL;
	p->p = NULL;
	return p;
}

/*
AVL��ʧȥƽ���ʱ��һ������������֮һ: LL, LR, RL, RR 
*/
tNode* llRotate(tNode* k2){
	// k2����תǰ�ĸ��ڵ� 
	tNode* k1 = NULL, k2p = NULL;
	k1 = k2->left;
	// ����k2��parent, k1����parent 
	if(k2 != root){
		k2p = k2->p;
		//����ƽ������root 
		if(k2p->left == k2){
			k2p->left = k1;
		} else{
			k2p->right = k1;
		}
		k1->p = k2p;
	} else{
		k1->p = NULL;
	}
	
	k2->left = k1->right;
	k1->right = k2;
	k2->parent = k1;
	
	if(k2->left != NULL){
		k2->left->p = k2;
	}
	
	return k1;
}

tNode* rrRotate(tNode* k1){
	tNode* k2 = k1->right, k1p = NULL;
	if(k1 != root){
		k1p = k1->p;
		if(k1p->left == k1){
			k1p->left = k2;
		}else{
			k1p->right = k2;
		}
		k2->p = k1p;
	}else{
		k2->p = NULL;
	}
	k1->right = k2->left;
	
	if(k1->right != NULL){
		k1->right->p = k1;
	}
	
	return k1;	//root=XXRotate();
}

/*

1) RR
2) LL
		k3
	   /  \
	  k1  D
	 / \
	A	k2
	   /  \
	  (B)  C
//todo test
*/
tNode* lrRotate(tNode* k3){
	tNode* k1 = k3->left;
	tNode* k2 = k1->right;
	
	if(k2->left != NULL){
		tNode* B = k2->left;
		B->p = k1;
		k1->right = B;
		k2->p = B;
		B->right = k2; 
	}
	
	k3->left = rrRotate(k1);
	return llRotate(k3);
}

/*
		k4
	   /  \
	  D   k3
	     /  \
	    k2   B
	   /  \
	  A  (C)
*/
tNode* rlRotate(tNode* k4){
	tNode* k3 = k4->right;
	tNode* k2 = k3->left;
	
	if(k2->right != NULL){
		tNode* C = k2->right;
		k3->left = C;
		C->p = k3;
		k2->p = C;
		C->left = k2;
	}
	
	k4->right = llRotate(k3);
	return rrRotate(k4);
}

tTree* addNode(TREE_TYPE val, tTree* k){
	
}
/*
����->��ת
1) root->left->left = newNode; 		����
2) root->right->right = newNode;	����
3) root->left->right = newNode;		���һ���
4) root->right->left = newNode;		������  
*/

void printTree(tTree* T){
	if(T!=NULL){
		printTree(T->left);
		printf("%d ", T->key);
		printTree(T->right;)
	}
}

