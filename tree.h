#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

#ifndef Binary_Search_Tree
#define Binary_Search_Tree

template<class T> class Tree;

template<class T>
class Node {
public:
	Node() { left = right = NULL; }
	Node(const T& el, Node *l = 0, Node *r = 0) {
		key = el; left = l; right = r;
	}
	T key;
	Node *left, *right;
};

template<class T>
class Tree {
public:
	Tree() { root = 0; }
	~Tree() { clear(); }
	void clear() { clear(root); root = 0; }
	bool isEmpty() { return root == 0; }
	void inorder() { inorder(root); }
	void insert(const T& el);
	void deleteNode(Node<T> *& node);
	void visit(Node<T> *p);
	int getheight(Node<T> *p);
	int getheight() { return getheight(root); }
	void search(Node<T>* p, const T& el);
	Node<T> *root;


protected:

	void clear(Node<T> *p);
	void inorder(Node<T> *p);

};
template<class T>
int Tree<T>::getheight(Node<T> *p)
{
	if (p == 0) {
		return -1;
	}
	else {
		return max(getheight(p->left), getheight(p->right)) + 1;
	}
}

template<class T>
void Tree<T>::clear(Node<T> *p)
{
	if (p != 0) {
		clear(p->left);
		clear(p->right);
		delete p;
	}
}
template<class T>
void Tree<T>::inorder(Node<T> *p) {
	if (p != 0) {
		inorder(p->left);
		visit(p);
		inorder(p->right);
	}

}

template<class T>
void Tree<T>::insert(const T &el) {
	Node<T> *p = root, *prev = 0;

	while (p != 0) {
		prev = p;
		if (p->key < el)
			p = p->right;
		else
			p = p->left;
	}
	if (root == 0)
		root = new Node<T>(el);
	else if (prev->key<el)
		prev->right = new Node<T>(el);
	else
		prev->left = new Node<T>(el);
}
template<class T>
void Tree<T>::visit(Node<T> *p)
{
	cout << p->key << "<<---IN TREE" << endl;

}



template<class T>
void Tree<T>::deleteNode(Node<T> *&node) {
	Node<T> *prev, *tmp = node;
	if (node->right == 0)
		node = node->left;
	else if (node->left == 0)
		node = node->right;
	else {
		tmp = node->left;
		prev = node;
		while (tmp->right != 0) {
			prev = tmp;
			tmp = tmp->right;
		}
		node->key = tmp->key;
		if (prev == node)
			prev->left = tmp->left;
		else prev->right = tmp->left;
	}
	delete tmp;
}

template<class T>
void Tree<T>::search(Node<T>* p, const T& el)
{
	if (p != NULL){
		while (p != NULL)
		{
			if (el == p->key)
			{
				cout <<"Number "<< el << " is in your tree." << endl;
				break;
			}

			else if (el < p->key)
			{
				p = p->left;
			}
			else
			{
				p = p->right;
			}
		}
	}
	if (p == 0)
	{
		cout <<"Number "<< el <<" isn't in your tree." << endl;
	}
	//Doesn't have delete function.
}

#endif
