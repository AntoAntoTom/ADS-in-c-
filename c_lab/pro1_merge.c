#include<stdio.h>
void main(){
int n1,n2,i,j=0,k=0;
int a1[50];
int a2[50];
int a3[50];

printf("Enter the limet of the first array :");
scanf("%d",&n1);

for(i=0;i<n1;i++)
 	scanf("%d",&a1[i]);

printf("Enter the limet of the second array :");
scanf("%d",&n2);

for(i=0;i<n2;i++)
	scanf("%d",&a2[i]);

i=0;

while(i<n1 && j<n2)
	{
  		if(a1[i]<a2[j])
		{
 			a3[k]=a1[i];
 			i++;
			k++;
 		}
		else
		{
 			a3[k]=a2[j];
 			j++;
 			k++;
		}
	}


while(i<n1)
	a3[k++]=a1[i++];

while(j<n2)
	a3[k++]=a2[j++];

for(i=0;i<n1+n2;i++)
	 printf("%d ",a3[i]);


}
