#include "stack.h"

template<typename T> 
auto stack<T>::empty() const noexcept->bool {
	return (allocator<T>::count_ == 0);

template <typename T>
auto mem_copy(size_t count_m, size_t array_size_m, const T * tmp)->T* {
	T *mass = new T[array_size_m];
	std::copy(tmp, tmp + count_m, mass);
	return mass;
}


template <typename T>
stack<T>::~stack() {
destroy(allocator<T>::array_, allocator<T>::array_ + allocator<T>::count_);};

template <typename T>
stack<T>::stack()  {};



template <typename T>
auto stack<T>::push(T const &val)->void {
	if (allocator<T>::count_ == allocator<T>::size_) {
		size_t size = allocator<T>::size_ * 2 + (allocator<T>::size_ == 0);
		T *tmp = mem_copy(allocator<T>::count_, size, allocator<T>::array_);
		delete[] allocator<T>::array_;
		allocator<T>::array_ = tmp;
		allocator<T>::size_ = size;
	}
	construct(allocator<T>::array_+allocator<T>::count_,val);
	++allocator<T>::count_;
}


template <typename T>
stack<T>::stack(stack const &tmp) {
	allocator<T>::count_ = tmp.count_;
	allocator<T>::array_ = mem_copy(tmp.count_, tmp.size_, tmp.array_);
	allocator<T>::size_ = tmp.size_;
};

template <typename T>
auto stack<T>::operator=(const stack &tmp)->stack& {
	if (this != &tmp) {
		T* cp = mem_copy(tmp.count_, tmp.size_, tmp.array_);
		delete[] allocator<T>::array_; 
		allocator<T>::array_ = cp;
		allocator<T>::size_ =tmp.size_;
		allocator<T>::count_ = tmp.count_;
	}
	return *this;
}


template <typename T>
auto stack<T>::count() const noexcept->size_t {
	return allocator<T>::count_;
}

template <typename T>
auto stack<T>::pop()->void {
	if (allocator<T>::count_ == 0) throw std::logic_error("Empty!");
	destroy(allocator<T>::array_+allocator<T>::count_);
	--allocator<T>::count_;
}

template <typename T>
auto stack<T>::top() const->T& {
	if (allocator<T>::count_ == 0) throw std::logic_error("Empty!");
	return allocator<T>::array_[allocator<T>::count_-1];

}
