#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int T, N;
long int arr[100001];
long int K, cum = 1;
int main() {
    scanf("%d", &T);
	for (int aa = 0; aa < T; ++aa) {
	    cin >> N >> K;
	    //cout << K << "\n";
	    for (int i = 0; i < N; ++i) {
	        scanf("%ld", arr+i);
	    }
	    int total = 0;
	    cum = 1;
	    for (int beg = -1, end = 0; end < N; ++end) {
	        cum *= arr[end];
	        
	        for (; cum >= K && beg < N; ++beg, cum /= arr[beg]);
	        // formula by fixing the last element in the arr
	        //printf("%d %d %ld add: %d\n", beg, end, cum, (end-beg));
	        total += (end-beg);
	    }
	    cout << total << "\n";
	    //printf("\n");
	}
	return 0;
}
