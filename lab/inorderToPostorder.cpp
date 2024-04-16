#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

node *BST(vector<int> inorder, int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    int mid = start + (end - start) / 2;
    node *root = new node(inorder[mid]);
    root->left = BST(inorder, start, mid - 1);
    root->right = BST(inorder, mid + 1, end);
    return root;
}

void postorderTraversal(node *root)
{
    if (root == NULL)
        return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

void inorderToPostorder(vector<int> inorder)
{
    node *root = BST(inorder, 0, inorder.size() - 1);
    cout << "Postorder: ";
    postorderTraversal(root);
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    vector<int> inorder;
    cout << "Enter inorder traversal: ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        inorder.push_back(x);
    }
    inorderToPostorder(inorder);
    return 0;
}
