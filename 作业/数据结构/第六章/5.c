#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// 创建一个新节点
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 中序遍历打印二叉树
void inorderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// 打印并删除子树
void printAndDeleteSubtree(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    // 打印子树
    inorderTraversal(root);
    printf("\n");

    // 删除子树
    printAndDeleteSubtree(root->left);
    printAndDeleteSubtree(root->right);
    free(root);
}

// 删除值为x的节点及其子树
struct TreeNode* deleteNode(struct TreeNode* root, int x) {
    if (root == NULL) {
        return NULL;
    }

    if (root->data == x) {
        // 找到要删除的节点，打印并删除其子树
        printf("被删除的子树: ");
        printAndDeleteSubtree(root);
        return NULL;
    }

    root->left = deleteNode(root->left, x);
    root->right = deleteNode(root->right, x);

    return root;
}

// 主函数
int main() {
    // 创建二叉树
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("原二叉树的中序遍历: ");
    inorderTraversal(root);
    printf("\n");

    int x = 2;
    root = deleteNode(root, x);

    printf("删除值为%d的节点及其子树后的中序遍历: ", x);
    inorderTraversal(root);
    printf("\n");

    return 0;
}
