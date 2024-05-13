#pragma once
#include <iostream>
#include <exception>
using namespace std;

class exceptie2 : public exception
{
	virtual const char* what() const throw()
	{
		return "Indexul este inafara domeniului!";
	}
};

class Compare
{
public:
	virtual int CompareElements(void* e1, void* e2) = 0;
};
template<class T>
class ArrayIterator
{
private:
	int Current; // mai adaugati si alte date si functii necesare pentru iterator
public:
	T** p;
	ArrayIterator<T>& operator++() { p++; return *this; }
	bool operator != (ArrayIterator m) { return p != m.p; }
	T* operator* () { return *p; }
	ArrayIterator()
	{
		Current = 0;
		p = nullptr;
	}
	
	
	
};

template <class T>
class Array
{
private:
	T** List; // Lista cu pointeri la obiecte de tipul T*
	int Capacity; // dimensiunea listei de pointeri
	int Size; // cate elemente sunt in lista
	exceptie2 index_out_of_bounds;
public:
	ArrayIterator<T> begin() { ArrayIterator<T> tmp; tmp.p = &List[0]; return tmp; }
	ArrayIterator<T> end() { ArrayIterator<T> tmp; tmp.p = &List[Size]; return tmp; }
	Array()
	{
		Capacity = 0;
		Size = 0;
		List = nullptr;
	}
	~Array()
	{
		for (int i = 0; i < Capacity; i++)
			delete List[i];
		delete[] List;
	}
	Array(int capacity)
	{
		if (capacity <= 0)
			throw "Error capacity";
		Capacity = capacity;
		Size = 0;
		List = new T * [capacity];
		for (int i = 0; i < capacity; i++)
			List[i] = new T;
	}
	Array(const Array<T>& otherArray)
	{
		Capacity = otherArray.Capacity;
		Size = otherArray.Size;
		List = new T * [Capacity];
		for (int i = 0; i < otherArray.Capacity; i++)
		{
			List[i] = new T;
			*List[i] = *otherArray.List[i];
		}
	}

	T& operator[] (int index)
	{
		if (index < 0 || index >= Capacity)
			throw exceptie2();
		return *(List[index]);
	}

	const Array<T>& operator+=(const T& newElem)
	{
		if (Size == Capacity)
			throw "Error: max capacity reached";
		*(List[Size++]) = newElem;
		return *this;
	}
	const Array<T>& Insert(int index, const T& newElem)
	{
		if (index < 0 || index >= Capacity)
			throw index_out_of_bounds;
		if (index != 0 && index >= Size)
			throw "Error: index = Size";

		for (int i = Capacity - 1; i > index; i--)
			*List[i] = *List[i - 1];
		*(List[index]) = newElem;
		if (Size != Capacity)
			Size++;
		return *this;
	}
	const Array<T>& Insert(int index, const Array<T> otherArray)
	{
		if (otherArray.Size > Capacity)
			throw "Error: size > capacity";
		if (index + otherArray.Capacity > Capacity)
			throw "Error: index + otherCapacity > List's Capacity.";
		if (index < 0 || index > Capacity)
			throw index_out_of_bounds;
		if (index != 0 && index >= Size)
			throw "Error: index =size";

		for (int i = Capacity - 1; i > index; i--)
			if (i - otherArray.Size >= index)
				*List[i] = *List[i - otherArray.Size];
			else
				break;
		for (int i = index; i < otherArray.Size; i++)
			*List[i] = *otherArray.List[i - index];
		if (Size + otherArray.Size > Capacity)
			Size = Capacity;
		else
			Size = Size + otherArray.Capacity;
		return *this;
	}

	const Array<T>& Delete(int index)
	{
		if (index < 0 || index >= Capacity)
			throw index_out_of_bounds;
		if (index != 0 && index >= Size)
			throw "Error: index =.";
		if (Size == 0)
			throw "Error: Size =0";

		for (int i = index; i < Size - 1; i++)
			*List[i] = *List[i + 1];
		Size--;
		return *this;
	}

	bool operator=(const Array<T>& otherArray)
	{
		if (otherArray.Size == 0)
			throw "Error: cannot copy empty List.";
		if (otherArray.Capacity != Capacity)
			throw "Error: capacity";
		for (int i = 0; i < Capacity; i++)
			*List[i] = *otherArray.List[i];
		Size = otherArray.Size;
		return true;
	}


	void Sort()
	{
		T aux;
		bool ok;

		do
		{
			ok = true;
			for (int i = 0; i < Size - 1; i++)
				if (*List[i] > *List[i + 1])
				{
					aux = *List[i];
					*List[i] = *List[i + 1];
					*List[i + 1] = aux;
					ok = false;
				}
		} while (!ok);
	}

	void Sort(int(*compare)(const T&, const T&))
	{
		if (compare == nullptr)
			throw "Error: invalid compare function";
		T aux;
		bool ok;

		do
		{
			ok = true;
			for (int i = 0; i < Size - 1; i++)
				if (compare(*List[i], *List[i + 1]) < 0)
				{
					aux = *List[i];
					*List[i] = *List[i + 1];
					*List[i + 1] = aux;
					ok = false;
				}
		} while (!ok);
	}

	// sorteaza folosind un obiect de comparatie
	void Sort(Compare* comparator)
	{
		if (comparator == nullptr)
			throw "Error: comparator =nullptr";
		T aux;
		bool ok;

		do
		{
			ok = true;
			for (int i = 0; i < Size - 1; i++)
				if (comparator->CompareElements(static_cast<void*>(List[i]), static_cast<void*>(List[i + 1])) > 0)
				{
					aux = *List[i];
					*List[i] = *List[i + 1];
					*List[i + 1] = aux;
					ok = false;
				}
		} while (!ok);
	}



	// functii de cautare - returneaza pozitia elementului sau -1 daca nu exista

	int BinarySearch(const T& elem)
	{
		if (Size == 0 || Capacity == 0)
			throw "Error: array is empty";

		int st = 0, dr = Size - 1;
		int mij;
		while (st <= dr)
		{
			mij = (st + dr) / 2;
			if (*List[mij] == elem)
				return mij;
			if (*List[mij] < elem)
				st = mij + 1;
			else
				dr = mij - 1;
		}
		return -1;
	}

	int BinarySearch(const T& elem, int(*compare)(const T&, const T&))
	{
		if (Size == 0 || Capacity == 0)
			throw "Error: array is empty";

		int st = 0, dr = Size - 1;
		int mij;
		while (st <= dr)
		{
			mij = (st + dr) / 2;
			if (compare(elem, *List[mij]) == 0)
				return mij;
			if (compare(elem, *List[mij]) > 0)
				st = mij + 1;
			else
				dr = mij - 1;
		}
		return -1;
	}

	int BinarySearch(const T& elem, Compare* comparator)
	{
		if (Size == 0 || Capacity == 0)
			throw "Error: array is empty";

		T elem_nonconst = elem;

		int st = 0, dr = Size - 1;
		int mij;
		while (st <= dr)
		{
			mij = (st + dr) / 2;
			if (comparator->CompareElements(static_cast<void*>(List[mij]), static_cast<void*>(&elem_nonconst)) == 0)
				return mij;
			if (comparator->CompareElements(static_cast<void*>(List[mij]), static_cast<void*>(&elem_nonconst)) < 0)
				st = mij + 1;
			else
				dr = mij - 1;
		}
		return -1;
	}


	int Find(const T& elem)
	{

		for (int i = 0; i < Size; i++)
			if (*List[i] == elem)
				return i;
		return -1;
	}

	int Find(const T& elem, int(*compare)(const T&, const T&))
	{
		for (int i = 0; i < Size; i++)
			if (compare(elem, *List[i]) == 0)
				return i;
		return -1;
	}

	int Find(const T& elem, Compare* comparator)
	{
		T nonconstcopy = elem;
		for (int i = 0; i < Size; i++)
			if (comparator->CompareElements(static_cast<void*>(List[i]), static_cast<void*>(&nonconstcopy)) == 0)
				return i;
		return -1;
	}


	int GetSize()
	{
		return Size;
	}

	int GetCapacity()
	{
		return Capacity;
	}


	ArrayIterator<T> GetBeginIterator()
	{
		ArrayIterator it;
		return it;
	}

	ArrayIterator<T> GetEndIterator()
	{
		ArrayIterator it(Size - 1);
		return it;
	}
};
class Compare2 : public Compare
{
public:
	int CompareElements(void* e1, void* e2)
	{
		int* e1_int = static_cast<int*>(e1);
		int* e2_int = static_cast<int*>(e2);
		return *e1_int - *e2_int;
	}
};

int main()
{
	try {
		Array<int> a(5);
		a += 150;
		a += 200;
		a += 307;
		Array<int> b(6);
		Array<int> l(6);
		Array<int> l2(6);
		b += 400;
		b += 300;
		b += 200;
		b += 100;
		b.Insert(0, a);
		b.Insert(0, 5); //exceptie
		l = b;
		l2 = l;
		l2.Sort([](const int& x, const int& y) ->int { return x > y ? -1 : 1; });
		for (int i = 0; i < l2.GetSize(); i++)
			std::cout << l2[i] << ' ';
		std::cout << std::endl;
		Compare2* c = new Compare2();
		l.Sort(c);
		for (int i = 0; i < l.GetSize(); i++)
			std::cout << l[i] << ' ';
		std::cout << std::endl;
		for (ArrayIterator<int> it = l.begin(); it != l.end(); ++it) {
			std::cout << **it << " ";
		}
		std::cout << std::endl;
		std::cout << "400 se afla pe pozitia " << l.BinarySearch(400) << std::endl;
		std::cout << "300 se afla pe pozitia " << l.BinarySearch(300, c) << std::endl;
		std::cout << "500 se afla pe pozitia " << l.BinarySearch(500, c) << std::endl;
		std::cout << "10 se afla pe pozitia " << l.Find(10, c) << std::endl;

		b.Sort();
		for (int i = 0; i <= b.GetSize(); i++)
			std::cout << b[i] << ' ';
		std::cout << std::endl;


	}
	catch (exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
