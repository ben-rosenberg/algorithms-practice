#include <iostream>
#include "BinarySearchTree.h"


/* Constructors */

BinarySearchTree::BinarySearchTree()
    : m_root(nullptr) {}

BinarySearchTree::BinarySearchTree(int rootVal)
    : m_root(new TreeNode(rootVal)) {}

/* Deconstructor */

BinarySearchTree::~BinarySearchTree()
{
    deleteTree();
}

/* Utiliy Functions */

void BinarySearchTree::printRoot()
{
    if (this->isEmpty()) {
        std::cout << "NULL" << '\n';
        return;
    }

    std::cout << m_root->m_value << '\n';
}

void BinarySearchTree::printChildren(TreeNode* node)
{
    if (node == nullptr) {
        std::cout << "NULL" << '\n';
        return;
    }
    int leftVal = node->m_left != nullptr 
        ? node->m_left->m_value
        : 0;

    int rightVal = node->m_right != nullptr
        ? node->m_right->m_value
        : 0;

    std::cout << node->m_value << ": " << leftVal << ", " << rightVal << '\n';
}

bool BinarySearchTree::isEmpty()
{
    return m_root == nullptr;
}

/* Insertion */

TreeNode* BinarySearchTree::insert(int newVal)
{
    if (m_root == nullptr) {
        TreeNode* newNode = new TreeNode(newVal);
        m_root = newNode;
        return m_root;
    }

    return insert(m_root, newVal);
}

TreeNode* BinarySearchTree::insert(TreeNode* currNode, int newVal)
{
    if (newVal < currNode->m_value) {
        if (currNode->m_left == nullptr) {
            currNode->m_left = new TreeNode(newVal);
            return currNode->m_left;
        }

        return insert(currNode->m_left, newVal);
    }

    if (currNode->m_right == nullptr) {
        currNode->m_right = new TreeNode(newVal);
        return currNode->m_right;
    }

    return insert(currNode->m_right, newVal);
}

/* void BinarySearchTree::insert(int newVals[], int newValsLength)
{
    for (int i = 0; i < newValsLength; ++i) {
        insert(newVals[i]);
    }
} */

/* Search */

bool BinarySearchTree::search(int searchVal)
{
    if (m_root == nullptr) return false;
    if (searchVal == m_root->m_value) return true;

    return search(m_root, searchVal);
}

bool BinarySearchTree::search(TreeNode* currNode, int searchVal)
{
    if (currNode == nullptr) return false;

    if (searchVal == currNode->m_value) {
        return true;
    }

    if (searchVal < currNode->m_value) {
        return search(currNode->m_left, searchVal);
    }

    return search(currNode->m_right, searchVal);
}

/* Breadth-First Traversal */

/*
    I need to print the current node's value, with the current node beginning
    at root.
    I need to print out the value of the current node's left child.
    I need to print the value of the current node's right child.
    I need to do the same for the current node's children, beginning with the
    children of left node first, then children of right node.
    HOW DO?
*/
void BinarySearchTree::levelOrder()
{
    /* Is this even necessary? This gets checked every recursive call */
    if (isEmpty()) {
        std::cout << "Empty" << '\n';
        return;
    }

    levelOrder(m_root, false);
    std::cout << std::endl;
}

void BinarySearchTree::levelOrder(TreeNode* currNode, bool leftOrRight)
{
    if (currNode == nullptr) return;

    std::cout << currNode->m_value << ", ";
    levelOrder((leftOrRight ? currNode->m_right : currNode->m_left), !leftOrRight);
}

/* Depth-First Traversal */

void BinarySearchTree::inorder()
{
    if (m_root == nullptr) {
        std::cout << "Empty" << '\n';
        return;
    }

    inorder(m_root);
    std::cout << std::endl;
}

void BinarySearchTree::inorder(TreeNode* currNode)
{
    if (currNode == nullptr) return;

    inorder(currNode->m_left);
    std::cout << currNode->m_value << ", ";
    inorder(currNode->m_right);
}

void BinarySearchTree::preorder()
{
    if (isEmpty()) {
        std::cout << "Empty" << '\n';
        return;
    }

    preorder(m_root);
    std::cout << std::endl;
}

void BinarySearchTree::preorder(TreeNode* currNode)
{
    if (currNode == nullptr) return;

    std::cout << currNode->m_value << ", ";
    preorder(currNode->m_left);
    preorder(currNode->m_right);
}

void BinarySearchTree::postorder()
{
    if (m_root == nullptr) {
        std::cout << "Empty" << '\n';
        return;
    }

    postorder(m_root);
    std::cout << std::endl;
}

void BinarySearchTree::postorder(TreeNode* currNode)
{
    if (currNode == nullptr) return;

    postorder(currNode->m_left);
    postorder(currNode->m_right);
    std::cout << currNode->m_value << ", ";
}

/* Cleanup */

void BinarySearchTree::deleteTree()
{
    _deleteTree(m_root);
}

void BinarySearchTree::_deleteTree(TreeNode* currNode)
{
    if (currNode == nullptr) return;

    _deleteTree(currNode->m_left);
    _deleteTree(currNode->m_right);
    std::cout << "Deleting node with value: " << currNode->m_value << '\n';
    delete currNode;
    currNode = nullptr;
}