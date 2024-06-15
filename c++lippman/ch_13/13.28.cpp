/*
Exercise 13.28: Given the following classes, implement a default constructor and the
necessary copy-control members.
*/
#include <string>

// TreeNode class definition
class TreeNode {
private:
    std::string value;
    int count;
    TreeNode *left;
    TreeNode *right;
    std::size_t *use;

public:
    // Default constructor
    TreeNode(const std::string &s = std::string()) 
        : value(s), count(1), left(nullptr), right(nullptr), use(new std::size_t(1)) {}

    // Copy constructor
    TreeNode(const TreeNode &node) 
        : value(node.value), count(node.count), 
          left(node.left), right(node.right), use(node.use) { ++*use; }

    // Copy assignment operator
    TreeNode& operator=(const TreeNode &rhs) {
        ++*rhs.use;
        if (--*use == 0) {
            delete left;
            delete right;
            delete use;
        }
        value = rhs.value;
        count = rhs.count;
        left = rhs.left;
        right = rhs.right;
        use = rhs.use;
        return *this;
    }

    // Destructor
    ~TreeNode() {
        if (--*use == 0) {
            delete left;
            delete right;
            delete use;
        }
    }
};