struct TreeNode
{
    TreeNode() : m_value(0), m_left(nullptr), m_right(nullptr) {}

    TreeNode(int newVal) : m_value(newVal), m_left(nullptr), m_right(nullptr) {}

    TreeNode(int newVal, TreeNode* left, TreeNode* right)
        : m_value(newVal), m_left(left), m_right(right) {}

    TreeNode* m_left, *m_right;
    int m_value;
};