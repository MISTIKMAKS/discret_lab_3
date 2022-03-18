#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void placement(int n, int r) {
	int result = 0;
	int up = 1;
	int down = 1;
	for (int i = 1; i <= n; i++) {
		up *= i;
	}
	for (int i = 1; i <= n - r; i++) {
		down *= i;
	}
	result = up / down;
	cout << result << endl;
}

void stirling(int en) {
	const int ene = 18;

	cout << "Stirling Second Numbers:" << endl;
	int stirlingArray[ene][ene];
	for (int n = 0; n < ene; n++) {
		for (int k = 0; k < ene; k++) {
			if (k == 0) {
				stirlingArray[n][k] = 0;
			}
			else if(k == n) {
				stirlingArray[n][k] = 1;
			}
			else if (n == 0 && k == 0) {
				stirlingArray[n][k] = 1;
			}
			else if (k > n) {
				stirlingArray[n][k] = 0;
			}
			else {
				stirlingArray[n][k] = stirlingArray[n - 1][k - 1] + k * stirlingArray[n - 1][k];
			}
		}
	}
	for (int n = 0; n < ene; n++) {
		for (int k = 0; k < ene; k++) {
			cout << stirlingArray[n][k] << ' ';
		}
		cout << endl;
	}
	cout << endl;

	cout << "Bell Number:" << endl;
	int belleArray[ene] = { 0 };
	for (int n = 0; n < ene; n++) {
		for (int k = 0; k < ene; k++) {
			if (k > n) {
				break;
			}
			else {
				belleArray[n] += stirlingArray[n][k];
			}
		}
	}
	for (int n = 0; n < ene; n++) {
		cout << belleArray[n] << endl;
	}
}

int main()
{
	int n = 9;
	int r = 6;

	cout << "Placement:" << endl;
	placement(n, r);
	cout << endl << endl << endl;

	int en = 12 + 5 + 1;

	stirling(en);
}