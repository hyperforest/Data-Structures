#include <bits/stdc++.h>
using namespace std;

/*
	Bismillaah Ar-Rahmaan Ar-Rahiim
	Created By : Rimba Erlangga	
	Oct 22nd 2017
	
	This program provides the basic concept about Binary Search Tree data structure :
	insertion operation and pre-order, in-order, and post-order traversal.
*/



//	Declaration of the node

struct Node {
   int value;
   struct Node* left;
   struct Node* right;
};


//	Create a new node, used when inserting a new node into a NULL node

struct Node* create(int input) {
   Node* ret = new Node;
   ret->value = input;
   ret->left = NULL;
   ret->right = NULL;
   return ret;
}


/*	
	-- Insert a node into a node --
	The insert function takes two arguments : a node and an integer
	The node used as the argument processed recursively in order to find the correct position on the tree.
	When the position is reached, it creates a new node with "input" parameter used as its value,
	and then the function returns the node on the arguments.
*/

struct Node* insert(Node* node, int input) {
   if(node == NULL) return create(input);
   if(input < node->value) node->left = insert(node->left, input);
   else node->right = insert(node->right, input);
   return node;
}


/*	
	-- Search a node is in tree or not --
	The search function takes two arguments : a node and an integer
	The node used as the argument processed recursively in order to find the existance of a node on the tree.
	When the node with value equals to "input" parameter is found, it returns the node,
	else it returns NULL.
*/

struct Node* search(Node* node, int input) {
   if (node == NULL) return NULL;
   if (node->value == input) return node;
   if (input < node->value) return search(node->left, input);
   else return search(node->right, input);
}

void preOrder(Node* node) {
   cout << node->value << " ";
   if(node->left != NULL) preOrder(node->left);
   if(node->right != NULL) preOrder(node->right);
}

void inOrder(Node* node) {
   if(node->left != NULL) inOrder(node->left);
   cout << node->value << " ";
   if(node->right != NULL) inOrder(node->right);
}

void postOrder(Node* node) {
   if(node->left != NULL) postOrder(node->left);
   if(node->right != NULL) postOrder(node->right);
   cout << node->value << " ";
}

int main() {
	int N, M, input;
	Node* myTreeRoot = NULL; //We create a new root of our tree, and initally set as NULL
	
	cout << "How many nodes do you want to create : "; cin >>N;
	
	cout << "Insert your node's value respectively : ";
	while(N--) {
		cin >> input;
		myTreeRoot = insert(myTreeRoot, input);
	}
	
	cout << "\nYour tree in preOrder traversal : "; preOrder(myTreeRoot);
	cout << "\nYour tree in inOrder traversal : "; inOrder(myTreeRoot);
	cout << "\nYour tree in postOrder traversal : "; postOrder(myTreeRoot);


	cout << "\nHow many numbers do you want to check : "; cin >> M;
	while (M--) {
		cout << "Number you want to check : ";
		cin >> input;
		if (search(myTreeRoot, input) != NULL)
			cout << input << " is in our tree\n";
		else
			cout << input << " is NOT in our tree\n";
	}
}

