#include "Header.h"

template <typename T> //освобождаем памяти
inline stack<T>::~stack()
{
	delete[] array_;
}

template <typename T> //конструктор по умолчанию
inline stack<T>::stack() :count_(0), array_size_(0), array_(nullptr) {};

template <typename T> //вставляем эл-нт в стэк 
inline auto stack<T>::push(T const &com)->void {
	if (array_ == nullptr) {
		array_ = new T[1];
		array_[0] = com;
		count_++; array_size_++;
	}
	else {
		if (count_ == array_size_) {
			T *tmp = array_;
			array_size_ *= 2;
			array_ = new T[array_size_];
			std::copy(tmp, tmp + count_, array_);
			delete[] tmp;

		}
		array_[count_] = com;
		count_++;

	}
}

template <typename T> //конструктор копирования
inline stack<T>::stack(const stack&tmp) :count_(tmp.count_), array_size_(tmp.array_size_), array_(new T[tmp.array_size_]) {
	array_ = new T[array_size_];
	copy(tmp.array_, tmp.array_ + count_, array_);
}

template <typename T> //перегружаем оператор присваивания 
inline auto stack<T>::operator=(const stack&tmp)->stack& {
	if (this != &tmp) {
		delete[] array_;
		count_ = tmp.count_;
		array_size_ = tmp.array_size_;
		array_ = new T[array_size_];
		copy(tmp.array_, tmp.array_ + count_, array_);
	}
	return *this;
}

template <typename T> // выводим стэк
inline auto stack<T>::print()->void {
	for (size_t i(0); i < count_; i++) cout << array_[i] << endl;
}

template <typename T> //возвращаем count_
inline auto stack<T>::count() const noexcept->size_t {
	return count_;
}

template <typename T> // уменьшаем count_ 
inline auto stack<T>::pop()->T {
	if (count_ == 0) throw logic_error("Empty!");
	return --count_;
}

template <typename T> //удаляем эл-нт
inline auto stack<T>::top() const->T& {
	if (count_ == 0) throw logic_error("Empty!");
	return array_[count_];

}