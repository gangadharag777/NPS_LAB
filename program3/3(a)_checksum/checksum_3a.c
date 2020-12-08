#include<stdio.h>
#include<stdlib.h>
unsigned fields[10];
unsigned short checksum()
{
	int i;
	int sum=0;
	printf("enter IP header information in 16 bit words\n");
	for(i=0;i<9;i++)
	{
		printf("Field%d:",i+1);
		scanf("%x",&fields[i]);

		sum=sum+(unsigned short)fields[i];
		while(sum>>16)
			sum=((sum & 0xFFFF) + (sum>>16));
	}
	sum=~sum;
	return (unsigned short)sum;
}



int main()
{
	unsigned short result1,result2;
	int i;
	/*printf("\n Enter the IP header information in 16 bit words\n");
	for(i=0;i<9;i++)
	{
		printf("\nField %d\n",i+1);
		scanf("%x",&fields[i]);
	}
*/

	result1=checksum(fields);

	printf("sender checksum=%x\n",result1);


	result2=checksum(fields);

	printf("reciever checksum=%x\n",result2);


	if(result1==result2)
		printf("no error\n\n");
	else
		printf("error\n\n");

	return 0;
}


