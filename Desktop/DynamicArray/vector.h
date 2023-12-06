#ifndef DYNAMIC_ARRAY
#define DYNAMIC_ARRAY

#include <iostream>
#include <initializer_list>
#include <utility>

template <typename T>
class Vector {
public:
	//iterators classes
	class const_iterator {
	public:
		const_iterator(const T* ptr) : m_ptr(ptr){}
		const_iterator& operator++() {
		++m_ptr;
		return *this;
	}
		const_iterator operator++ (int) {//postfix 
			const_iterator tmp = *this;
			++(*this);
			return tmp;
	}
	const T& operator*() {
		return *m_ptr;
	}
	bool operator!= (const_iterator& oth) const {
		return m_ptr != oth.m_ptr;
	}
	const_iterator begin() const {
		return const_iterator(data);
	}
	const_iterator end() const {
		return const_iterator(data + len);
	}
	private:
		const T* m_ptr;
	};
//const iter impl
	class iterator : public const_iterator {
	public:
		iterator(T* ptr) : const_iterator(ptr){}
		iterator& operator++() {
			const_iterator::operator++();
			return *this;
		}
		iterator operator++(int) { // postfix 
			iterator tmp = *this;
			++(*this);
			return tmp;
		}
		T& operator*() {
			return const_cast<T&>(const_iterator::operator*());
		}
		iterator begin() {
			return iterator(data);
		}
		iterator end() {
			return iterator(data + len);
		}
		private:
			T *m_ptr;
	};

public:
	//ctors
	Vector();
	Vector(const Vector&);
	Vector(Vector&&) noexcept;//no throw excdeption if i have copy and move select move not copy all of source data to dest :)
	Vector(size_t, size_t);

	~Vector();

	size_t vec_size() const;
	size_t vec_cap() const;

	Vector(std::initializer_list<T>);

	Vector& operator=(const Vector&);
	Vector& operator=(Vector&&) noexcept;
	T& operator[](size_t);

	template <typename U>
	friend std::istream& operator>> (std::istream&, Vector<U>&);

	template <typename U>
	friend std::ostream& operator<< (std::ostream&, const Vector<U>&);
	
	// member functions
	void push_back(T value);//O(1)
	void push_back(T(&arr)[3]);//pass to Static Arr
	void push_back(int val, int count);

	void pop_back();//O(1)

	void shrink_to_fit();//shrink free space but remain >= len space - O(n)

	void insert(T value, size_t idx);//O(n)
	void insert(T(&arr)[2], size_t idx);//which index arrayv`	void insert(T val, int count, size_t idx);
	void insert(T , int count, size_t);
	
	void deleteItem(int idx);//O(n)
	void deleteItem(int idx, int count);

	void search(T val);//O(n)

	void resize(size_t newSize,int count = 0);//defualt need to be 0  O(n)
	
private:
	T* data;
	size_t len;
	size_t cap;
};
#include "vector.tpp"
#endif //DynamicArray_H
