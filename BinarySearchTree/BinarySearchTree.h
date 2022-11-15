#include "TreeNode.h"

class BinarySearchTree
{
public:
    /* Constructors */
    BinarySearchTree();
    BinarySearchTree(int rootVal);

    /* Destructor */
    ~BinarySearchTree();

    /* Utiliy Functions */
    void printRoot();
    void printChildren(TreeNode* node);
    bool isEmpty();

    /* Insertion */
    TreeNode* insert(int newVal);
    TreeNode* insert(TreeNode* currNode, int newVal); // maybe make this private

    /* void insert(int newVals[], int newValsLength); */

    /* Deletion */
    void deleteNode(TreeNode* currNode = nullptr);

    /* Search */
    bool search(int searchVal);
    bool search(TreeNode* currNode, int searchVal); // maybe make this private

    /* Breadth-First Traversal */
    void levelOrder();
    void levelOrder(TreeNode* currNode, bool leftOrRight);

    /* Depth-First Traversal */
    void inorder();
    void inorder(TreeNode* currNode); // private?

    void preorder();
    void preorder(TreeNode* currNode);

    void postorder();
    void postorder(TreeNode* currNode);

    /* Cleanup */
    void deleteTree();
    void _deleteTree(TreeNode* currNode);

private:
    TreeNode* m_root;
};