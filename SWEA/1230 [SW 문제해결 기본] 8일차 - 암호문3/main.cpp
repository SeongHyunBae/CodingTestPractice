#include "pch.h"
#include<iostream>

using namespace std;

#define MAXN 5000

int bufferCnt = 0;

struct Node {
	int data;
	Node* next;
}buffer[MAXN];

class List {
	Node* head;
	Node* tail;

public:
	List(Node* headNode, Node* tailNode) {
		head = headNode;
		tail = tailNode;
		head->next = nullptr;
	}

	void insertNode(Node* newNode, int idx, int data) {
		newNode->data = data;

		Node* tmp = head;

		while (idx--) {
			if (tmp == tail) return;

			tmp = tmp->next;
		}

		// tmp는 idx 위치 바로 전 노드
		newNode->next = tmp->next;
		tmp->next = newNode;
	}

	void deleteNode(int idx) {
		if (head->next != nullptr) {
			Node* tmp = head;

			while (idx--) {
				if (tmp == tail) return;
				tmp = tmp->next;
			}

			// tmp는 idx 위치 바로 전 노드
			tmp->next = tmp->next->next;
		}
	}

	void pushNode(Node* newNode, int data) {
		newNode->data = data;
		
		if (head->next == nullptr) {
			head->next = newNode;
			newNode->next = tail;
		}
		
		else {
			Node* tmp = head->next;

			while (tmp->next != tail) {
				tmp = tmp->next;
			}
			// tmp는 tail 전의 노드
			tmp->next = newNode;
			newNode->next = tail;
		}
	}

	void print(int num) {
		Node* tmp = head->next;

		while (tmp != tail && num--) {
			printf("%d ", tmp->data);
			tmp = tmp->next;
		}
		printf("\n");
	}
};

void init() {
	bufferCnt = 0;
}


int main(int argc, char** argv)
{
	int tc;
	int T = 10;

	FILE *stream;
	freopen_s(&stream, "input.txt", "r", stdin);

	for (tc = 1; tc <= T; ++tc)
	{
		init();

		int N;
		cin >> N;

		Node* head = &buffer[bufferCnt++];
		Node* tail = &buffer[bufferCnt++];
		List list = List(head, tail);
		
		for (int i = 0; i < N; i++) {
			int data;
			cin >> data;
			list.pushNode(&buffer[bufferCnt++], data);
		}

		cin >> N;

		for (int i = 0; i < N; i++) {
			char cmd;
			cin >> cmd;
			if (cmd == 'I') {
				int x, y;
				cin >> x >> y;

				for (int j = 0; j < y; j++) {
					int data;
					cin >> data;
					list.insertNode(&buffer[bufferCnt++], x++, data);
				}
			}
			else if (cmd == 'D') {
				int x, y;
				cin >> x >> y;
				for (int j = 0; j < y; j++) {
					list.deleteNode(x);
				}
			}
			else if (cmd == 'A'){
				int y;
				cin >> y;
				
				for (int j = 0; j < y; j++) {
					int data;
					cin >> data;
					list.pushNode(&buffer[bufferCnt++], data);
				}
			}
		}
		printf("#%d ", tc);
		list.print(10);
	}
	return 0;
}