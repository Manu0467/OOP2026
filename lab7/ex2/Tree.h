#pragma once
template <class T>
class Tree {
	struct node {
		T data;
		node* list[100];
		int cnt;
	};

	node tree[100];
	int index;

	node* find_recursive(node* curent, const T& element, bool (*compare)(const T&, const T&)) {

		if (compare(curent->data, element)) {
			return curent;
		}
		else {
			for (int i = 0; i < curent->cnt; i++)
			{
				node* rezultat = find_recursive(curent->list[i], element, compare);
				if (rezultat != nullptr) {
					return rezultat; 
				}
			}
		}
		return nullptr;
	}

	int count_rec(node* n) {

		if (n==nullptr)
		{
			return 0;
		}
		int sum = n->cnt;
		for (int i = 0; i < n->cnt; i++)
		{
			sum += count_rec(n->list[i]);
		}
		return sum;
	}

public:
	Tree() : index(0) {};
		
	void add_node(const T& value, node* parent=nullptr) {
		tree[index].data = value;
		tree[index].cnt = 0;
		if (parent!=nullptr)
		{
			parent->list[parent->cnt] = &tree[index];
			parent->cnt++;
		}
		this->index++;
	};

	node& get_node(node* parent, int i) {
		if (parent==nullptr)
		{
			return tree[0];
		}
		else {
			return *(parent->list[i]);
		}
	};

	void delete_node(node* n) {

		if (n == nullptr) return;
		for (int i = 0; i < n->cnt; i++)
		{
			delete_node(n->list[i]);
		}
		n->cnt = 0;
		n->data = T();
	
	};

	node* find(const T& element, bool (*compare)(const T&, const T&)) {
		return find_recursive(&tree[0], element, compare);
	}

	void insert(const  T& value, node* parent, int ind) {
		
		this->tree[index].data = value;
		this->tree[index].cnt = 0;
		
		for (int i = parent->cnt; i > ind; i--)
		{
			parent->list[i] = parent->list[i - 1];
		}
		parent->list[ind] = &tree[index];
		this->index++;
		parent->cnt++;
	};

	void sort(node* parent, bool (*compare)(const T&, const T&) = nullptr) {

		bool sorted;
		do
		{
			sorted = true;
			for (int i = 0; i < parent->cnt-1; i++)
			{
				bool swap = false;
				if (compare != nullptr)
				{
					if (compare(parent->list[i]->data, parent->list[i + 1]->data)) {
						swap = true;
					}
				}
				else {
					if (parent->list[i]->data > parent->list[i+1]->data)
					{
						swap = true;
					}
				}
				if (swap)
				{
					node* temp = parent->list[i];
					parent->list[i] = parent->list[i + 1];
					parent->list[i + 1] = temp;
					sorted = false;
				}
			}
			

		} while (!sorted);

	};

	int count(node* parent) {

		if (parent==nullptr)
		{
			if (this->index==0)
			{
				return 0;
			}
			else {
				return count_rec(&this->tree[0]);
			}
		}
		else {
			return count_rec(parent);
		}
	};
};