#pragma once

template<typename T>

class Vector
{
public:
	Vector() {
		array = new T[0];
		size_now = 0;
	}

	Vector(const int& a) {
		array = new T[a + 1];
		size_now = a;
	}

	~Vector() {
		delete[] array;
		size_now = 0;
	}

	void addMemory() {
		int new_size = size_now + 1;
		T* tmp = array;
		array = new T[new_size];
		for (int i = 0; i < size_now; ++i) array[i] = tmp[i];
		delete[] tmp;
	}

	void push_back(const T& new_value) {
		addMemory();
		array[size_now] = new_value;
		size_now++;
	}

	void pop_back() {
		if (size_now == 0)
			throw "Error";
		int new_size = size_now;
		T* tmp = array;
		array = new T[new_size];
		for (int i = 0; i < size_now - 1; ++i) array[i] = tmp[i];
		delete[] tmp;
		size_now--;
	}

	void resize(const int& new_size) {
		T* tmp = array;
		array = new T[new_size];
		for (int i = 0; i < size_now; ++i) array[i] = tmp[i];
		delete[] tmp;
		size_now = new_size;
	}

	T front() {
		if (size_now == 0)
			throw "Error";
		return array[0];
	}

	T end() {
		if (size_now == 0)
			throw "Error";
		return array[size_now - 1];
	}

	int size() {
		return size_now;
	}

	bool empty() {
		return (size_now == 0);
	}

	T& operator[](int index) {
		if (index >= size_now)
			throw "Error";
		return array[index];
	}

private:
	T* array;
	int size_now;
};

