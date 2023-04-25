#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
  if (root != NULL) {
    traverseInOrder(root->left);
    cout << root->key << " ";
    traverseInOrder(root->right);
  }
}

// Insert a node
struct node *insertNode(struct node *root, int key) {
  if (root == NULL) {
    struct node *newNode = new node;
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
  }
  
  else if (root->key < key  ) {
    root->right = insertNode(root->right, key);
  }
  else if (key < root->key) {
    root->left = insertNode(root->left, key);
  }
  return root;
}


// Find the minimum value node
struct node *minValueNode(struct node *node) {
  struct node *current = node;
  while (current->left != NULL) {
    current = current->left;
  }
  return current;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  if (root == NULL) {
    return root;
  } else if (key < root->key) {
    root->left = deleteNode(root->left, key);
  } else if (key > root->key) {
    root->right = deleteNode(root->right, key);
  } else {
    if (root->left == NULL) {
      struct node *temp = root->right;
      delete root;
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      delete root;
      return temp;
    }
    struct node *minNode = root->right;
    while (minNode->left != NULL) {
      minNode = minNode->left;
    }
    root->key = minNode->key;
    root->right = deleteNode(root->right, minNode->key);
  }
  return root;
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        
        return 0;
    }
  }
  
  traverseInOrder(root);
  return 0;
}
