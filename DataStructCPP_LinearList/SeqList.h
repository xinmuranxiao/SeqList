#ifndef SEQLIST_H
#define SEQLIST_H

#include<iostream>
#include <vector>
#include <string>
#include <stdexcept>

template<class T>
class SeqList {
public:
	//获取头指针
	typename std::vector<T>::iterator begin() noexcept;
	//获取尾指针
	typename std::vector<T>::iterator end() noexcept;
	//删除
	typename std::vector<T>::iterator pop(const size_t& pos_);
	typename std::vector<T>::iterator pop(const size_t& first, const size_t& last);

	//判断是否为空

	bool empty() const noexcept;

	//构造
	SeqList(const std::vector<T>& arr_ = {});
	SeqList(const T* aRR_, const size_t num_);

	//插入
	void insert(const size_t &pos_, const std::vector<T>& arr_);
	void insert(const size_t &pos_, const T* a, const size_t num_);

	//获取长度
	size_t size()const noexcept;

	//修改对应参数
	T& operator[](size_t pos_);

private:
	//构造/添加函数判断是否
	void checkNullPtr(const T* ptr) const;

	//检查是否越界
	void checkValidIndex(const size_t& pos_)const;

	//检查是否尾端越界
	void checkValidIndexLast(const size_t& pos_) const;

	//参数是否正确
	void validatePositiveNumber(const size_t& num_) const;

	//声明变量
	std::vector<T> arr;//存储的动态数组
};

//----------------------内部--------------------------

//产生异常
//检查c数组传入参数是否正确
template<class T>
void SeqList<T>::validatePositiveNumber(const size_t &num_) const {
	if (num_ == 0) {
		throw std::invalid_argument(std::string("must num>0"));
	}
}

//检查是否参数越界
template<class T>
void SeqList<T>::checkValidIndex(const size_t &pos_) const {
	if (pos_ >= arr.size()) {
		throw std::out_of_range(std::string("pos_ no in arr!"));
	}
}

//检查是否尾端越界
template<class T>
void SeqList<T>::checkValidIndexLast(const size_t& pos_) const {
	if (pos_ > arr.size()) {
		throw std::out_of_range(std::string("pos_ no in arr!"));
	}
}

//检查传入指指针是否为空
template<class T>
void SeqList<T>::checkNullPtr(const T* ptr) const {
	if (ptr == nullptr) {
		throw std::domain_error("arr==NULL");
	}
}

//----------------------外部--------------------------

//获取头指针
template<class T>
typename std::vector<T>::iterator SeqList<T>::begin() noexcept {
	return arr.begin();
}

//获取尾指针
template<class T>
typename std::vector<T>::iterator SeqList<T>::end() noexcept {
	return arr.end();
}

template<class T>
bool SeqList<T>::empty() const noexcept {
	return arr.empty();
}

//--------------------初始化线性表-----------------------------

//vector初始化
template<class T>
SeqList<T>::SeqList(const std::vector<T>& arr_) :arr(arr_){}

//c数组构造
template<class T>
SeqList<T>::SeqList(const T* arr_,const size_t num_) {
	validatePositiveNumber(num_);
	checkNullPtr(arr_);
	arr.assign(arr_, arr_ + num_);
}

//----------------------------------插入-------------------------------------

//vector插入
template<class T>
void SeqList<T>::insert(const size_t& pos_, const std::vector<T>& arr_) {
	checkValidIndexLast(pos_);
	arr.insert(arr.begin() + pos_, arr_.begin(), arr_.end());
}

//c数组插入
template<class T>
void SeqList<T>::insert(const size_t& pos_, const T* arr_, const size_t num_) {
	validatePositiveNumber(num_);
	checkNullPtr(arr_);
	checkValidIndexLast(pos_);
	arr.insert(arr.begin() + pos_, arr_, arr_ + num_);
}

//删除数组
template<class T>
typename std::vector<T>::iterator SeqList<T>::pop(const size_t& pos_) {
	checkValidIndex(pos_);
	return arr.erase(arr.begin()+pos_);
}

template<class T>
typename std::vector<T>::iterator SeqList<T>::pop(const size_t& first,const size_t& last){
	checkValidIndex(first);
	checkValidIndexLast(last);
	if (first > last) {
		throw std::invalid_argument(std::string("first > last"));
	}
	return arr.erase(arr.begin()+first, arr.begin() + last);
}

//获取内部已存储容量
template<class T>
size_t SeqList<T>::size() const noexcept {
	return arr.size();
}

//重载[]运算符
template<class T>
T& SeqList<T>::operator[](size_t pos_) {
	checkValidIndex(pos_);
	return arr[pos_];
}

#endif // SEQLIST_H