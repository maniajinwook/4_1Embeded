#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#include "sensor.h"

#define BUF_SIZE	4
#define INIT_VAL_OF_MEM	0
#define PROTOCOL_TYPE	0
#define NUM_OF_ARGC	2
#define NUM_OF_QUEUE	5
#define DATA_SIZE	1

#define PKT_STX	0x01
#define PKT_ETX 0x04

#define CMD_SENSOR_REQ	0x10 
#define CMD_SENSOR_RES	0x90

int getSensorData(void);
void error_handling(char *message);

int main(int argc, char *argv[]) {
	int serv_sock, clnt_sock;
	FILE *fp;
	char snd_buf[BUF_SIZE];
	char rcv_buf[BUF_SIZE];
	int read_cnt;
	int readBufSize;

	struct sockaddr_in serv_adr, clnt_adr;
	socklen_t clnt_adr_sz;

	int getData;

	printf("***********************************************\n");
	printf("TCP/IP Data Transmission Program - Server\n");
	printf("***********************************************\n\n");

	// check port info
	if (argc != NUM_OF_ARGC) {
		printf("Usage: %s <port>\n", argv[0]);
		exit(1);
	}

	serv_sock = socket(PF_INET, SOCK_STREAM, PROTOCOL_TYPE);
	if (serv_sock == -1 )
		error_handling("socket() error");

	memset(&serv_adr, INIT_VAL_OF_MEM, sizeof(serv_adr));
	serv_adr.sin_family = AF_INET;
	serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_adr.sin_port = htons(atoi(argv[1]));

	if (bind(serv_sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr)) == -1)
		error_handling("bind() error()");

	if (listen(serv_sock, NUM_OF_QUEUE) == -1)
		error_handling("listen() error");

	clnt_adr_sz = sizeof(clnt_adr);

	clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_adr, &clnt_adr_sz);

	printf("Connected IP : %s\n\n", inet_ntoa(clnt_adr.sin_addr));

	while(1)
	{
		if (readBufSize = read(clnt_sock, rcv_buf, BUF_SIZE) != -1)
		{
			if(rcv_buf[0] == PKT_STX)
			{
				if(rcv_buf[1] == CMD_SENSOR_REQ)
				{
					if(rcv_buf[3] == PKT_ETX)
					{
						getData = getSensorData();

						snd_buf[0] = PKT_STX;
						snd_buf[1] = CMD_SENSOR_RES;
						snd_buf[2] = getData;
						snd_buf[3] = PKT_ETX;


						write(clnt_sock, snd_buf, BUF_SIZE);
					}
				}
			}
		}
		else {
			write(clnt_sock, snd_buf, BUF_SIZE);
			break;
		}
	}
	close(clnt_sock);
	close(serv_sock);
	printf("Transmission terminated. \n");
	printf("Disconnected(PI : %s)\n\n", inet_ntoa(clnt_adr.sin_addr));
}

void error_handling(char *message) {
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}

