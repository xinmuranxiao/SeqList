#include<iostream>

template<class T>
class SeqList {
public:
	SeqList(int size_);
	
	int getSize();
	int getCapacity();
	T& operator[](pos_) {
		if (pos_ < 0 || pos_ >= arr.size()) {
			throw std::out_of_range(
				"下标越界！有效范围：0~" + std::to_string(arr.size() - 1) +
				"，你输入的下标：" + std::to_string(pos_)
			);
		}
		return arr[pos_];
	}
	
	~SeqList();
private:
	int size = 0;
	int capacity = 0;
	vector<T> arr;
};

template<class T>
SeqList<T>::SeqList(int size_) {
	if (size_ <= 0) {
		throw invalid_argument("1");
	}
	arr.reserve(size_);
	size = size_;
}

template<class T>
int SeqList<T>::getSize() {
	return size;
}

template<class T>
int SeqList<T>::getCapacity() {
	return capacity;
}

template<class T>
SeqList<T>::~SeqList() {
}