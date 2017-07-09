#include <iostream>

struct node
{
	int key;
	node *left;
	node *right;
};

class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();

	void insert(int key);
	node find_key(int key);
	void delete_tree();

private:

	void insert(node *root, int key);
	node find_key(node *nd, int key);
	void delete_tree(node *root);

	node *root;
};

BinaryTree::BinaryTree() : root(NULL) {}

void BinaryTree::insert(int key)
{
	if (root != NULL)
		insert(root, key);
	else
	{
		root = new node;
		root->key = key;
		root->left = NULL;
		root->right = NULL;
	}
}

void BinaryTree::insert(node *root, int key)
{
	if (key < root->key)
	{
		if (root->left != NULL)
			insert(root->left, key);
		else
		{
			root->left = new node;
			root->left->key = key;
			root->left->left = NULL;
			root->left->right = NULL;
		}
	}
	else
	{
		if (root->right != NULL)
			insert(root->right, key);
		else
		{
			root->right = new node;
			root->right->key = key;
			root->right->left = NULL;
			root->right->right = NULL;
		}
	}
}

node BinaryTree::find_key(int key)
{
	if (root != NULL)
		return find_key(root, key);
	else
		return *root;
}

node BinaryTree::find_key(node *nd, int key)
{
	if (key == nd->key)
		return *nd;
	else if (key < nd->key)
		find_key(nd->left, key);
	else
		find_key(nd->right, key);
}

void BinaryTree::delete_tree(node *root)
{
	if (root != NULL)
	{
		delete_tree(root->left);
		delete_tree(root->right);
	}

	root->left = NULL;
	root->right = NULL;
	delete root;
}

BinaryTree::~BinaryTree()
{
	delete_tree(root);
}

int main()
{
	BinaryTree bt;
	int num;

	for (size_t i = 0; i < 10; i++)
	{
		std::cin >> num;
		bt.insert(num);
	}

	return 0;
}