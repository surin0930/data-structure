//  15
// 4  20
//1 16  28

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TReeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;

TreeNode n1 = { 1, NULL, NULL };		//{가운데, 왼쪽, 오른쪽}
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 28, NULL,NULL };
TreeNode n5 = { 20, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };
TreeNode* root = &n6;

void inorder(TreeNode* root) {
	if (root) {
		inorder(root->left);
		printf("%d\n", root->data);
		inorder(root->right);
	}
}

void preorder(TreeNode* root) {
	if (root) {
		printf("%d\n ", root->data);
		preorder(root->left);
		preorder(root->right);

	}
}

void postorder(TreeNode* root) {
	if (root) {
		postorder(root->left);
		postorder(root->right);
		printf("%d\n", root->data);
	}
}

int main() {
	printf("중위 순회\n");
	inorder(root);
	printf("\n\n");

	printf("전위 순회\n");
	preorder(root);
	printf("\n\n");

	printf("후위 순회\n");
	postorder(root);
	printf("\n\n");
	return 0;
}