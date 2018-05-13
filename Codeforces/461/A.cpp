#include <bits/stdc++.h>

int main() {
	int x, y;
	scanf("%d%d", &x, &y);
	--y;
	if (x - y >= 0){
		printf("%s\n", (x-y)%2 ? "No": "Yes");
	}
	else {
		printf("No\n");
	}
	return 0;
}