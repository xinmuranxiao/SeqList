#include"SeqList.h"

int tarr1[] = { 0,1 };
std::vector<int>tarr2 = { 2,3 };
//测试创建增加
void test01() {
	std::cout << "test01:start" << std::endl;
	try {
		SeqList<int> arr1(tarr1, 2);
		SeqList<int> arr2(tarr2);
		std::cout << arr1[0] << " " << arr1[1] << std::endl;
		std::cout << arr2[0] << " " << arr2[1] << std::endl;
		arr1.append(tarr1, 2);
		arr2.append(tarr2);
		std::cout << arr1.size() << std::endl;
		for (auto i = arr1.begin(); i != arr1.end();i++) {
			std::cout << *i << " ";
		}
		std::cout << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "test01:over" << std::endl;
}

//测试修改
void test02() {
	std::cout << "test02:start" << std::endl;
	try {
		SeqList<int> arr1(tarr1, 2);
		SeqList<int> arr2(tarr2);
		arr1[1] = 2;
		for (int i = 0; i < arr2.size(); i++) {
			std::cout << arr2[i] << " ";
		}
		std::cout << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "test02:over" << std::endl;
}

//测试删除
void test03() {
	std::cout << "test03:start" << std::endl;
	try {
		SeqList<int> arr1(tarr1, 2);
		SeqList<int> arr2(tarr2);
		arr1[1] = 2;
		for (int i = 0; i < arr2.size(); i++) {
			std::cout << arr2[i] << " ";
		}
		std::cout << std::endl;
		arr1.pop(1);
		arr1.pop(0);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "test03:over" << std::endl;
}

int main() {
	test01();
	test02();
	return 0;
}