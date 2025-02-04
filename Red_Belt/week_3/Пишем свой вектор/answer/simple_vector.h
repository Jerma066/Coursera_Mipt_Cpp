#pragma once

#include <cstdlib>

// Реализуйте шаблон SimpleVector
template <typename T>
class SimpleVector {
public:
	  SimpleVector();
	  explicit SimpleVector(size_t size);
	  ~SimpleVector();

	  T& operator[](size_t index);

	  T* begin();
	  T* end();
	  const T* begin() const;
	  const T* end() const;

	  size_t Size() const;
	  size_t Capacity() const;
	  void PushBack(const T& value);

private:
	size_t _size = 0;
	size_t _capacity = 0;
	T* _data = nullptr;
	T* _end = nullptr;
};

template <typename T>
SimpleVector<T>::SimpleVector():
	_size(0),
	_capacity(0),
	_data(nullptr),
	_end(nullptr)
{
}

template <typename T>
SimpleVector<T>::SimpleVector(size_t size):
	_size(size),
	_capacity(size)
{
	_data = new T[size];
	_end = _data + size;
}

template <typename T>
T& SimpleVector<T>::operator[](size_t index) {
	return _data[index];
}

template <typename T>
SimpleVector<T>::~SimpleVector() {
	delete[] _data;
}

template <typename T>
T* SimpleVector<T>::begin() {
  return _data;
}

template <typename T>
T* SimpleVector<T>::end() {
  return _end;
}

template <typename T>
const T* SimpleVector<T>::begin() const {
  return _data;
}

template <typename T>
const T* SimpleVector<T>::end() const {
  return _end;
}

template <typename T>
size_t SimpleVector<T>::Capacity() const {
	return _capacity;
}

template <typename T>
size_t SimpleVector<T>::Size() const {
	return _size;
}

template <typename T>
void SimpleVector<T>::PushBack(const T& value) {
	if (Size() == 0) {
		_capacity++;
		_data = new T[_capacity];
	}
	else if (Size() == Capacity()) {
		T* old_data = _data;
		_capacity *= 2;
		_data = new T[_capacity];

		for (size_t i = 0; i < Size(); ++i) {
			_data[i] = old_data[i];
		}

		delete[] old_data;
	}

	_data[_size] = value;
	_size++;
	_end = _data + _size;
}
