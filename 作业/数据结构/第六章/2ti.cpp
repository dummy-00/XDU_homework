#include <iostream>
using namespace std;

// 二叉树节点结构体定义
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 查找节点n的双亲节点的函数
TreeNode *findParent(TreeNode *t, int n, TreeNode *&parent) {
	if (t == NULL) {
		return NULL;
	}
	if (t->left != NULL && t->left->val == n) {
		parent = t;
		return t;
	}
	if (t->right != NULL && t->right->val == n) {
		parent = t;
		return t;
	}
	TreeNode *leftResult = findParent(t->left, n, parent);
	if (leftResult != NULL) {
		return leftResult;
	}
	return findParent(t->right, n, parent);
}

int main() {
	// 构建一棵示例二叉树
	TreeNode *root = new TreeNode(1);
	TreeNode *node2 = new TreeNode(2);
	TreeNode *node3 = new TreeNode(3);
	TreeNode *node4 = new TreeNode(4);
	TreeNode *node5 = new TreeNode(5);
	TreeNode *node6 = new TreeNode(6);
	TreeNode *node7 = new TreeNode(7);

	root->left = node2;
	root->right = node3;
	node2->left = node4;
	node2->right = node5;
	node3->left = node6;
	node3->right = node7;

	TreeNode *parent = NULL;
	int target = 7;  // 这里可以修改要查找双亲节点的目标节点值
	TreeNode *result = findParent(root, target, parent);
	if (result == NULL) {
		cout << "不存在节点 " << target << " 或者该节点没有双亲节点" << endl;
	} else {
		cout << "节点 " << target << " 的双亲节点的值为: " << result->val << endl;
	}

	return 0;
}