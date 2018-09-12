#include <iostream>
using namespace std;

int main(){
	int n = 64;
	char A[65] = "3141592653589793238462643383279502884197169399375105820974944592", B[65] = "2718281828459045235360287471352662497757247093699959574966967627";
	int A1[n], A2[n], temp[n][n+n], rst[n+n], i, k, add, tmp;
	for (i = 0; i < n; i++)
		for (k = 0; k < n+n; k++)
			temp[i][k] = 0;
	for (i = 0; i < n+n; i++)
		rst[i] = 0;
	for (i = 0; i < n; i++){
		A1[i] = int(A[i] - '0');
		A2[i] = int(B[i] - '0');
	}
	for (i = 0; i < n; i++){
		add = 0;
		for (k = 0; k < n; k++){
			tmp = A1[n-k-1] * A2[n-i-1] + add;
			add = tmp / 10;
			temp[i][n+n-k-1-i] = tmp % 10;
		}
		temp[i][n+n-k-1-i] = add;
	}
	add = 0;
	for (k = n+n-1; k >= 0; k--){
		tmp = 0;
		for (i = 0; i < n; i++){
			tmp += temp[i][k];
		}
		tmp += add;
		rst[k] = tmp % 10;
		add = tmp / 10;
	}
	for (i = 0; i < n+n; i++)
		cout << rst[i];
	cout << endl;
	return 0;
}