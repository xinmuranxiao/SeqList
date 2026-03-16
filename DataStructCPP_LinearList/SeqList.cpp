#include <iostream>
#include <vector>

template<class T>
class SeqList {
public:
	SeqList();
	SeqList(int num_);
	SeqList(const std::vector<T>& arr_);
	SeqList(const T* a, const int num_);


	void append(int num_);
	void append(const T* a,const int num_);
	void append(const std::vector<T>& arr_);

	void pop(int pos_);

	int getSize()const;
	T& operator[](int pos_) {
		if (pos_ < 0 || pos_ >= arr.size()) {
			throw std::out_of_range(
				std::string("error :102 :") + std::to_string(pos_)
			);
		}
		return arr[pos_];
	}

	~SeqList();
private:
	int capacity = 0;
	vector<T> arr;
};

//初始化线性表
//无元素无容量
template<class T>
SeqList<T>::SeqList() {
	arr.reserver(0);
}
//无元素纯只构造元素
template<class T>
SeqList<T>::SeqList(int num_) {
	arr.reserver(num_);
}
//vector初始化
template<class T>
SeqList<T>::SeqList(const std::vector<T>& arr_) {
	arr = arr_;
}
//c数组构造
template<class T>
SeqList<T>::SeqList(const T* a,const int num_) {
	if (num_ <= 0) {
		throw std::out_of_range{ std::string("error:101") };
	}
	if (a == NULL) {
		throw std::out_of_range{ std::string("error:201") };
	}
	for (int i = 0; i < num_; i++) {
		arr.push_back(a[i]);
	}
}

//增加元素
//vector初始化
template<class T>
void SeqList<T>::append(const std::vector<T>& arr_) {
	if (arr_.empty()) {
		throw std::out_of_range{ std::string("error:101") };
	}
	arr.insert(arr.end(), arr_.begin(), arr_.end())
}
//c数组增加
template<class T>
void SeqList<T>::append(const T* a, const int num_) {
	if (num_ <= 0) {
		throw std::out_of_range{ std::string("error:101") };
	}
	if (a == NULL) {
		throw std::out_of_range{ std::string("error:201") };
	}
	for (int i = 0; i < num_; i++) {
		arr.push_back(a[i]);
	}
}

//删除数组
template<class T>
void SeqList<T>::pop(int num_) {
	for 
}

//获取内部已存储容量
template<class T>
int SeqList<T>::getSize() const {
	return size;
}

//析构数据表
template<class T>
SeqList<T>::~SeqList() {
}