#include "heap.h"
#include "stdlib.h"

MaxHeap::MaxHeap(int size)
{
	Lenth = 0;
	Size = size;
	Heap = this->Heap;
	Heap = (int *)malloc(sizeof(int)*Size);
	for (int i = 0; i < Size; i++) {
		Heap[i] = NULL;
	}
}

bool MaxHeap::expansion()
{
	Heap = (int *)realloc(Heap,sizeof(int)*(Size+10));
	for (int i = Size; i < Size + 10; i++) {
		Heap[i] = NULL;
	}
	return true;
}

bool MaxHeap::setCurrent(int pos)
{
	if (pos > Lenth) {
		return false;
	}
	Cur = pos;
	return true;
}

int MaxHeap::getSize()
{
	return Size;
}

int MaxHeap::getLenth()
{
	return Lenth;
}

int* MaxHeap::getHeap()
{
	return Heap;
}

bool MaxHeap::isLeaf(int pos)
{
	if ((pos >= Lenth / 2) && (pos < Lenth)) {
		return true;
	}
	else
		return false;
}

int MaxHeap::leftChild(int pos)
{
	return pos*2+1;
}

int MaxHeap::rightChild(int pos)
{
	return pos*2+2;
}

int MaxHeap::parent(int pos)
{
	return (pos-1)/2;
}

void MaxHeap::swap(int * heap, int pos, int pos2)
{
	int temp = heap[pos];
	heap[pos] = heap[pos2];
	heap[pos2] = temp;
}

void MaxHeap::siftDown(int pos)
{
	while (!isLeaf(pos)) {
		int j = leftChild(pos);
		int k = rightChild(pos);
		if ((k < Lenth) && (Heap[j] < Heap[k])) {
			j = k;
		}
		if (Heap[pos] > Heap[j]) {
			return;
		}
		swap(Heap, pos, j);
		pos = j;
	}
}
/*
void MaxHeap::bulidHeap()
{
	for(int i = Lenth/2-1;i>=0;i--)

}*/

int MaxHeap::searchByValue(int value)
{
	for (int i = 0; i < Lenth; i++) {
		if (Heap[i] == value) {
			return i;
		}
	}
	return NULL;
}

int MaxHeap::searchByPos(int pos)
{
	if (pos >= Lenth)
		return NULL;
	return Heap[pos];
}

bool MaxHeap::append(int value)
{
	if (Lenth == Size)
		expansion();
	setCurrent(Lenth);
	this->Heap[Cur] = value;
	while ((Cur != 0) &&  Heap[Cur] > Heap[parent(Cur)]) {
		swap(Heap, Cur, parent(Cur));
		Cur = parent(Cur);
	}
	Lenth = Lenth++;
	return true;
}

bool MaxHeap::removeFirst()
{
	if(Lenth <= 0)
		return false;
	Lenth = Lenth--;
	swap(Heap, 0, Lenth);
	if (Lenth != 1 && Lenth != 0)
		siftDown(0);
	return true;
}

bool MaxHeap::remove(int pos)
{
	if (Lenth == 0)
		return false;
	if ((pos < 0) || (pos >= Lenth))
		return false;
	Lenth = Lenth--;
	if (pos == Lenth)
		return true;
	else {
		swap(Heap, pos, Lenth);
		while ((pos != 0) && (Heap[pos] > Heap[parent(pos)])) {
			swap(Heap, pos, parent(pos));
			pos = parent(pos);
		}
		if (Lenth != 1) siftDown(pos);
	}
	return true;
}

bool MaxHeap::clean()
{
	for (int i = 0; i < Lenth; i++) {
		Heap[i] = NULL;
	}
	Lenth = 0;
	return true;
}
