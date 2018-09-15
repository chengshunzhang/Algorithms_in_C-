void Merge(int L1[], int L2[], int left, int mid, int right){
	int k1 = left, k2 = mid + 1, k = left;
	for (int i = left; i <= right; i++){
		L2[i] = L1[i];
	}
	while (k1 <= mid && k2 <= right){
		if (L2[k1] < L2[k2])
			L1[k++] = L2[k1++];
		else
			L1[k++] = L2[k2++];
	}
	while (k1 <= mid) L1[k++] = L2[k1++];
	while (k2 <= right) L1[k++] = L2[k2++];
}

void MergeSort(int L1[], int L2[], int left, int right){
	if (left == right) return;
	int mid = (left + right) / 2;
	MergeSort(L1, L2, left, mid);
	MergeSort(L1, L2, mid + 1, right);
	Merge(L1,L2,left,mid,right);
}