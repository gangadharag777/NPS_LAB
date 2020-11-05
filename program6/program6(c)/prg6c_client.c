#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<arpa/inet.h>

void str_cli(FILE *fp, int sockfd,struct sockaddr* serv_address, int servlen)
{
   int bufsize = 1024, cont;
   char *buffer = malloc(bufsize);
	int addrlen = sizeof(struct sockaddr_in);
	struct sockaddr_in *preply_addr;
	int len = sizeof(struct sockaddr_in);
	if(fgets(buffer,bufsize,fp)!=NULL){
	
	sendto(sockfd, buffer, sizeof(buffer),0,serv_address,servlen);  

  	if((cont=recvfrom(sockfd, buffer, bufsize, 0,(struct sockaddr*)preply_addr,&len)>0)) //...... recv+accept
	{
		//printf("The address %s  ...\n",inet_ntoa(preply_addr->sin_addr) );
    	fputs(buffer,stdout);

  	}
        //close(sockfd);
}
	
  printf("\nEOF\n");
}
int main(int argc,char *argv[])
{
  int sockfd;
  
  //char fname[256];
  struct sockaddr_in serv_address;
  if ((sockfd = socket(AF_INET,SOCK_DGRAM,0)) > 0)
  printf("The Socket was created\n");
  serv_address.sin_family = AF_INET;
  serv_address.sin_port = htons(16001);

  inet_pton(AF_INET,argv[1],&serv_address.sin_addr);
 
  
  str_cli(stdin,sockfd,(struct sockaddr *)&serv_address,sizeof(serv_address));

 
  exit(0);
}
