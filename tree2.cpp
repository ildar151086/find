#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct Element {
	int value;
	Element* left;
	Element* right;
	Element* parents;
};

class Tree {
	Element* root;
public:
	Tree() {
		root = nullptr;
	}
	void insert(Element* leaf) {
		//cout << leaf->value << " ";
		leaf->left  = nullptr;
		leaf->right = nullptr;
		Element* node = root;
		Element* temp = nullptr;

		while (node != nullptr) {
			temp = node;
			if (leaf->value < node->value) {
				node = node->left;
			}
			else {
				node = node->right;
			}
		}
		leaf->parents = temp;

		if (temp == nullptr) {
			root = leaf;
		} else 
			if (leaf->value < temp->value) {
				temp->left = leaf;
			} else {
				temp->right = leaf;
			}
	}
	void print(Element* leaf) {
		if (leaf != nullptr) {
			print(leaf->left);
			cout << leaf->value << endl;
			print(leaf->right);
		}
	}

	bool find(int valueFind) {
		Element* node = root;
		while (node != nullptr) {
			if (valueFind == node->value) {
				cout << "Число нашли " << valueFind;
				return true;
			}
			if (valueFind < node->value) {
				node = node->left;
			}
			else {
				node = node->right;
			}
		}
		cout << "Число не нашли " << valueFind;
		return false;
	}
};


int main(){
	srand(time(0));
	setlocale(LC_ALL, "RUS");

	int const SIZE = 5;
	Element element[SIZE];

	for (int i = 0; i < SIZE; i++) {
		element[i].value = rand() % 30;
		//cout << element[i].value << " ";
	}
	cout << endl;
   
	Tree tree;
	for (int i = 0; i < SIZE; i++) {
		tree.insert(&element[i]);
	}
	tree.print(&element[0]);

	int user = -1;
	cout << " Что нам найти ";
	cin >> user;
	tree.find(user);
}
