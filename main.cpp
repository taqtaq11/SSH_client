#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

using namespace std;

int main() {
    string login;
    string pass;
    string cmd;
    int sockfd;
    sockaddr_in serv_addr;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    connect(sockfd, (sockaddr*)&serv_addr, sizeof(serv_addr));

    cout << "Enter login:" << endl;
    cin >> login;
    cout << "Enter pass:" << endl;
    cin >> pass;
    cout << "Enter a command:" << endl;
    cin >> cmd;

    string msg = "";
    msg.append(login);
    msg.append(" ");
    msg.append(pass);
    msg.append("\n");
    msg.append(cmd);
    send(sockfd, msg.c_str(), msg.length(), 0);

    char server_reply[1000];
    recv(sockfd, server_reply, 1000, 0);
    cout << "Response:" << endl << server_reply << endl;

    return 0;
}