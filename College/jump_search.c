#include<stdio.h>
#include<math.h>
int main(){
	int n;printf("Enter the size of array: ");
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++){
		scanf("%d",a+i);
	}
	printf("Enter the key to search: ");
	int key;scanf("%d",&key);
	int block=sqrt(n);
	int i;
	for(i=0;i<n;i+=block){
		if(a[i]>=key){
			break;
		}
	}
	if (i>=n){
		i=n-1;
	}
	int flag=0;
	for(;a[i]>=key;i--){
		if(a[i]==key){
			printf("Found at %d index...\n",i);
			flag=1;
		}
	}
	if(a[i]<key && flag==0){
		printf("Not found\n");
	}
	return 0;
}