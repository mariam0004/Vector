
template<typename T, size_t N>
Array<T,N>::Array()
            : currentSize{}{}
template<typename T, size_t N>
Array<T, N>::Array(const Array& other)
        :currentSize{other.currentSize}{
            for(int i = 0; i < currentSize; ++i){
                arr[i] = other.arr[i];
            }
}
template<typename T, size_t N>
T Array<T, N>::front() const {
    if(currentSize >= 0){
        return arr[0];
    } else {
        return -1;
    }
}
template<typename T, size_t N>
T  Array<T, N>::back() const {
    if(currentSize > 0){
        return arr[currentSize - 1];
    }
    return -1;
}
template<typename T, size_t N>
void Array<T, N>::traverse() {
    for(int i = 0; i < N; ++i) {
        std::cout << arr[i] << " ";
    }
}
template<typename T, size_t N>
bool Array<T, N>::empty() const {
    return currentSize == 0;
}
template<typename T, size_t N>
size_t Array<T, N>::size() {
    return currentSize;
}
template<typename T, size_t N>
T& Array<T, N>::operator[](size_t index) {
	if(index < 0){
		std::cout << "Invalid index\n";
	}
		return arr[index];
}
/*
template<typename T, size_t N>
std::istream& operator>>(std::istream& is,Array<T, N>& a){
	for(int i = 0; i < N; ++i){
		is >> a.arr[i];
	}
	return is;
}*/
/*
template <typename T, size_t N>
typename Array<T,N>::const_iterator::operatpr*() const {
	return *ptr;
}
*/
