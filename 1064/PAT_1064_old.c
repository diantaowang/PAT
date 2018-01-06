#include <stdio.h>
#include <stdlib.h>

#define LEFT  0
#define RIGHT 1

int num[1010];
int POWER[12] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024 };

typedef struct _node {
	struct _node *left, *right;
	int num;
} node;

node *add_node(node * f, int num, int type)
{
	node *child = (node *) malloc(sizeof(node));
	child->num = num;
	child->left = NULL;
	child->right = NULL;
	if (type == LEFT)
		f->left = child;
	else
		f->right = child;
	return child;
}

int find(int l, int r)
{
	int k = 0;
	int n = r - l + 1;
	while (k < 13) {
		if (POWER[k] > n)
			break;
		k++;
	}
	int baseNum = POWER[k] - 1 - n;
	int baseHalfNum = POWER[k - 2];
	if (baseNum <= baseHalfNum)
		l += baseNum;
	else {
		l += baseHalfNum;
		r -= (baseNum - baseHalfNum);
	}
	return (r - l) / 2 + l;
}

void make_tree(int l, int r, node * f, int type)
{
	if (l > r)
		return;
	else {
		int mid = find(l, r);
		node *child = add_node(f, num[mid], type);
		make_tree(l, mid - 1, child, LEFT);
		make_tree(mid + 1, r, child, RIGHT);
	}
}

node *build_tree(int l, int r)
{
	node *root = (node *) malloc(sizeof(node));
	root->left = NULL;
	root->right = NULL;
	int mid = find(l, r);
	root->num = num[mid];
	make_tree(l, mid - 1, root, LEFT);
	make_tree(mid + 1, r, root, RIGHT);
	return root;
}

int comp(const void *a, const void *b)
{
	return *((int *)a) > *((int *)b) ? 1 : -1;
}

void level_order(node * root, int *a)
{
	node *son[1010] = { NULL }, *son_n[1010] = {
	NULL};
	node **p1 = son;
	node **p2 = son_n;
	son[0] = root;
	int n1 = 1, n2 = 0, count = 0;
	for (int i = 0; i < n1; i++) {
		a[count++] = p1[i]->num;
		if (p1[i]->left != NULL) {
			p2[n2++] = p1[i]->left;
			if (p1[i]->right != NULL)
				p2[n2++] = p1[i]->right;
		}
		if (i == n1 - 1) {
			n1 = n2;
			n2 = 0;
			node **t = p1;
			p1 = p2;
			p2 = t;
			i = -1;
		}
	}
}

int main()
{
	int n, order[1010];
	node *tree;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &num[i]);
	qsort(num, n, sizeof(int), comp);
	tree = build_tree(0, n - 1);
	level_order(tree, order);
	for (int i = 0; i < n - 1; i++)
		printf("%d ", order[i]);
	printf("%d\n", order[n - 1]);
	free(tree);
	return 0;
}
