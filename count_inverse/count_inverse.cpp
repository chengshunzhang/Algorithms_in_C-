#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int Countlines(string filename){
	ifstream File;
	int n = 0;
	string temp;
	File.open(filename,ios::in);
	if (File.fail())
		return 0;
	else {
		while(getline(File, temp))
			n++;
		return n;
	}
	File.close();
}

uint MergeCount(int L1[], int L2[], int left, int mid, int right){
	int k1 = left, k2 = mid + 1, k = left;
	uint num = k2 - k1, count = 0;
	for (int i = left; i <= right; i++){
		L2[i] = L1[i];
	}
	while (k1 <= mid && k2 <= right){
		if (L2[k1] < L2[k2])
			{L1[k++] = L2[k1++]; num--;}
		else
			{L1[k++] = L2[k2++]; count += num;}
	}
	while (k1 <= mid) L1[k++] = L2[k1++];
	while (k2 <= right) L1[k++] = L2[k2++];
	return count;
}

uint CountInverse(int L1[], int L2[], int left, int right){
	if (left == right) return 0;
	int mid = (left + right) / 2;
	uint n1, n2, n3;
	n1 = CountInverse(L1, L2, left, mid);
	n2 = CountInverse(L1, L2, mid + 1, right);
	n3 = MergeCount(L1,L2,left,mid,right);
	return n1 + n2 + n3;
}

int main(){
	ifstream file;
	file.open("IntegerArray.txt");
	if (file.fail()){
		cout << "error!" << endl;
		file.close();
	}
	else {
		int numberOfElements = Countlines("IntegerArray.txt");
		int * Array1 = new int [numberOfElements], * Array2 = new int [numberOfElements];
		int i = 0;
		while (!file.eof())
			file >> Array1[i++];
		file.close();
		cout << CountInverse(Array1, Array2, 0, numberOfElements - 1) << endl;
	}
	return 0;
}