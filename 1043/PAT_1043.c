#include <stdio.h>
#include <stdlib.h>

#define LEFT  0
#define RIGHT 1

int first_time = 0;

typedef struct _node {
	int num;
	struct _node *left, *right;
} node;

void add_node(node * f, int num, int type)
{
	node *child = (node *) malloc(sizeof(node));
	child->num = num;
	child->left = NULL;
	child->right = NULL;
	if (type == LEFT)
		f->left = child;
	else
		f->right = child;
}

int build_tree(node * f, int num, int type)
{
	if (type == 0) {
		if (num < f->num && f->right == NULL) {
			if (f->left == NULL) {
				add_node(f, num, LEFT);
				return 1;
			} else {
				return build_tree(f->left, num, 0);
			}
		} else if (num >= f->num) {
			if (f->right == NULL) {
				add_node(f, num, RIGHT);
				return 1;
			} else {
				return build_tree(f->right, num, 0);
			}
		} else {
			return -1;
		}
	} else {
		if (num >= f->num && f->right == NULL) {
			if (f->left == NULL) {
				add_node(f, num, LEFT);
				return 1;
			} else {
				return build_tree(f->left, num, 1);
			}
		} else if (num < f->num) {
			if (f->right == NULL) {
				add_node(f, num, RIGHT);
				return 1;
			} else {
				return build_tree(f->right, num, 1);
			}
		} else {
			return -1;
		}
	}
	return -1;
}

void postorder_traversal(node * f)
{
	if (f->left == NULL && f->right == NULL) {
		if (first_time == 0) {
			first_time = 1;
			printf("%d", f->num);
		} else {
			printf(" %d", f->num);
		}
		return;
	}
	if (f->left != NULL)
		postorder_traversal(f->left);
	if (f->right != NULL)
		postorder_traversal(f->right);
	printf(" %d", f->num);
}

int main()
{
	int n, num[1010];
	node *tree;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &num[i]);
	tree = (node *) malloc(sizeof(node));
	tree->num = num[0];
	tree->left = NULL;
	tree->right = NULL;
	if (n == 1)
		printf("YES\n%d\n", num[0]);
	else {
		int flag;
		for (int i = 1; i < n; i++) {
			flag = build_tree(tree, num[i], 0);
			if (flag == -1)
				break;
		}
		if (flag == -1) {
			tree->left = NULL;
			tree->right = NULL;
			for (int i = 1; i < n; i++) {
				flag = build_tree(tree, num[i], 1);
				if (flag == -1)
					break;
			}
		}
		if (flag == -1)
			printf("NO\n");
		else {
			printf("YES\n");
			postorder_traversal(tree);
			printf("\n");
		}
	}
	return 0;
}
