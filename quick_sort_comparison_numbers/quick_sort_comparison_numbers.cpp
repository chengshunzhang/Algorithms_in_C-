#include <iostream>
#include <fstream>
using namespace std;

// choose the first element of given array as pivot

/*int partition(int a[], int left, int right, int & num){
	num += (right - left);
	int pivotpos = left, j = left + 1, temp;
	while (j <= right){
		if (a[j] < a[left]){
			pivotpos++;
			if(pivotpos != j){
				temp = a[j]; a[j] = a[pivotpos]; a[pivotpos] = temp;
			}
		}
		j++;
	}
	if (pivotpos != left){
		temp = a[pivotpos]; a[pivotpos] = a[left]; a[left] = temp;
	}
	return pivotpos;
}*/


// choose the last element of given array as pivot

/*int partition(int a[], int left, int right, int & num){
	num += (right - left);
	int pivotpos = left, j = left + 1, temp;
	temp = a[left]; a[left] = a[right]; a[right] = temp;
	while (j <= right){
		if (a[j] < a[left]){
			pivotpos++;
			if(pivotpos != j){
				temp = a[j]; a[j] = a[pivotpos]; a[pivotpos] = temp;
			}
		}
		j++;
	}
	if (pivotpos != left){
		temp = a[pivotpos]; a[pivotpos] = a[left]; a[left] = temp;
	}
	return pivotpos;
}*/


// use the median of three pivot rule

int partition(int a[], int left, int right, int & num){
	num += (right - left);
	int pivotpos = left, j = left + 1, temp;
	int mid = (left + right) / 2;
	if ((a[mid] < a[left] && a[mid] > a[right]) || (a[mid] > a[left] && a[mid] < a[right])){temp = a[mid]; a[mid] = a[left]; a[left] = temp;}
	else if ((a[right] < a[left] && a[right] > a[mid]) || (a[right] > a[left] && a[right] < a[mid])) {temp = a[right]; a[right] = a[left]; a[left] = temp;}
	while (j <= right){
		if (a[j] < a[left]){
			pivotpos++;
			if(pivotpos != j){
				temp = a[j]; a[j] = a[pivotpos]; a[pivotpos] = temp;
			}
		}
		j++;
	}
	if (pivotpos != left){
		temp = a[pivotpos]; a[pivotpos] = a[left]; a[left] = temp;
	}
	return pivotpos;
}

void Quicksort(int a[], int left, int right, int & num){
	if (left >= right) return;
	int p = partition(a, left, right, num);
	Quicksort(a, left, p - 1, num);
	Quicksort(a, p + 1, right, num);
}

int main(){
	int count = 0;
	ifstream file;
	file.open("QuickSort.txt");
	if (file.fail()){
		cout << "error!" << endl;
		file.close();
	}
	else {
		int Array[10000];
		int i = 0;
		while (!file.eof())
			file >> Array[i++];
		file.close();
		Quicksort(Array,0,9999,count);
		cout << count << endl;
	}
	return 0;
}