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
			cout << leaf->value << " ";
			print(leaf->right);
		}
	}

	// Поиск узла по значению элемента
	Element* findNode(int valueFind) {
		Element* node = root;

		while (node != nullptr) {
			if (valueFind == node->value) {
				//cout << "Узел нашли " << valueFind << endl;				
				return node;// Возвращаем адрес узла
			}
			if (valueFind < node->value) {
				node = node->left;
			}
			else {
				node = node->right;
			}
		}
		cout << "Узел не нашли " << valueFind << endl;
		return nullptr;
	};

	// Поиск макисмальньо и минимального элемента заданного узла
	void maxMinNode(Element* bazeNode) {
		if (bazeNode == nullptr) {
			cout << "Такого узла не существует" << endl;
			return;
		}
		// Ищим максимальный элемент данного узла. Самая правая ветка до конца
		Element* temp = bazeNode;
		int max = temp->value;

		while (temp != nullptr) {
			if (max < temp->value) {
				max = temp->value;				
			}
			temp = temp->right;
		}
		// Ищим максимальный элемент данного узла. Самая правая ветка до конца
		temp = bazeNode;
		int min = temp->value;

		while (temp != nullptr) {
			if (min > temp->value) {
				min = temp->value;
			}
			temp = temp->left;
		}
		cout << "Максимальный элемент данного узла:\t" << max << endl;
		cout << "Минимальный элемент данного узла:\t" << min << endl;
	}

	// Поиск макисмального и минимального числа по всему дереву независимо от входного узла
	void maxMinTree(Element* bazeNode) {
		if (bazeNode == nullptr) {
			cout << "Такого узла не существует" << endl;
			return;
		}
		// Находим родителя
		while (bazeNode->parents != nullptr) {
			if (bazeNode->parents != nullptr) {
				bazeNode = bazeNode->parents;
			}
		}
		// Заупскаем поиск в главного родителя по всему дереву
		maxMinNode(bazeNode);
	}
};


int main(){
	srand(time(0));
	setlocale(LC_ALL, "RUS");

	int const SIZE = 500;
	Element element[SIZE];

	for (int i = 0; i < SIZE; i++) {
		int randValue = rand() % 50 + 1;
		element[i].value = randValue;
		cout << element[i].value << " ";
	}
	cout << endl;
   
	Tree tree;
	for (int i = 0; i < SIZE; i++) {
		tree.insert(&element[i]);
	}
	cout << "Отсортированый массив ";
	tree.print(&element[0]);

	cout << "\n Введите узел для анализа: ";
	int userValure;
	cin >> userValure;
	Element* findNode = tree.findNode(userValure);	
	
	tree.maxMinNode(findNode);

	tree.maxMinTree(findNode);
}
