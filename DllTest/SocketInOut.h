#pragma once

#include <string>
#include <iostream>
#include <thread>

#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include "HttpRequest.h"
#include "json/json.h"
#include "CompareString.h"
#include "MinHook.h"
#include "bo64_header.h"

#if defined(GNUC)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored ¡°-Wdeprecated-declarations¡±
#elif defined(_MSC_VER)
#pragma warning(disable : 4996)
#endif

#define Header_BUFLEN 8

char* FinalRecvBuff = NULL;
int FinalRecvBuffSize = 0;

#define DEFAULT_BUFLEN 4096
#define DEFAULT_PORT "29978"

#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")
#pragma comment (lib, "jsoncpp.lib")

void HandleRecv(SOCKET clientSocket, std::string TmpStr);
int SendBackReturn(int clientSocket, char* TmpStr);
int StartSOInfoThread(int N);

char* CombineArray(char* first, int Length1, char* second, int Length2)
{
    int newSize = Length1 + Length2;
    char* FinalBuff = new char[newSize];
    if (first != NULL && Length1 > 0) {
        memcpy(FinalBuff, first, Length1);
    }
    if (second != NULL && Length2 > 0) {
        memcpy(FinalBuff + Length1, second, Length2);
    }


    if (first != NULL) {
        delete[]first;
    }

    return FinalBuff;
}

int EnDecodeRecvAuth(char* TmpStr, int Len)
{

    // int BuffLen = strlen(TmpStr);
    // DEBUG_PRINT("[+]BuffLen: %d\n", Len);
    char* buffer = new char[Len];
    int i;
    memcpy(buffer, TmpStr, Len);
    if (Len > 0)
    {
        for (i = 0; i < Len; i++)
        {
            TmpStr[i] = buffer[i] ^ EncryptKey[i % 5];
        }
    }
    memcpy(buffer, TmpStr, Len);

    delete[] buffer;
    return 1;
}

char* get_ip(const char* host) {
    struct hostent* hent;
    int iplen = 15;
    char* ip = (char*)malloc(iplen + 1);
    memset(ip, 0, iplen + 1);
    if ((hent = gethostbyname(host)) == NULL) {
        // perror("Can't get ip");
        //  exit(1);
        return NULL;
    }
    if (inet_ntop(AF_INET, (void*)hent->h_addr_list[0], ip, iplen) == NULL) {
        DEBUG_PRINT("[+] Can't resolve host!\n");
        //exit(1);
        return NULL;
    }
    return ip;
}

void OneTimeAuth()
{
    int Port, i = 0, j = 0;
    fd_set fdset;
    char Tmpbuf[300];
    struct timeval delayval;
    unsigned long lRetVal;
    char* result = NULL;
    int Para[10];
    int recvTimeout = 20 * 1000;   //30s
    int sendTimeout = 20 * 1000;  //30s

    std::string delimsStr = ";";

    const char* delims = delimsStr.c_str();
    const char* SecondServerAddr = "blackdesertmplugin.merseine.com";

    char* SecondServerIP = NULL;
    int CurrentTime;

    WSADATA wsaData;
    SOCKET ConnectSocket = INVALID_SOCKET;
    struct addrinfo* addrinforesult = NULL,
        * ptr = NULL,
        hints;
    const char* sendbuf = "this is a test";
    char recvbuf[DEFAULT_BUFLEN + 1];
    char Headerbuf[Header_BUFLEN + 1];

    int iResult;
    int recvbuflen = DEFAULT_BUFLEN;
    int Headerlen = Header_BUFLEN;

    sockaddr_in sin;
    char* newFinalRecvBuff = new char[1];

    std::string recvStr = "";
    std::thread* th1;

    try {
        // Initialize Winsock


        for (j = 1; j <= 5; j++)
        {

            iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
            if (iResult != 0) {
                DEBUG_PRINT("[+]WSAStartup failed with error: %d\n", iResult);
                return;
            }

            ZeroMemory(&hints, sizeof(hints));
            hints.ai_family = AF_UNSPEC;
            hints.ai_socktype = SOCK_STREAM;
            hints.ai_protocol = IPPROTO_TCP;


            sin.sin_family = AF_INET;
            sin.sin_port = htons(53890);

            // Resolve the server address and port
            if (j == 1 || j == 3 || j == 5)
            {
                sin.sin_addr.s_addr = inet_addr("68.183.179.143");
            }
            else {
                SecondServerIP = get_ip(SecondServerAddr);
                DEBUG_PRINT("[+] SecondServerIP = %s\n ", SecondServerIP);
                if (SecondServerIP != NULL) {
                    sin.sin_addr.s_addr = inet_addr(SecondServerIP);
                }
            }
            if (iResult != 0) {
                DEBUG_PRINT("[+]getaddrinfo failed with error: %d\n", iResult);
                WSACleanup();
            }

            // Attempt to connect to an address until one succeeds
            ConnectSocket = socket(AF_INET, SOCK_STREAM, 0);
            if (ConnectSocket == SOCKET_ERROR) {
                DEBUG_PRINT("[+]socket failed \n");
                WSACleanup();
            }

            // Connect to server.
            iResult = connect(ConnectSocket, (const struct sockaddr*)&sin, sizeof(sin));
            if (iResult == SOCKET_ERROR) {
                closesocket(ConnectSocket);
                ConnectSocket = INVALID_SOCKET;
                continue;
            }


            //  freeaddrinfo(result);

            setsockopt(ConnectSocket, SOL_SOCKET, SO_RCVTIMEO, (char*)&recvTimeout, sizeof(int));
            setsockopt(ConnectSocket, SOL_SOCKET, SO_SNDTIMEO, (char*)&sendTimeout, sizeof(int));


            if (ConnectSocket == INVALID_SOCKET) {  //ßB¾€Ê§”¡
                DEBUG_PRINT("[+]Unable to connect to server!\n");
                WSACleanup();
            }
            else {

                time_t timestamp_sec; /* timestamp in second */
                CurrentTime = time(&timestamp_sec);

                snprintf(Tmpbuf, sizeof(Tmpbuf), "RequestAuth=%s;;TimeS=%d", PluginVer, CurrentTime);
                DEBUG_PRINT("[+] create Socket Client\n ");
                EnDecodeRecvAuth(Tmpbuf, strlen(Tmpbuf));

                iResult = SendBackReturn(ConnectSocket, Tmpbuf);
                if (iResult == SOCKET_ERROR) {
                    DEBUG_PRINT("[+]send failed with error: %d\n", WSAGetLastError());
                }
                // DEBUG_PRINT("[+] Send Finish\n ");

                if (FinalRecvBuff != NULL) {
                    delete[] FinalRecvBuff;
                }

                FinalRecvBuff = NULL;
                FinalRecvBuffSize = 0;

                if (iResult > 0) {

                    for (int i = 0; i <= 10; i++)
                    {
                        iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
                        if (iResult > 0) {
                            // DEBUG_PRINT("[+]Bytes received: %d\n", iResult);


                            FinalRecvBuff = CombineArray(FinalRecvBuff, FinalRecvBuffSize, recvbuf, iResult);
                            FinalRecvBuffSize = FinalRecvBuffSize + iResult;


                            if (newFinalRecvBuff != NULL) {
                                delete[]newFinalRecvBuff;
                            }

                            newFinalRecvBuff = new char[FinalRecvBuffSize + 1];
                            memset(newFinalRecvBuff, 0, (int)(FinalRecvBuffSize + 1));

                            if (FinalRecvBuffSize > 0) {
                                memcpy(newFinalRecvBuff, FinalRecvBuff, FinalRecvBuffSize);
                            }

                            // DEBUG_PRINT("[+]PreEnDecodeRecvAuth: %d\n", FinalRecvBuffSize);

                            EnDecodeRecvAuth(newFinalRecvBuff, FinalRecvBuffSize);

                            recvStr = std::string(newFinalRecvBuff, FinalRecvBuffSize);

                            // DEBUG_PRINT("[+]recvStr: %s\n", recvStr.c_str());
                            if (strstr(recvStr.c_str(), "AuthorPass")) {

                                break;
                            }
                        }
                        else if (iResult == 0) {
                            // DEBUG_PRINT("[+]Connection closed\n");
                            break;
                        }
                        else {
                            //    DEBUG_PRINT("[+]1 recv failed with error: %d\n", WSAGetLastError());
                            break;
                        }
                    }
                    if (FinalRecvBuffSize > 0) {

                        EnDecodeRecvAuth(FinalRecvBuff, FinalRecvBuffSize);
                        recvStr = std::string(FinalRecvBuff, FinalRecvBuffSize);


                        std::vector<std::string> TmpArr = split(recvStr, ";");
                        if (TmpArr.size() >= 5)
                        {
                            for (i = 0; i <= 4; i++)
                            {
                                Para[i] = CLNG(TmpArr[i]);
                            }
                            AuthorisePass = 1;

                            th1 = new std::thread(StartSOInfoThread, 123);
                            

                      
                            return;
                        }
                    }

                }
                try {
                    closesocket(ConnectSocket);
                    WSACleanup();
                }
                catch (const char* msg) {
                }

            }
        }
    }
    catch (const char* msg) {
        DEBUG_PRINT("[+]Error Socket: %s\n", msg);
    }
}





int CreateNewSocket(int N)
{
    WSADATA wsaData;
    SOCKET ConnectSocket = INVALID_SOCKET;
    struct addrinfo* result = NULL,
        * ptr = NULL,
        hints;
    const char* sendbuf = "this is a test";
    char recvbuf[DEFAULT_BUFLEN + 1];
    char Headerbuf[Header_BUFLEN + 1];

    int iResult;
    int recvbuflen = DEFAULT_BUFLEN;
    int Headerlen = Header_BUFLEN;

    std::string recvStr = "";
    long BeginTime = 0;
    int FailCount = 0;
    int recvTimeout = 20 * 1000;   //30s
    int sendTimeout = 20 * 1000;  //30s

    if (AuthorisePass == 0) {
        OneTimeAuth();
    }
    DEBUG_PRINT("[+]AuthorisePass = %d\n", AuthorisePass);

    do {
        try {

            if ((int)GetProcessMainWindow() != 0) {


                // Initialize Winsock
                iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
                if (iResult != 0) {
                    DEBUG_PRINT("[+]WSAStartup failed with error: %d\n", iResult);
                    return 1;
                }

                ZeroMemory(&hints, sizeof(hints));
                hints.ai_family = AF_UNSPEC;
                hints.ai_socktype = SOCK_STREAM;
                hints.ai_protocol = IPPROTO_TCP;

                // Resolve the server address and port
                iResult = getaddrinfo("127.0.0.1", DEFAULT_PORT, &hints, &result);
                if (iResult != 0) {
                    DEBUG_PRINT("[+]getaddrinfo failed with error: %d\n", iResult);
                    WSACleanup();
                }

                // Attempt to connect to an address until one succeeds
                for (ptr = result; ptr != NULL; ptr = ptr->ai_next) {

                    // Create a SOCKET for connecting to server
                    ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype,
                        ptr->ai_protocol);
                    if (ConnectSocket == INVALID_SOCKET) {
                        DEBUG_PRINT("[+]socket failed with error: %ld\n", WSAGetLastError());
                        WSACleanup();
                        goto NextRound;
                    }

                    // Connect to server.
                    iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
                    if (iResult == SOCKET_ERROR) {
                        closesocket(ConnectSocket);
                        ConnectSocket = INVALID_SOCKET;
                        continue;
                    }
                    break;
                }


                //  freeaddrinfo(result);

                setsockopt(ConnectSocket, SOL_SOCKET, SO_RCVTIMEO, (char*)&recvTimeout, sizeof(int));
                setsockopt(ConnectSocket, SOL_SOCKET, SO_SNDTIMEO, (char*)&sendTimeout, sizeof(int));



                if (ConnectSocket == INVALID_SOCKET) {
                    DEBUG_PRINT("[+]Unable to connect to server!\n");
                    WSACleanup();
                }
                else {

                    FailCount = 0;
                    // Receive until the peer closes the connection
                    do {

                        memset(Headerbuf, 0, (int)(Headerlen + 1));

                        if (FinalRecvBuff != NULL) {
                            delete[] FinalRecvBuff;
                        }

                        FinalRecvBuff = NULL;
                        FinalRecvBuffSize = 0;
                        BeginTime = GetTickCount();

                        iResult = recv(ConnectSocket, Headerbuf, Headerlen, 0);
                        DEBUG_PRINT("[+]Header received: %s\n", Headerbuf);
                        if (iResult > 0) {
                            int datasize = 0;
                            datasize = atoi(Headerbuf);

                            for (int i = 0; i <= datasize; i++)
                            {
                                iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
                                if (iResult > 0) {
                                    // DEBUG_PRINT("[+]Bytes received: %d\n", iResult);

                                    FinalRecvBuff = CombineArray(FinalRecvBuff, FinalRecvBuffSize, recvbuf, iResult);
                                    FinalRecvBuffSize = FinalRecvBuffSize + iResult;

                                    if (FinalRecvBuffSize >= datasize) {
                                        break;
                                    }

                                }
                                else if (iResult == 0) {
                                    // DEBUG_PRINT("[+]Connection closed\n");
                                    break;
                                }
                                else {
                                    //    DEBUG_PRINT("[+]1 recv failed with error: %d\n", WSAGetLastError());
                                    break;
                                }
                            }
                            if (FinalRecvBuffSize > 0) {
                                recvStr = std::string(FinalRecvBuff, FinalRecvBuffSize);
                                DEBUG_PRINT("[+] recvStr: %s\n", recvStr.c_str());
                                HandleRecv(ConnectSocket, recvStr);
                            }

                        }
                        else if (iResult == 0) {
                            //  DEBUG_PRINT("[+]iResult == 0\n");
                            Sleep(10);
                            //  break;
                            if (GetTickCount() - BeginTime < 500) {
                                FailCount = FailCount + 1;
                            }
                            if (FailCount > 20) {

                                break;
                            }

                        }
                        else {
                            DEBUG_PRINT("[+]2 recv failed with error: %d\n", WSAGetLastError());

                            if (WSAGetLastError() == 10054) { //”à¾€
                              //  break;
                            }

                            if (GetTickCount() - BeginTime < 500) {
                                FailCount = FailCount + 1;
                            }
                            if (FailCount > 20) {

                                break;
                            }

                            Sleep(10);
                            //  break;
                        }
                    } while (true);


                    closesocket(ConnectSocket);
                    WSACleanup();
                }
            }
            else {
                Sleep(1000);
            }
        }
        catch (const char* msg) {
            DEBUG_PRINT("[+]Error Socket: %s\n", msg);
        }
        Sleep(10);
    NextRound: {}
    } while (true);

    // cleanup
    return 0;

}




