#include <iostream>
template <typename K, typename V>
class Map {
	struct Element {
		K key;
		V value;
		int count;
	} *vector;
	int count;
	int size;
	void Resize()
	{
		if (size != 0)
		{
			Element* v = new Element[size * 2];
			memcpy(v, vector, sizeof(Element) * size);
			vector = v;
			size = size * 2;
			return;
		}
		vector = new Element[1];
		size = 1;
		count = 0;
	}
public:
	Map()
	{
		vector = new Element[1];
		size = 1;
		count = 0;
	}
	~Map() 
	{
		Clear();
	}
	Element* begin() const { return &vector[0]; }
	Element* end() const { return &vector[count]; }
	V& operator [] (K key)
	{
		for (int i = 0; i < count; i++)
		{
			if (key == vector[i].key)
				return vector[i].value;
		}
		vector[count].count = count;
		vector[count].key = key;
		count++;
		if (count == size)
			Resize();
		return vector[count - 1].value;
	}
	void Set(K k, V v)
	{
		for (int i = 0; i < count; i++)
		{
			if (vector[i].key == k)
			{
				vector[i].value = v;
				size++;
				return;
			}
		}
		return;
	}
	bool Get(const K& k, V& v)
	{
		for (int i = 0; i < count; i++)
		{
			if (vector[i].key == k)
			{
				v = vector[i].value;
				return true;
			}
		}
		return false;
	}
	int Count() const
	{
		return count;
	}
	void Clear()
	{
		size = 0;
		count = 0;
		delete[] vector;
		vector = nullptr;
	}
	bool Delete(const K& k)
	{
		for (int i = 0; i < count; i++)
		{
			if (vector[i].key == k)
			{
				for (int j = i; j < count - 1; j++)
					vector[j] = vector[j + 1];
				count--;
				for (int m = 0; m < count; m++)
					vector[m].count = m;
				return true;
			}
		}
		return false;
	}

	bool Includes(const Map<K, V>& map)
	{
		if (count < map.count) return false;
		bool exists;
		for (int i = 0; i < map.count; i++)
		{
			exists = false;
			for (int j = 0; j < count; j++)
				if (vector[j].key == map.vector[i].key)
				{
					exists = true;
					break;
				}
			if (exists == false)
				return false;
		}
		return true;
	}
};

int main()
{
	Map<int, const char*> m;
	m[10] = "C++";
	m[20] = "test";
	m[30] = "Poo";
	Map<int, const char*>m2;
	m2[10] = "C++";
	if (m.Includes(m2))
		printf("includes\n");
	for (auto [key, value, index] : m)
	{
		printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
	}
	m[20] = "result";
	m.Set(30, "Set");
	printf("m.Set()\n");
	for (auto [key, value, index] : m)
	{
		printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
	}
	printf("m.Delete(10)\n");
	m.Delete(10);
	for (auto [key, value, index] : m)
	{
		printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
	}
	printf("get 20\n");
	const char* get;
	m.Get(20, get);
	printf("%s", get);
	printf("\nclear");
	m.Clear();
	for (auto [key, value, index] : m)
	{
		printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
	}
	
	return 0;
}