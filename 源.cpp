#include <iostream>
#include "heap.h"

using namespace std;

//������Ϣ
void showBasicInfo(MaxHeap aheap) {
	int maxSize = aheap.getSize();
	int listSize = aheap.getLenth();
	int* list = aheap.getHeap();
	//��ȡmaxSize
	cout << "����󳤶�Ϊ" << maxSize << endl;
	//��ȡlistSize
	cout << "�ѵ�ǰ����Ϊ" << listSize << endl;
	//��ȡ��ǰaheap
	cout << "��ǰ��Ϊ" << endl;
	if (listSize != 0) {
		for (int i = 0; i < listSize - 1; i++) {
				cout << list[i] << " ";                       
		}
			cout << list[listSize - 1] << endl;
	}
}

//����ֵ��λ��
void searchPos(MaxHeap aheap) {
	int value;
	cout << "������Ҫ������ֵ(����ʾ��һ����ֵ��λ��)" << endl;
	cin >> value;
	int position = aheap.searchByValue(value);
	if (position != NULL)
		cout << "��һ����ֵ��λ��Ϊ" << position << endl;
}

//����λ�õ�ֵ
void searchValue(MaxHeap aheap) {
	int position;
	cout << "������Ҫ����λ��" << endl;
	cin >> position;
	int value = aheap.searchByPos(position);
	if (value != NULL)
		cout << "��λ�õ�ֵΪ" << value << endl;
	else
		cout << "��λ�ò����ڣ�����" << endl;
}
//����
void append(MaxHeap* aheap) {
	int value;
	cout << "������Ҫ׷�ӵ�ֵ" << endl;
	cin >> value;
	aheap->append(value);
	cout << "׷�ӳɹ�" << endl;
}
//ɾ����ֵ
void removeRoot(MaxHeap* aheap) {
	bool isRemove = aheap->removeFirst();
	if (isRemove == false)
		cout << "�ն�" << endl;
	else
		cout << "ɾ����ֵ�ɹ�" << endl;
}
//ɾ��λ���ϵ�ֵ
void removePos(MaxHeap* aheap) {
	int position;
	cout << "������Ҫɾ����λ��" << endl;
	cin >> position;
	if (aheap->remove(position) == false)
		cout << "û��ɾ���Ŀ����ԣ�" << endl;
	else {
		cout << "��ɾ����λ�õ�ֵ��" << endl;
	}
}
//���
void clear(MaxHeap* aheap) {
	if (aheap->clean() == false)
		cout << "���ʧ��" << endl;
	else
		cout << "��ճɹ�" << endl;

}

int main() {
	int size;
	cout << "��������󳤶�" << endl;
	cin >> size;
	//����
	MaxHeap aheap = MaxHeap(size);

	int Size = aheap.getSize();
	int Lenth = aheap.getLenth();
	int* heap = aheap.getHeap();

	while (1) {
		Size = aheap.getSize();
		Lenth = aheap.getLenth();
		heap = aheap.getHeap();

		//����
		int op;
		cout << "������(1)��ʾ�ѻ�����Ϣ(2)����ֵ��λ��(3)����λ�õ�ֵ(4)����(5)ɾ����ֵ(6)ɾ��λ���ϵ�ֵ(7)���" << endl;
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