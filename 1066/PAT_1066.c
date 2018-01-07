#include <stdio.h>
#include <stdlib.h>

struct AvlNode {
	int data;
	struct AvlNode *left;
	struct AvlNode *right;
	int height;
};

typedef struct AvlNode *AvlTree;

int Height(AvlTree P)
{
	if (P == NULL)
		return -1;
	else
		return P->height;
}

int Max(int a, int b)
{
	return a > b ? a : b;
}

AvlTree RotateLL(AvlTree k2)
{
	AvlTree k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;
	k2->height = Max(Height(k2->left), Height(k2->right)) + 1;
	k1->height = Max(Height(k1->left), k2->height) + 1;
	return k1;
}

AvlTree RotateRR(AvlTree k1)
{
	AvlTree k2 = k1->right;
	k1->right = k2->left;
	k2->left = k1;
	k1->height = Max(Height(k1->left), Height(k1->right)) + 1;
	k2->height = Max(k1->height, Height(k2->right)) + 1;
	return k2;
}

AvlTree RotateLR(AvlTree k3)
{
	k3->left = RotateRR(k3->left);
	return RotateLL(k3);
}

AvlTree RotateRL(AvlTree k1)
{
	k1->right = RotateLL(k1->right);
	return RotateRR(k1);
}

AvlTree Insert(int x, AvlTree T)
{
	if (T == NULL) {
		T = (AvlTree) malloc(sizeof(struct AvlNode));
		T->data = x;
		T->left = NULL;
		T->right = NULL;
		T->height = 0;
	} else if (x < T->data) {
		T->left = Insert(x, T->left);
		if (Height(T->left) - Height(T->right) == 2) {
			if (x < T->left->data)
				T = RotateLL(T);
			else
				T = RotateLR(T);
		}
	} else {
		T->right = Insert(x, T->right);
		if (Height(T->right) - Height(T->left) == 2) {
			if (x > T->right->data)
				T = RotateRR(T);
			else
				T = RotateRL(T);
		}
	}
	T->height = Max(Height(T->left), Height(T->right)) + 1;
	return T;
}

int main()
{
	int n, num;
	scanf("%d", &n);
	AvlTree root = NULL;
	while (n--) {
		scanf("%d", &num);
		root = Insert(num, root);
	}
	printf("%d\n", root->data);
	return 0;
}
