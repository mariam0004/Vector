template <typename T>
	//ctors
Vector<T>::Vector() : data(nullptr), len(0), cap(0) {}
template <typename T>
Vector<T>::Vector(const Vector& rhs)
			: data(new T[rhs.len])
			, len(rhs.len)
			, cap(rhs.cap)
	 {
	for(int i = 0; i < rhs.len; ++i) {
		data[i] = rhs.data[i];
	}			
}
template <typename T>
Vector<T>::Vector(Vector&& rhs) noexcept
		: data(std::exchange(rhs.data, nullptr))// data = rhs.data, rhs.data = nullptr
		, len(std::exchange(rhs.len, 0))
		, cap(std::exchange(rhs.cap, 0))
	 {}

template <typename T>
Vector<T>::Vector(size_t l, size_t c)
		: data(new T[l])
		, len(l)
		, cap(c) {}

template <typename T>
Vector<T>::~Vector() {
		delete[] data;
	}

template<typename T>
size_t Vector<T>::vec_size() const {
	return len;
}


template <typename T>
size_t Vector<T>::vec_cap() const {
	return cap;
}
	
template <typename T>
Vector<T>::Vector (std::initializer_list<T> list) 
		: data(new T[list.size()])
		, len(list.size())
		, cap(list.size()){
		std::copy(list.begin(), list.end(), data);
	}


template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& rhs) {
		if(this != &rhs) {
			delete[] data;//before alloc release naxrody
			data = new T[rhs.len];
			for(int i = 0; i < rhs.len; ++i) {
			data[i] = rhs.data[i];
		}
			len = rhs.len;
			cap = rhs.cap;
		}
		return *this;
	}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector&& rhs) noexcept {
	if(this != &rhs) {
		delete[] data;
		data = std::exchange(rhs.data, nullptr);
		len = std::exchange(rhs.len, 0);
		cap = std::exchange(rhs.cap, 0);		
	}
	return *this;
}
template <typename T>
T& Vector<T>::operator[](size_t idx) {
	if(idx < 0 || idx >= len) {
		std::cout << "Out of range \n";//thorw out_of_range";

	}
//	std::cout << "Out of range \n";//thorw out_of_range";
	return data[idx];
}

	template <typename T>
std::istream&  operator>> (std::istream& is, Vector<T>& vec) {
	for(int i = 0; i < vec.vec_size(); ++i) {
		if(!(is >> vec[i])) {
			break;
		}
	}
	return is;
}

	template <typename T>
std::ostream& operator<< (std::ostream& os, const Vector<T>& vec) {
	for(int i = 0; i < vec.vec_size(); ++i) {
		os << vec.data[i];
	}
	return os;
}

template <typename T>
void Vector<T>::push_back(T val) {
    if (len == cap) {
        cap = (cap == 0) ? 1 : cap * 2;
        T* newData = new T[cap];
        for (size_t i = 0; i < len; ++i) {
            newData[i] = data[i];
        }

        delete[] data;
        data = newData;
    }

    data[len++] = val;
}

template <typename T>
void Vector<T>::push_back(T(&arr)[3]) {
    if (len + 3 > cap) {
        // Double  if needed
        cap = (cap == 0) ? 1 : cap * 2;
        T* newData = new T[cap];
        for (size_t i = 0; i < len; ++i) {
            newData[i] = data[i];
        }

        delete[] data;
        data = newData;
    }

    for (size_t i = 0; i < 3; ++i) {
        data[len++] = arr[i];
    }
}

template <typename T>
void Vector<T>::push_back(int val, int count) {
    if (len + count > cap) {
        cap = (cap == 0) ? 1 : cap * 2;
        T* newData = new T[cap];
        for (size_t i = 0; i < len; ++i) {
            newData[i] = data[i];
        }

        delete[] data;
        data = newData;
    }

    for (int i = 0; i < count; ++i) {
        data[len++] = val;
    }
}


template <typename T>
void Vector<T>::pop_back() {
	if(vec_size() > 0){//or i can ` delete data[len - 1].~T() for that type that need to invoken dtor 
		--len;
	}
}


template <typename T>
void Vector<T>::shrink_to_fit()//this function release free space but save 3 elems space, cause somebody can want to push_back
{
	int newCap = len + 3;
	if(cap > newCap) {
		T* newData = new T[newCap];
		for(int i = 0; i < len; ++i) {
			newData[i] = data[i];
		}
		delete[] data;
		data = newData;
		cap = newCap;
	}
}

template<typename T>
void Vector<T>::insert(T val, size_t idx) {
	if(idx < 0 || idx > len) {
		std::cout << "Out of bound!!!";
		return;
	}
	if(len == cap) {
		cap = (cap == 0) ? 1 : cap * 2;
		T* newData = new T[cap];
		for(int i = 0; i < len; ++i) {
			 newData[i] = data[i];
		}
		newData[idx] = val;
		for(int i = idx; i < len; ++i) {
			newData[i + 1] = data[i];
		}
		delete[] data;
		data = newData;
		++len;
	} else {
		for(int i = len; i >= 0; --i) {
			data[i] = data[i - 1]; 
		}
		data[idx] = val;
		++len;
	}//not realloc cap is enough
}

template <typename T>
void Vector<T>::insert(T (&arr)[2] ,  size_t idx) {
	if(idx < 0 || idx > len) {
		std::cout << "Out of range!!\n";
	}
	if(len == cap){
		cap = (cap == 0) ? 1 : cap * 2;
		T* newData = new T[cap];
		for(int i = 0; i < len; ++i) {
			newData[i] = data[i];
		}
		for(int i = 0; i < 2; ++i) { 
			newData[idx + i] = arr[i];
		}
		for(int i = idx + 2; i < len ; ++i) {
			newData[i] = data[i - 2];//copy mnacacy idx + 2-ic
		}
		delete[] data;
		data = newData;
		len += 2;	
	}
	else {
		for(int i = len; i > idx; --i) {
			data[i] = data[i - 2];
		}
		for(int i = 0; i < 2; ++i) {
			data[idx + i] = arr[i];
		}
		len += 2;
	}//no need realloc
}


template <typename T>
void  Vector<T>::insert(T val, int count, size_t idx) {
	if(idx < 0 || idx > len) {
		std::cout << "Out of range!!\n";
		return;
	}
	if(len + count > cap) {
		size_t newCap = len + count;
		T* newD = new T[newCap];
		for(int i = 0; i < idx; ++i) {
			newD[i] = data[i];
		}
		for(int i = 0; i < count; ++i) {
			newD[idx + i] = val;
		}
		for(int i = idx; i < len; ++i) {
			newD[idx + count + i] = data[i];//insert aneluc heto mnacacy
		}
		delete[] data;
		data = newD;
		cap = newCap;
		len += count;
	} else {
		for(int i = len; i > idx; --i) {
			data[i + count - 1] = data[i - 1];
		}
		for(int i = 0; i < count; ++i) {
			data[idx + i] = val;
		}
		len += count;
	}
}


template <typename T>
void Vector<T>::deleteItem(int idx) {
	if(idx < 0 || idx >= len) {
		std::cout << "Out of range\n";
		return;
	}
	T* newData = new T[cap];
	for(int i = 0; i < idx; ++i) {
		newData[i] = data[i];
	}
	for(int i = idx + 1; i < len ; ++i) {
		newData[i - 1] = data[i];
	}
	delete[] data;
	data = newData;
	len--;
}


template <typename T>
void Vector<T>::deleteItem(int idx, int count) {
	if(idx < 0 || idx >= len) {
		std::cout << "Out of range !!\n";
		return;
	}
	T* newD = new T[cap];
	for(int i = 0; i < idx; ++i) {
		newD[i] = data[i];
	}
	for(int i = idx + count; i < len; ++i) {
		newD[i - count] = data[i];//for right index i - count is correct
	}
	delete[] data;
	data = newD;
	len -= count;
}

template <typename T>
void  Vector<T>::search(T val) {
	for(int i = 0; i < len; ++i) {
		if(data[i] == val) {
			std::cout << val << " is found in " << i << "-th index\n"; 
			return;
		}
	}
	std::cout << "Val is not found!!\n";
}

template <typename T>
void Vector<T>::resize(size_t newSize, int count) {
	if(newSize == len) {
		std::cout << "Count equal to len nothing to do !\n";
		return;
	}
	if(newSize < len) {
		for(int i = newSize; i < len; ++i) {
			data[i].~T();
		}
	} else {
		if(newSize > cap) {
			T* newData = new T[newSize];
			for(int i = 0; i < len; ++i) {
				new (&newData[i]) T(data[i]);//copy ctor for exmaple string
				data[i].~T();
			}
			delete[] data;
			data = newData;
			cap = newSize;
		}
	
	for(int i = len; i < newSize; ++i) {
		new (& data[i]) T();
	}
}
		len = newSize;
}

