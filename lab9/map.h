#pragma once

template <typename K, typename V>

class Map
{
	struct Element {

		K key;
		V value;
		int index;
	};
	Element* data;
	int count;
	int capacity;

	void Resize() {

		int new_capacity = capacity * 2; // dublam spatiul de stocare
		Element* new_data = new Element[new_capacity];
		for (int i = 0; i < count; i++) //am creat un nou array in care copiem valorile din vectorul initial
		{
			new_data[i] = data[i];
		}
		delete[] data;//sterg pointerul initial pentru a nu avea scurgeri de memorie
		data = new_data;
		capacity = new_capacity; //actualizez datele
	}

public:

	Map() {
		count = 0;
		capacity = 10;
		data = new Element[capacity];
	}
	~Map() {
		delete[] data;
	}

	V& operator[](const K& key) {

		for (int i = 0; i < count; i++)
		{
			if (data[i].key == key) {
				return data[i].value;
			}
		}

		if (count == capacity)
		{
			Resize();
		}

		//daca nu am gasit cheia atunci inseamna ca o adaugam la final

		data[count].key = key;
		data[count].index = count;
		count++;
		return data[count - 1].value;
	}


	struct Iterator {

		Element* ptr;

		bool operator !=(const Iterator& m) const { return ptr != m.ptr; };
		Iterator& operator++() { ptr++; return *this; };
		Element& operator*() { return *ptr; };
	};

	Iterator begin() { Iterator tmp; tmp.ptr = &data[0]; return tmp; };
	Iterator end() { Iterator tmp; tmp.ptr = &data[count]; return tmp; };


	int Count() {
		return count;
	}

	void Set(const K& key, const V& value) {

		for (int i = 0; i < count; i++)
		{
			if (data[i].key == key) {
				 data[i].value = value;
				 return;
			}
		}

		if (count == capacity)
		{
			Resize();
		}

		//daca nu am gasit cheia atunci inseamna ca o adaugam la final

		data[count].key = key;
		data[count].index = count;
		data[count].value = value;
		count++;
	}

	bool Get(const K& key, V& value) {

		for (int i = 0; i < count; i++)
		{
			if (data[i].key == key) {
				value = data[i].value;
				return true;
			}
		}

		return false;
	}

	void Clear() {
		count = 0;
	}

	bool Delete(const K& key) {

		for (int i = 0; i < count; i++)
		{
			if (data[i].key == key) {
				for (int j = i; j < count-1; j++)
				{
					data[j] = data[j + 1];
				}
				return true;
			}
		}

		return false;
	}

	bool Includes(const Map<K, V>& map) {

		if (map.Count() > count)
		{
			return false;
		}

		for (int i = 0; i < map.Count(); i++)
		{
			V temp;
			if (this->Get(map.data[i].key, temp) == false)
			{
				return false;
			}
		}
		return true;
	}




};

