#pragma once
class MaxHeap {
public:
	//���캯��
	MaxHeap(int size);
	//����
	bool expansion();
	//�趨Curλ��
	bool setCurrent(int pos);
	//��ȡ��Ϣ
	int getSize();
	int getLenth();
	int* getHeap();
	//�ж��Ƿ�ΪҶ
	bool isLeaf(int pos);
	//���������ӽڵ��Լ����ڵ�
	int leftChild(int pos);
	int rightChild(int pos);
	int parent(int pos);
	//����
	void swap(int* heap, int pos, int pos2);
	//��ɸ����
	void siftDown(int pos);
	//����
	//void bulidHeap();
	//ֵ����
	int searchByValue(int value);
	//λ������
	int searchByPos(int pos);
	//����
	bool append(int value);
	bool append2(int value,int pos);
	//ɾ�����ڵ�
	bool removeFirst();
	//ɾ������λ�ýڵ�
	bool remove(int pos);
	//���
	bool clean();

private:
	int* Heap;
	int Size;
	int Lenth;
	int Cur;
};