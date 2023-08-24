/*! @file
**********************************************************************
<PRE>
ģ����       :
�ļ���       : HttpRequest.cpp
����ļ�     : HttpRequest.h
�ļ�ʵ�ֹ��� : Http ����
����         : Song
�汾         : 1.0
----------------------------------------------------------------------
��ע         :
----------------------------------------------------------------------
�޸ļ�¼     :
�� ��        �汾   �޸���                 �޸�����
2018/4/10    1.0    Song                    ����
</PRE>
**********************************************************************

* ��Ȩ����(c) 2018-2019, ��������Ȩ��

*********************************************************************/
#include "pch.h"
#include "HttpRequest.h"
#include <WinSock.h>
#include <iostream>


//#define DEBUG_PRINT(x) OutputDebugString(x)
//#define DEBUG_PRINT(...) {char cad[512]; sprintf_s(cad, __VA_ARGS__);  OutputDebugStringA(cad);}
#define DEBUG_PRINT(...) 


#pragma comment(lib, "ws2_32.lib")

HttpRequest::HttpRequest(const std::string& ip, int port) : m_ip(ip), m_port(port)
{
}


HttpRequest::~HttpRequest(void)
{
}


std::string getIpAddr(std::string hostName) {
    struct hostent* hostAddr = gethostbyname(hostName.c_str());
    if (hostAddr == nullptr) {
        return "";
    }
    std::string ipv4 = "";

    for (int i = 0; hostAddr->h_addr_list[i]; i++) {
        struct in_addr tmpAddr = *reinterpret_cast<struct in_addr*>(hostAddr->h_addr_list[i]);
        std::string ch = inet_ntoa(tmpAddr);
        ipv4 += ch;
    }
    return ipv4;
}





// �ָ��ַ���
std::vector<std::string> HttpRequest::split(const std::string& s, const std::string& seperator)
{
    std::vector<std::string> result;
    typedef std::string::size_type string_size;
    string_size i = 0;

    try {
        while (i != s.size()) {
            // �ҵ��ַ������׸������ڷָ�������ĸ
            int flag = 0;
            while (i != s.size() && flag == 0) {
                flag = 1;
                for (string_size x = 0; x < seperator.size(); ++x)
                    if (s[i] == seperator[x]) {
                        ++i;
                        flag = 0;
                        break;
                    }
            }

            // �ҵ���һ���ָ������������ָ���֮����ַ���ȡ��
            flag = 0;
            string_size j = i;
            while (j != s.size() && flag == 0) {
                for (string_size x = 0; x < seperator.size(); ++x)
                    if (s[j] == seperator[x]) {
                        flag = 1;
                        break;
                    }
                if (flag == 0)
                    ++j;
            }
            if (i != j) {
                result.push_back(s.substr(i, j - i));
                i = j;
            }
        }
    }
    catch (char* e) {

    }

    return result;
}


std::vector<std::string> split2(std::string s, std::string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }

    res.push_back(s.substr(pos_start));
    return res;
}

int CountString(std::string Content, std::string Target) {
    int occurrences = 0;
    std::string::size_type pos = 0;
    std::string s = Content;
    std::string target = Target;
    while ((pos = s.find(target, pos)) != std::string::npos) {
        ++occurrences;
        pos += target.length();
    }
    return occurrences;
}

// Http GET����
std::string HttpRequest::HttpGet(std::string hostName, int port, std::string api, std::string param) {
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);



    std::string ip = hostName;
    //�������������ip,����������򣬻�ȡip��ַ

    DEBUG_PRINT("[+]Connnect IP=%s\n", ip.c_str());

    for (unsigned i = 0; i < hostName.length(); i++) {
        if (hostName[i] < '0' || hostName[i] > '9') {
            ip = getIpAddr(hostName);
            break;
        }
    }
    //��ַ��˿ڲ���
    sockaddr_in sin;
    sin.sin_family = AF_INET;
    sin.sin_port = htons(port);
    sin.sin_addr.s_addr = inet_addr(ip.c_str());

    DEBUG_PRINT("[+]Connnect IP=%s\n", ip.c_str());
    //��ʼ��socket
    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == SOCKET_ERROR) {
        return "��ʼ��socketʧ��";
    }
    //���ӷ�����
    int connectStatus = connect(sock, (const struct sockaddr*)&sin, sizeof(sin));
    if (connectStatus == INVALID_SOCKET) {
        return "���ӷ�����ʧ��";
    }
    //��ʼ�����͵�����
    std::string data = "";
    data += "GET " + api + " HTTP/1.1\r\n";
    //HEADER��Ϣ
    data += "Host: " + hostName + "\r\n";
    data += "Content-Length: 0";
    data += "\r\n";
    data += "Cache-Control: no-cache\r\n";
    data += "Content-Type:  application/x-www-form-urlencoded\r\n";
    data += "Accept: text/html,*/*;q=0.8\r\n";
    //������Ϣ
    data += "\r\n";
    data += param;



    //cout << data << endl; exit(0);
    //��������
    int sendStatus = send(sock, data.c_str(), data.length(), 0);
    if (sendStatus == -1) {

        return  "��������ʧ��";
    }

    //��ȡ���ص���Ϣ
    char recvStr[4096] = { 0 };
    memset(recvStr, 0, 4096);
    int recvStatus = 0;
    recvStatus = recv(sock, recvStr, 4096, 0);
    if (recvStatus == -1) {
        return  "��������ʧ��";
    }
    std::string Result = recvStr;
    std::string FinalResult = "";

    std::vector<std::string> v = split2(Result, "\n");

    if (v.size() > 0) {
        for (auto i : v) {
            FinalResult = i;
            if (CountString(FinalResult, ".") >= 3) {
                break;
            }
         //   DEBUG_PRINT("[+]i =%s\n", i.c_str());
        }
      //  DEBUG_PRINT("[+]FinalResult =%s\n", FinalResult.c_str());
    }
   

    closesocket(sock);
    WSACleanup();


    return FinalResult;
}



// Http POST����
std::string HttpRequest::HttpPost(std::string req, std::string data)
{
    std::string ret = ""; // ����Http Response
    try
    {
        // ��ʼ����socket��ʼ��;
        WSADATA wData;
        ::WSAStartup(MAKEWORD(2, 2), &wData);

        SOCKET clientSocket = socket(AF_INET, 1, 0);
        struct sockaddr_in ServerAddr = { 0 };
        ServerAddr.sin_addr.s_addr = inet_addr(m_ip.c_str());

        DEBUG_PRINT("[+]Connnect IP=%s\n", m_ip.c_str());

        ServerAddr.sin_port = htons(m_port);
        ServerAddr.sin_family = AF_INET;
        int errNo = connect(clientSocket, (sockaddr*)&ServerAddr, sizeof(ServerAddr));
        if (errNo == 0)
        {
            // ��ʽ��data����
            char len[10] = { 0 };
            sprintf_s(len, "%d", data.length());
            std::string strLen = len;

            //  "POST /[req] HTTP/1.1\r\n"
            //  "Connection:Keep-Alive\r\n"
            //  "Accept-Encoding:gzip, deflate\r\n"
            //  "Accept-Language:zh-CN,en,*\r\n"
            //  "Content-Length:[len]\r\n"
            //  "Content-Type:application/x-www-form-urlencoded; charset=UTF-8\r\n"
            //  "User-Agent:Mozilla/5.0\r\n\r\n"
            //  "[data]\r\n\r\n";
            std::string strSend = " HTTP/1.1\r\n"
                "Cookie:16888\r\n"
                "Content-Type:application/x-www-form-urlencoded\r\n"
                "Charset:utf-8\r\n"
                "Content-Length:";
            strSend = "POST " + req + strSend + strLen + "\r\n\r\n" + data;

            // ����
            errNo = send(clientSocket, strSend.c_str(), strSend.length(), 0);
            if (errNo > 0)
            {
                //cout<<"���ͳɹ�\n";
            }
            else
            {
                std::cout << "errNo:" << errNo << std::endl;
                return ret;
            }

            // ����
            char bufRecv[3069] = { 0 };
            errNo = recv(clientSocket, bufRecv, 3069, 0);
            if (errNo > 0)
            {
                ret = bufRecv;// ������ճɹ����򷵻ؽ��յ���������
            }
            else
            {
                std::cout << "errNo:" << errNo << std::endl;
                return ret;
            }
        }
        else
        {
            errNo = WSAGetLastError();
        }
        // socket��������
        ::WSACleanup();
    }
    catch (...)
    {
        return "";
    }
    return ret;
}

// �ϳ�JSON�ַ���
std::string HttpRequest::genJsonString(std::string key, int value)
{
    char buf[128] = { 0 };
    sprintf_s(buf, "{\"%s\":%d}", key.c_str(), value);
    std::string ret = buf;
    return ret;
}



// ��Response�в���key��Ӧ��Header������
std::string HttpRequest::getHeader(std::string respose, std::string key)
{
    std::vector<std::string> lines = split(respose, "\r\n");
    for (int i = 0; i < lines.size(); i++)
    {
        std::vector<std::string> line = split(lines[i], ": ");// ע��ո�
        if (line.size() >= 2 && line[0] == key)
        {
            return line[1];
        }
    }
    return "";
}