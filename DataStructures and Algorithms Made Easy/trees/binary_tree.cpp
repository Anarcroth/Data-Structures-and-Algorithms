/**
	COS: FDS
	binary_tree.cpp
	Purpose: Create an AVL tree holding any type.

	@author:	Martin Nestorov
	@version:	1.0.0 27/08/2017
*/

#include <iostream>
#include <iomanip>
#include <queue>
#include "binary_tree.h"

/**
	Insert a new element into the tree if the tree is not empty, otherwise create the root of the
	tree with the new element

	@param key		The element to be inserted.
*/
template<class T>
void BinaryTree<T>::insert(const T &key)
{
    if (root != nullptr)
    {
        insert(root, key);
    }
    else
    {
        root = new node<T>(key, nullptr, nullptr);
    }
}

/**
	Recursively insert the element into the proper position

	@param *root	A pointer to the parent of the current node.
	@param key		The element to be inserted.
*/
template<class T>
void BinaryTree<T>::insert(node<T> *&root, const T &key)
{
    if (root == nullptr)
    {
        root = new node<T>(key, nullptr, nullptr);
    }
    else if (key < root->key)
    {
        insert(root->left, key);

        if (height(root->left) - height(root->right) == 2)
        {
            if (key < root->left->key)
            {
                left_rotation(root);
            }
            else
            {
                double_left_rotation(root);
            }
        }
    }
    else if (key > root->key)
    {
        insert(root->right, key);

        if (height(root->right) - height(root->left) == 2)
        {
            if (key > root->right->key)
            {
                right_rotation(root);
            }
            else
            {
                double_right_rotation(root);
            }
        }
    }

    root->height = std::max(height(root->left), height(root->right)) + 1;
}

template<class T>
int BinaryTree<T>::height(node<T> *&root)
{
    return root != nullptr ? root->height : -1;
}

/**
	Find the node<T> that holds the searched element

	@param key		The element to be inserted.
*/
template<class T>
void BinaryTree<T>::find_key(const T &key)
{
    if (root != nullptr)
    {
        find_key(root, key);
    }
    else
    {
        std::cout << "The tree is empty.\n";
    }
}

/**
	Recursively find the node<T> that holds the searched element

	@param *root	A pointer to the parent of the current node<T>.
	@param key		The element to be inserted.
*/
template<class T>
void BinaryTree<T>::find_key(node<T> *&root, const T &key)
{
    if (key == root->key)
    {
        std::cout << "The found key is: " << root->key << std::endl;
    }
    else if (key < root->key && root->left != nullptr)
    {
        find_key(root->left, key);
    }
    else if (key >= root->key && root->right != nullptr)
    {
        find_key(root->right, key);
    }
    else
    {
        std::cout << "Could not find element.\n";
    }
}

template<class T>
void BinaryTree<T>::display_tree()
{
    if (root != nullptr)
    {
        display_tree(root, 0);
    }
    else
    {
        std::cout << "The tree is empty.\n";
    }
}

template<class T>
void BinaryTree<T>::display_tree(node<T> *&root, int indent)
{
    if ((bool) indent)
    {
        std::cout << std::setw(indent) << " ";
    }

    std::cout << root->key << std::endl;

    if (root->left != nullptr)
    {
        display_tree(root->left, indent + 4);
    }

    if (root->right != nullptr)
    {
        display_tree(root->right, indent + 4);
    }
}

template<class T>
void BinaryTree<T>::pre_order_traversal()
{
    if (root != nullptr)
    {
        pre_order_traversal(root);
    }
}

/**
 * Visit the root. Then go to the left subtree, the to the right one
 *
 * @param root		A pointer to the parent of the current node<T>.
 */
template<class T>
void BinaryTree<T>::pre_order_traversal(node<T> *&root)
{
    if (root != nullptr)
    {
        std::cout << root->key << " ";
        pre_order_traversal(root->left);
        pre_order_traversal(root->right);
    }
}

template<class T>
void BinaryTree<T>::post_order_traversal()
{
    if (root != nullptr)
    {
        post_order_traversal(root);
    }
}

/**
 * Visit the left node<T>. Then go to the right one, and lastly visit the root node<T>
 *
 * @param root		A pointer to the parent of the current node<T>.
 */
template<class T>
void BinaryTree<T>::post_order_traversal(node<T> *&root)
{
    if (root != nullptr)
    {
        post_order_traversal(root->left);
        post_order_traversal(root->right);
        std::cout << root->key << " ";
    }
}

template<class T>
void BinaryTree<T>::in_order_traversal()
{
    if (root != nullptr)
    {
        in_order_traversal(root);
    }
}

/**
 * Visit the most left node<T>. Then go to the parent node<T>, the to the right one
 *
 * @param root		A pointer to the parent of the current node<T>.
 */
template<class T>
void BinaryTree<T>::in_order_traversal(node<T> *&root)
{

    if (root != nullptr)
    {
        in_order_traversal(root->left);
        std::cout << root->key << " ";
        in_order_traversal(root->right);
    }
}

template<class T>
void BinaryTree<T>::level_order_traversal()
{
    if (root != nullptr)
    {
        level_order_traversal(root);
    }
}

/*
 * Visit each node of the tree by levels, displaying them from the top down
 *
 * @param root      A pointer to the parent of the current node<T>/
 */
template<class T>
void BinaryTree<T>::level_order_traversal(node<T> *&root)
{
    std::queue<node<T> *> queue;

    queue.push(root);

    while (true)
    {
        unsigned long node_count = queue.size();

        if (node_count == 0) break;

        while (node_count > 0)
        {
            node<T> *temp = queue.front();

            std::cout << temp->key << " ";

            queue.pop();

            if (temp->left != nullptr) queue.push(temp->left);

            if (temp->right != nullptr) queue.push(temp->right);

            node_count--;
        }

        std::cout << std::endl;
    }
}

template<class T>
void BinaryTree<T>::right_rotation(node<T> *&root)
{
    auto *temp = root->right;
    root->right = temp->left;
    temp->left = root;

    root->height = std::max(height(root->left), height(root->right)) + 1;
    temp->height = std::max(height(temp->left), height(temp->right)) + 1;
    root = temp;
}

template<class T>
void BinaryTree<T>::double_right_rotation(node<T> *&root)
{
    left_rotation(root->right);
    right_rotation(root);
}

template<class T>
void BinaryTree<T>::left_rotation(node<T> *&root)
{
    auto *temp = root->left;
    root->left = temp->right;
    temp->right = root;

    root->height = std::max(height(root->left), height(root->right)) + 1;
    temp->height = std::max(height(temp->left), height(temp->right)) + 1;
    root = temp;
}

template<class T>
void BinaryTree<T>::double_left_rotation(node<T> *&root)
{
    right_rotation(root->left);
    left_rotation(root);
}

/**
	Recursively delete the tree from the children to the root

	@param *root	A pointer to the parent of the current node<T>.
*/
template<class T>
void BinaryTree<T>::delete_tree(node<T> *&root)
{
    if (root != nullptr)
    {
        delete_tree(root->left);
        delete_tree(root->right);
    }

    root->left = nullptr;
    root->right = nullptr;
    delete root;
}

template<class T>
BinaryTree<T>::~BinaryTree()
{
    delete_tree(root);
}
/*
nt main()
{
    BinaryTree<int> binary_tree;

    int answer = 0, elem = 0;

    std::cout << "----- Binary Tree Menu -----\n";

    std::cout << "1. Insert element to the tree.\n";
    std::cout << "2. Find element from the tree.\n";
    std::cout << "3. Display contents of the tree.\n";
    std::cout << "4. Choose traversal method.\n";
    std::cout << "5. Quit.\n";

    do
    {
        std::cout << "\nTake action: ";
        std::cin >> answer;

        switch (answer)
        {
            case 1:
                std::cout << "Enter an element: ";
                std::cin >> elem;

                binary_tree.insert(elem);
                break;

            case 2:
                std::cout << "Enter an element: ";
                std::cin >> elem;

                binary_tree.find_key(elem);
                break;

            case 3:
                binary_tree.display_tree();

                break;

            case 4:
                std::cout << "1. Post Order Traversal.\n";
                std::cout << "2. In Order Traversal.\n";
                std::cout << "3. Pre Order Traversal.\n";
                std::cout << "4. Level Order Traversal.\n";

                std::cout << "Take action: ";
                std::cin >> answer;

                switch (answer)
                {
                    case 1:
                        binary_tree.post_order_traversal();
                        break;

                    case 2:
                        binary_tree.in_order_traversal();
                        break;

                    case 3:
                        binary_tree.pre_order_traversal();
                        break;

                    case 4:
                        binary_tree.level_order_traversal();
                        break;

                    default:
                        continue;
                }
                break;

            case 5:
                exit(0);

            default:
                continue;
        }

    } while ((bool) answer);

    return 0;
}
*/