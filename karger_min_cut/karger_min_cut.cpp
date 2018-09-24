#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

struct edge{
	int data;
	edge * link;
	edge(int d, edge * next = NULL):data(d),link(next){}
};

struct vertex{
	int num;
	edge * adj;
};

void contract(vertex * A, int row, int v, int n){
	int id = 0;
	edge * p, * q, * t, * pre = NULL;
	while (A[id].num != v)
		id ++;
	p = A[id].adj;
	while (p != NULL){
		if (p -> data != A[row].num){
			int i = 0;
			while(A[i].num != p -> data)
				i++;
			q = A[i].adj;
			while (q != NULL){
				if (q -> data == v)
					q -> data = A[row].num;
				q = q -> link;
			}
			t = new edge(p -> data);
			t -> link = A[row].adj;
			A[row].adj = t;
		}
		A[id].adj = p -> link;
		delete p;
		p = A[id].adj;
	}
	t = A[row].adj;
	while (t != NULL){
		if (t -> data == v) {
			if (pre == NULL){
				A[row].adj = t -> link;
				delete t;
				t = A[row].adj;
			}
			else {
				pre -> link = t -> link;
				delete t;
				t = pre -> link;
			}
		}
		else {
			pre = t;
			t = t -> link;
		}
	}
	A[id].num = A[n-1].num;
	A[id].adj = A[n-1].adj;
}

int Run(){
	ifstream file;
	vertex Nodetable[200];
	file.open("kargerMinCut.txt");
	if (file.fail()){
		cout << "error!" << endl;
		file.close();
	}
	else {
		int i = 0, c;
		file >> Nodetable[i].num;
		Nodetable[i++].adj = NULL;
		edge * q;
		while (!file.eof()){
			if (file.peek() == '\n'){
				file >> Nodetable[i].num;
				Nodetable[i++].adj = NULL;
			}
			else {
				file >> c;
				edge * p = new edge(c);
				if (Nodetable[i-1].adj == NULL){
					Nodetable[i-1].adj = p;
					q = p;
				}
				else q -> link = p;
				q = p;
			}
		}
	}
	file.close();
	int n = 200, node, random_edge;
	while (n > 2){
		int m = 0;
		node = rand() % n;
		edge * p = Nodetable[node].adj;
		while (p != NULL){
			m++;
			p = p -> link;
		}
		random_edge = rand() % m + 1;
		p = Nodetable[node].adj;
		for (int i = 1; i < random_edge; i++)
			p = p -> link;
		contract(Nodetable, node, p -> data, n);
		n--;
	}
	int count = 0;
	edge * p = Nodetable[0].adj;
	while (p != NULL){
		count ++;
		p = p -> link;
	}
	return count;
}

int main(){
	int n = 0, result = Run();
	while (n < 400){
		if (Run() < result)
			result = Run();
		n++;
	}
	cout << result << endl;
	return 0;
}