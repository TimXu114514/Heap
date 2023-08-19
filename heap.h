#pragma once
class MaxHeap {
public:
	//构造函数
	MaxHeap(int size);
	//扩容
	bool expansion();
	//设定Cur位置
	bool setCurrent(int pos);
	//获取信息
	int getSize();
	int getLenth();
	int* getHeap();
	//判断是否为叶
	bool isLeaf(int pos);
	//计算左右子节点以及父节点
	int leftChild(int pos);
	int rightChild(int pos);
	int parent(int pos);
	//交换
	void swap(int* heap, int pos, int pos2);
	//下筛排序
	void siftDown(int pos);
	//排序
	//void bulidHeap();
	//值搜索
	int searchByValue(int value);
	//位置搜索
	int searchByPos(int pos);
	//插入
	bool append(int value);
	bool append2(int value,int pos);
	//删除根节点
	bool removeFirst();
	//删除任意位置节点
	bool remove(int pos);
	//清除
	bool clean();

private:
	int* Heap;
	int Size;
	int Lenth;
	int Cur;
};