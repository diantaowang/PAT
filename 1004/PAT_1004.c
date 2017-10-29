#include <stdio.h>
#include <malloc.h>

typedef struct _TreeNode *PtrToNode;

typedef struct _TreeNode{
	PtrToNode FirstChild;
	PtrToNode NextSibling;
} TreeNode;

int main()
{
	int m, n;
	PtrToNode Ptr;
	scanf("%d%d", &m, &n);
	Ptr = (PtrToNode)malloc(sizeof(TreeNode));
	

	return 0;
}
