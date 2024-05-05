#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(char val) : data(val), left(nullptr), right(nullptr) {}
};

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

TreeNode* constructExpressionTree(const string& prefix) {
    stack<TreeNode*> st;
    
    for (int i = prefix.size() - 1; i >= 0; --i) {
        char c = prefix[i];
        TreeNode* newNode = new TreeNode(c);
        
        if (isOperator(c)) {
            newNode->left = st.top();
            st.pop();
            newNode->right = st.top();
            st.pop();
        }
        
        st.push(newNode);
    }
    
    return st.top();
}

void postOrderTraversal(TreeNode* root) {
    if (!root)
        return;
    
    stack<TreeNode*> st;
    st.push(root);
    TreeNode* prev = nullptr;
    
    while (!st.empty()) {
        TreeNode* current = st.top();
        
        if (!prev || prev->left == current || prev->right == current) {
            if (current->left)
                st.push(current->left);
            else if (current->right)
                st.push(current->right);
        } else if (current->left == prev) {
            if (current->right)
                st.push(current->right);
        } else {
            cout << current->data << " ";
            st.pop();
        }
        
        prev = current;
    }
}

void deleteTree(TreeNode* root) {
    if (!root)
        return;
    
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    string prefix;
    cout << "Enter the prefix expression: ";
    getline(cin, prefix);
    
    TreeNode* root = constructExpressionTree(prefix);
    
    cout << "Post-order traversal: ";
    postOrderTraversal(root);
    cout << endl;
    
    // Deleting the entire tree
    deleteTree(root);
    
    return 0;
}
