#include <iostream>
#include "heap.h"

using namespace std;

//基础信息
void showBasicInfo(MaxHeap aheap) {
	int maxSize = aheap.getSize();
	int listSize = aheap.getLenth();
	int* list = aheap.getHeap();
	//获取maxSize
	cout << "堆最大长度为" << maxSize << endl;
	//获取listSize
	cout << "堆当前长度为" << listSize << endl;
	//获取当前aheap
	cout << "当前堆为" << endl;
	if (listSize != 0) {
		for (int i = 0; i < listSize - 1; i++) {
				cout << list[i] << " ";                       
		}
			cout << list[listSize - 1] << endl;
	}
}

//搜索值的位置
void searchPos(MaxHeap aheap) {
	int value;
	cout << "请输入要检索的值(将显示第一个该值的位置)" << endl;
	cin >> value;
	int position = aheap.searchByValue(value);
	if (position != NULL)
		cout << "第一个该值的位置为" << position << endl;
}

//搜索位置的值
void searchValue(MaxHeap aheap) {
	int position;
	cout << "请输入要检索位置" << endl;
	cin >> position;
	int value = aheap.searchByPos(position);
	if (value != NULL)
		cout << "该位置的值为" << value << endl;
	else
		cout << "该位置不存在！！！" << endl;
}
//插入
void append(MaxHeap* aheap) {
	int value;
	cout << "请输入要追加的值" << endl;
	cin >> value;
	aheap->append(value);
	cout << "追加成功" << endl;
}
//删除根值
void removeRoot(MaxHeap* aheap) {
	bool isRemove = aheap->removeFirst();
	if (isRemove == false)
		cout << "空堆" << endl;
	else
		cout << "删除根值成功" << endl;
}
//删除位置上的值
void removePos(MaxHeap* aheap) {
	int position;
	cout << "请输入要删除的位置" << endl;
	cin >> position;
	if (aheap->remove(position) == false)
		cout << "没有删除的可能性！" << endl;
	else {
		cout << "已删除该位置的值！" << endl;
	}
}
//清空
void clear(MaxHeap* aheap) {
	if (aheap->clean() == false)
		cout << "清空失败" << endl;
	else
		cout << "清空成功" << endl;

}

int main() {
	int size;
	cout << "请输入最大长度" << endl;
	cin >> size;
	//创建
	MaxHeap aheap = MaxHeap(size);

	int Size = aheap.getSize();
	int Lenth = aheap.getLenth();
	int* heap = aheap.getHeap();

	while (1) {
		Size = aheap.getSize();
		Lenth = aheap.getLenth();
		heap = aheap.getHeap();

		//操作
		int op;
		cout << "操作：(1)显示堆基础信息(2)搜索值的位置(3)搜索位置的值(4)插入(5)删除根值(6)删除位置上的值(7)清空" << endl;
		cin >> op;

		switch (op) {
		case 1:
			showBasicInfo(aheap);
			break;
		case 2:
			searchPos(aheap);
			break;
		case 3:
			searchValue(aheap);
			break;
		case 4:
			append(&aheap);
			break;
		case 5:
			removeRoot(&aheap);
			break;
		case 6:
			removePos(&aheap);
			break;
		case 7:
			clear(&aheap);
			break;
		}
	}
}