#include <stdio.h>
#include <stdlib.h>

int main() {
	#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen("input.txt","r",stdin);
	//for writing output to output.txt
	freopen("output.txt","w",stdout);
	#endif
	int n; scanf("%d",&n);
	int a[n],b[n];
	for(int i=0;i<n;i++) {
		scanf("%d %d",&a[i],&b[i]);
	}
	int diff = 0 , k = 0; int index[n]; //variable sized array not initialized
	for(int i=0;i<n;i++) {
		diff = diff + a[i] - b[i];
		if(diff < 0) {
			diff = 0;
			for(int i=0;i<k;i++)
				index[i] = 0;
			k=0;
		}
		else {
			index[k++] = i;
		}

	}
	printf("%d\n",index[0]);
	return 0;
}

