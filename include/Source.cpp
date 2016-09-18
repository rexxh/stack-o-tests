#include "Header.h"

template <typename T>//копирование и выделение памяти 
auto stack<T>::mem_copy(size_t count_m, size_t array_size_m, const T * tmp)->T* {
	T *mass = new T[array_size_m];
	copy(tmp,tmp+count_m,mass);
	return mass; 
}

template <typename T> //îñâîáîæäàåì ïàìÿòè
inline stack<T>::~stack()
{
	delete[] array_;
}

template <typename T> //êîíñòðóêòîð ïî óìîë÷àíèþ
inline stack<T>::stack() :count_(0), array_size_(0), array_(nullptr) {};

template <typename T> //âñòàâëÿåì ýë-íò â ñòýê 
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

template <typename T> //êîíñòðóêòîð êîïèðîâàíèÿ
inline stack<T>::stack(const stack&tmp) :count_(tmp.count_), array_size_(tmp.array_size_), array_(new T[tmp.array_size_]) {
	array_ = new T[array_size_];
	copy(tmp.array_, tmp.array_ + count_, array_);
}

template <typename T> //ïåðåãðóæàåì îïåðàòîð ïðèñâàèâàíèÿ 
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

template <typename T> // âûâîäèì ñòýê
inline auto stack<T>::print()->void {
	for (size_t i(0); i < count_; i++) cout << array_[i] << endl;
}

template <typename T> //âîçâðàùàåì count_
inline auto stack<T>::count() const noexcept->size_t {
	return count_;
}

template <typename T> // óìåíüøàåì count_ 
inline auto stack<T>::pop()->T {
	if (count_ == 0) throw logic_error("Empty!");
	return --count_;
}

template <typename T> //óäàëÿåì ýë-íò
inline auto stack<T>::top() const->T& {
	if (count_ == 0) throw logic_error("Empty!");
	return array_[count_];

}
