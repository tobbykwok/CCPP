#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define TREE_TYPE int
#define size 15

/*
Most of the BST operations (e.g., search, max, min, insert, delete.. etc) take O(h) time where h is the height of the BST.

*/


typedef struct Tree{
	TREE_TYPE value;
	struct Tree *left;
	struct Tree *right;
} Tree_node;

static Tree_node *root;

void create_tree(){
	root = NULL;
}

Tree_node* minValueNode(Tree_node *node){
	Tree_node* current = node;
	while(current->left != NULL){
		current = current->left;
	}
	return current;
}

Tree_node* insert(Tree_node *node, TREE_TYPE value){
	if(node == NULL){
		node = (Tree_node*)malloc(sizeof(Tree_node) * 1);
		node->value = value;
		node->left = NULL;
		node->right = NULL;
		if(root == NULL){
			root = node;
		}
	} else{
		if(value < node->value){
			node->left = insert(node->left, value);
		}else{
			node->right = insert(node->right, value);
		}
	}
	return node;
}

void show_all(Tree_node *node){
	if(node != NULL){
		if(node->left != NULL){
			show_all(node->left);
		}
		printf("%d ", node->value);
		if(node->right != NULL){
			show_all(node->right);
		}
	}
}

Tree_node* search(Tree_node *node, TREE_TYPE value){
	Tree_node *result = NULL;
	if(node != NULL){
		if(value == node->value){
			result = node;
		}else if(value<node->value){
			result = search(node->left, value);
		}else{
			result = search(node->right, value);
		}
	}
	return result;
}

Tree_node* find_parent(Tree_node *parent, TREE_TYPE value){
	Tree_node *result = NULL;
	if(parent != NULL){
		if(value < parent->value && parent->left != NULL){
			if(value == parent->left->value){
				result = parent;
			}else{
				result = find_parent(parent->left, value);
				if(result == NULL){
					result = find_parent(parent->right, value);
				}
			}
		}
		if(value > parent->value && parent->right != NULL){
			if(value == parent->right->value){
				result = parent;
			}else{
				result = find_parent(parent->left, value);
				if(result == NULL){
					result = find_parent(parent->right, value);
				}
			}
		}
	}
	return result;
}

/*
Deletion of a node:
	1) Node to be deleted is leaf: Simply remove from the tree.
	2) Node to be deleted has only one child: Copy the child to the node and delete the child.
	3) Node to be deleted has two children: 

*/
Tree_node* delete_node(Tree_node *root, TREE_TYPE key){
	if(root == NULL){
		return root;
	}
	
	if(key < root->value){
		// if the key to be deleted is smaller than the root's tree. then it lies in left tree.
		root->left = delete_node(root->left, key);
	} else if(key > root->value){
		root->right = delete_node(root->right, key);
	} else{
		// if key is same as root's key, then this is the node to be deleted.
		// further checks:
		//     1) node with only one child or no child.
		if(root->left == NULL){
			Tree_node* t = root->right;
			free(root);
			return t;
		}else if(root->right == NULL){
			Tree_node* t = root->left;
			free(root);
			return t;
		}
		//     2) node with two children: Get the inorder successor (smallest in the right subtree)
		Tree_node* t = minValueNode(root->right);
		
		root->value = t->value;
		root->right = delete_node(root->right, t->value);
	}
	
	return root;
}

int main()  
{  
    /**初始化*/  
    create_tree();  
  
    /**插入*/  
    TREE_TYPE list[size] = {8,4,11,2,6,10,13,1,3,5,7,9,15,14,16};  
    int i;  
    for(i = 0; i < size; i++)  
        insert(root,list[i]);  
  
    /**显示全部*/  
    show_all(root);  
    putchar('\n');  
  
    /**根据值查找某节点*/  
    Tree_node *result = search(root,14);  
    if(result != NULL)  
        printf("To find %d,result is %d\n",14,result->value);  
    else  
        printf("Not find\n");  
  
    /**根据值查找其父节点*/  
    Tree_node *parent_result = find_parent(root,14);  
    if(parent_result != NULL)  
        printf("To find %d's parent,result is %d\n",14,parent_result->value);  
    else  
        printf("Cannot find %d's parent\n",14);  
        
    printf("------------------------------\r\n");
	root = delete_node(root, 4);
	root = delete_node(root, 15);
	show_all(root);
	system("pause");
    return 0;  
}  
