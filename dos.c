#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int meusocket;
    int conecta;

    int i;
    int *porta;
    char *host;

    host = argv[1];
    porta = argv[2];

    struct sockaddr_in alvo;

    for (i=0;i<1;) {
        meusocket = socket(AF_INET, SOCK_STREAM, 0);
        if (meusocket == -1) {
            perror("Erro ao criar socket");
            return 1;
        }

        alvo.sin_family = AF_INET;
        alvo.sin_port = htons(porta);
        alvo.sin_addr.s_addr = inet_addr(host);

        conecta = connect(meusocket, (struct sockaddr *)&alvo, sizeof alvo);

        struct timespec sleep_time = {0, 1000000};
        nanosleep(&sleep_time, NULL);

        if (conecta == 0) {
            printf("Porta aberta %d\n", porta);
        }
    }
    return 0;
}
