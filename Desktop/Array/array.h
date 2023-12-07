#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
#include <bitset>

template <typename T, size_t N>
class Array{
public:

	using value_type = T;
	using reference = T&;
	using const_reference = const T&;
	using pointer = T*;
	using const_pointer = const T*;
	using size_type = size_t;
publicc:
	class const_iterator {
	protected:
		pointer ptr;
	
	public;
		explicit const_iterator(pointer p) : ptr{p}{}//avtomat urish tiperi cast chlini inchi hamar naxatesvaca dra hamr ashxati
		//const pointer kara urish tex nayi bayc arjeqy chi kara poxi
		//copy move ctor
		const_reference operator* () const //..deref arecir chpiti poxes 
		{	
			return *ptr;
		}

		const_pointer operator-> () const {
			return ptr;
		}
		const_iterator operator++() {
			++ptr;
			return *this;
		}
		const_iterator operator++ (int) //postfix
		{
			pointer tmp = ptr;
			++ptr;
			return tmp;
		}
		const_iterator operator+(int n) {
			return const_iterator(ptr + n);
		}
	}; //iteratoir0y jaranguma es cosnnt it + mna poxum, deref vor voch const_ptr veradardzni, const eri poxaren voch const veradardzni, inqy ira copy move ctory , consti poxaren iter karanq, bayc iter-i poxaren const iter chenq kara , derref slaq + ev hanum ++ ev -- , reveresei hamar +- -a anum -y + a anum

private:
    T arr[N];
    size_t currentSize;

public:
    Array();//default
    ~Array() = default;
    Array(const Array&);//copy
    T front() const;
    T back() const;
    void traverse();
    bool empty() const;
    size_t size();  
	T& operator[](size_t index);
	friend std::istream& operator>>(std::istream& is,Array<T, N>& a){
		for(size_t i = 0; i < N; ++i ){
			is >> a;
		}	
		return is; 
	}
	template<typename U, size_t M>
	Array<U,M> to_Array(const Array<U, M>& r){
		Array<U,M> res;
		for(size_t i = 0; i < M; ++i){
			res.arr[i] = r.arr[i];
		}
		res.currentSize = M;
		return res;
	}
};
//specialize 
template < size_t N>
class Array<bool, N> {
private:
	std::bitset<N> data;
	size_t currSize;
public:
	Array(const std::string& binStr) : data(binStr) {}
	Array(const std::bitset<N>& bitsetData) : data(bitsetData) {}
	void set(std::size_t index, bool value){
		data[index = value];
	}
	bool get(size_t index) const {
		return data[index];
	}
};
#include "array.tpp"
#endif //ARRAY_H
