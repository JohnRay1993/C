//#pragma once

#include "MFCI_struct.h"
#include <WinSock2.h>
#include <ws2tcpip.h>
#include <comdef.h>

#pragma comment (lib, "ws2_32.lib")

//для МФЦИ
#define DEFAULT_PORT 5513
#define DEFAULT_IP "192.168.11.67"//"127.0.0.1"//"192.168.11.25"//"192.20.98.12"
#define DEFAULT_IP1	"192.20.98.12"
#define DEFAULT_IP2	"192.20.98.13"
#define DEFAULT_IP3	"192.20.98.14"

//Для ПУИ
#define DEFAULT_PORT_PUI 5514
#define DEFAULT_IP_PUI "192.168.11.67"//"127.0.0.1"//"192.168.11.25"//"192.20.98.12"


//rec
#define DEFAULT_PORT_REC 7777
#define DEFAULT_IP_REC "192.168.11.13"//"192.20.98.11"//"192.168.11.13"//"192.168.11.13"

/*
Errors:
10		error read ini file, main section

*/

namespace sockserv
{
	class socket_server
	{

	public:
		//объект структуры
		MFCIstruc stru;	//МФЦИ
		PUIstruc struPUI;	//ПУИ
		MFCI_struct_out MFCI_struct_out;

	private:
		////переменные
		int server_socket, server_socket1, server_socket2, server_socket3, server_socket_PUI,	rec_socket;
		struct sockaddr_in server_address, server_address2, server_address3,					rec_addr;
		TCHAR read_ini[20];
		int type = 1;//1 - 1, 2 - >2
		//char ip[15];
		const char *ip;
		u_short port;

	public:
		int
			MFCI_socket_1, MFCI_socket_2, MFCI_socket_3,	//1st cabin
			MFCI_socket_4, MFCI_socket_5, MFCI_socket_6,	//2nd cabin
			MFCI_socket_7, MFCI_socket_8, MFCI_socket_9,	//2nd player
			PUI_socket_1,
			PUI_socket_2,
			MFCI_socket_out;

		struct sockaddr_in
			MFCI_addr_1, MFCI_addr_2, MFCI_addr_3,
			MFCI_addr_4, MFCI_addr_5, MFCI_addr_6,
			MFCI_addr_7, MFCI_addr_8, MFCI_addr_9,
			PUI_addr_1,
			PUI_addr_2,
			MFCI_addr_out;

	////описания функций

	///ОТПРАВКА
	//создание сервера
	private:	int socket_server::create_socket(int num, const char *IP_MFCI, u_short PORT_MFCI) {
		switch (num)
		{
		case 1: {
			MFCI_socket_1 = socket(AF_INET, SOCK_DGRAM, 0);	if (MFCI_socket_1 == -1) return 0;
			memset((char*)&MFCI_addr_1, 0, sizeof(MFCI_addr_1));
			MFCI_addr_1.sin_family = AF_INET;
			MFCI_addr_1.sin_addr.s_addr = inet_addr(IP_MFCI);
			MFCI_addr_1.sin_port = htons(PORT_MFCI);
			break;
		}
		case 2: {
			MFCI_socket_2 = socket(AF_INET, SOCK_DGRAM, 0);	if (MFCI_socket_2 == -1) return 0;
			memset((char*)&MFCI_addr_2, 0, sizeof(MFCI_addr_2));
			MFCI_addr_2.sin_family = AF_INET;
			MFCI_addr_2.sin_addr.s_addr = inet_addr(IP_MFCI);
			MFCI_addr_2.sin_port = htons(PORT_MFCI);
			break;
		}
		case 3: {
			MFCI_socket_3 = socket(AF_INET, SOCK_DGRAM, 0);	if (MFCI_socket_3 == -1) return 0;
			memset((char*)&MFCI_addr_3, 0, sizeof(MFCI_addr_3));
			MFCI_addr_3.sin_family = AF_INET;
			MFCI_addr_3.sin_addr.s_addr = inet_addr(IP_MFCI);
			MFCI_addr_3.sin_port = htons(PORT_MFCI);
			break;
		}
		case 4: {
			MFCI_socket_4 = socket(AF_INET, SOCK_DGRAM, 0);	if (MFCI_socket_4 == -1) return 0;
			memset((char*)&MFCI_addr_4, 0, sizeof(MFCI_addr_4));
			MFCI_addr_4.sin_family = AF_INET;
			MFCI_addr_4.sin_addr.s_addr = inet_addr(IP_MFCI);
			MFCI_addr_4.sin_port = htons(PORT_MFCI);
			break;
		}
		case 5: {
			MFCI_socket_5 = socket(AF_INET, SOCK_DGRAM, 0);	if (MFCI_socket_5 == -1) return 0;
			memset((char*)&MFCI_addr_5, 0, sizeof(MFCI_addr_5));
			MFCI_addr_5.sin_family = AF_INET;
			MFCI_addr_5.sin_addr.s_addr = inet_addr(IP_MFCI);
			MFCI_addr_5.sin_port = htons(PORT_MFCI);
			break;
		}
		case 6: {
			MFCI_socket_6 = socket(AF_INET, SOCK_DGRAM, 0);	if (MFCI_socket_6 == -1) return 0;
			memset((char*)&MFCI_addr_6, 0, sizeof(MFCI_addr_6));
			MFCI_addr_6.sin_family = AF_INET;
			MFCI_addr_6.sin_addr.s_addr = inet_addr(IP_MFCI);
			MFCI_addr_6.sin_port = htons(PORT_MFCI);
			break;
		}
		case 7: {
			MFCI_socket_7 = socket(AF_INET, SOCK_DGRAM, 0);	if (MFCI_socket_7 == -1) return 0;
			memset((char*)&MFCI_addr_7, 0, sizeof(MFCI_addr_7));
			MFCI_addr_7.sin_family = AF_INET;
			MFCI_addr_7.sin_addr.s_addr = inet_addr(IP_MFCI);
			MFCI_addr_7.sin_port = htons(PORT_MFCI);
			break;
		}
		case 8: {
			MFCI_socket_8 = socket(AF_INET, SOCK_DGRAM, 0);	if (MFCI_socket_8 == -1) return 0;
			memset((char*)&MFCI_addr_8, 0, sizeof(MFCI_addr_8));
			MFCI_addr_8.sin_family = AF_INET;
			MFCI_addr_8.sin_addr.s_addr = inet_addr(IP_MFCI);
			MFCI_addr_8.sin_port = htons(PORT_MFCI);
			break;
		}
		case 9: {
			MFCI_socket_9 = socket(AF_INET, SOCK_DGRAM, 0);	if (MFCI_socket_9 == -1) return 0;
			memset((char*)&MFCI_addr_9, 0, sizeof(MFCI_addr_9));
			MFCI_addr_9.sin_family = AF_INET;
			MFCI_addr_9.sin_addr.s_addr = inet_addr(IP_MFCI);
			MFCI_addr_9.sin_port = htons(PORT_MFCI);
			break;
		}
		case 10: {
			PUI_socket_1 = socket(AF_INET, SOCK_DGRAM, 0);	if (PUI_socket_1 == -1) return 0;
			memset((char*)&PUI_addr_1, 0, sizeof(PUI_addr_1));
			PUI_addr_1.sin_family = AF_INET;
			PUI_addr_1.sin_addr.s_addr = inet_addr(IP_MFCI);
			PUI_addr_1.sin_port = htons(PORT_MFCI);
			break;
		}
		case 11: {
			PUI_socket_2 = socket(AF_INET, SOCK_DGRAM, 0);	if (PUI_socket_2 == -1) return 0;
			memset((char*)&PUI_addr_2, 0, sizeof(PUI_addr_2));
			PUI_addr_2.sin_family = AF_INET;
			PUI_addr_2.sin_addr.s_addr = inet_addr(IP_MFCI);
			PUI_addr_2.sin_port = htons(PORT_MFCI);
			break;
		}
		default:
			break;
		}
		return 1;
	}
	public:		int socket_server::create_server(){
		int id(0);

			//create wsadata
			WSADATA wsaData;
			WSAStartup(MAKEWORD(2, 2), &wsaData);

			//XML Config File READ and create sockets
			System::Xml::XmlTextReader ^r = gcnew System::Xml::XmlTextReader(".\\MFCI_Controller_addresses.xml");
			while (r->Read())
			{
				switch (r->NodeType)
				{
				case System::Xml::XmlNodeType::Element:
				{
					if (r->Name == "MFCI_IN")
					{
						while (r->MoveToNextAttribute())
						{
							if (r->Name == "ID")	id = int::Parse(r->Value);
							if (r->Name == "IP")	ip = (const char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(r->Value);
							if (r->Name == "PORT")	port = int::Parse(r->Value);
						}
						if (!create_socket(id, ip, port))	return WSAGetLastError();
					}
					if (r->Name == "PUI_IN")
					{
						while (r->MoveToNextAttribute())
						{
							if (r->Name == "ID")	id = int::Parse(r->Value);	if (id == 1) id = 10; if (id == 2) id = 11;
							if (r->Name == "IP")	ip = (const char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(r->Value);
							if (r->Name == "PORT")	port = int::Parse(r->Value);
						}
						if (!create_socket(id, ip, port))	return WSAGetLastError();
					}
				}
					break;

				default:
					break;
				}
			}
			
			return 1;
		}

	//отправка МФЦИ
	public:		int socket_server::send(){
			/*if (sendto(server_socket, (char*)&stru, (int)sizeof(stru), 0, (struct sockaddr *) &server_address, sizeof(server_address)) <= 0)
				return WSAGetLastError();//ошибка*/

		if (MFCI_socket_1)
			if (sendto(MFCI_socket_1, (char*)&stru, (int)sizeof(stru), 0, (struct sockaddr *) &MFCI_addr_1, sizeof(MFCI_addr_1)) <= 0)
				return WSAGetLastError();//ошибка
		
		if (MFCI_socket_2)
			if (sendto(MFCI_socket_2, (char*)&stru, (int)sizeof(stru), 0, (struct sockaddr *) &MFCI_addr_2, sizeof(MFCI_addr_2)) <= 0)
				return WSAGetLastError();//ошибка

		/*if (MFCI_socket_3)
			if (sendto(MFCI_socket_3, (char*)&stru, (int)sizeof(stru), 0, (struct sockaddr *) &MFCI_addr_3, sizeof(MFCI_addr_3)) <= 0)
				return WSAGetLastError();//ошибка

		if (MFCI_socket_4)
			if (sendto(MFCI_socket_4, (char*)&stru, (int)sizeof(stru), 0, (struct sockaddr *) &MFCI_addr_4, sizeof(MFCI_addr_4)) <= 0)
				return WSAGetLastError();//ошибка

		if (MFCI_socket_5)
			if (sendto(MFCI_socket_5, (char*)&stru, (int)sizeof(stru), 0, (struct sockaddr *) &MFCI_addr_5, sizeof(MFCI_addr_5)) <= 0)
				return WSAGetLastError();//ошибка

		if (MFCI_socket_6)
			if (sendto(MFCI_socket_6, (char*)&stru, (int)sizeof(stru), 0, (struct sockaddr *) &MFCI_addr_6, sizeof(MFCI_addr_6)) <= 0)
				return WSAGetLastError();//ошибка

		if (MFCI_socket_7)
			if (sendto(MFCI_socket_7, (char*)&stru, (int)sizeof(stru), 0, (struct sockaddr *) &MFCI_addr_7, sizeof(MFCI_addr_7)) <= 0)
				return WSAGetLastError();//ошибка

		if (MFCI_socket_8)
			if (sendto(MFCI_socket_8, (char*)&stru, (int)sizeof(stru), 0, (struct sockaddr *) &MFCI_addr_8, sizeof(MFCI_addr_8)) <= 0)
				return WSAGetLastError();//ошибка

		if (MFCI_socket_9)
			if (sendto(MFCI_socket_9, (char*)&stru, (int)sizeof(stru), 0, (struct sockaddr *) &MFCI_addr_9, sizeof(MFCI_addr_9)) <= 0)
				return WSAGetLastError();//ошибка*/

		return 1;//хорошо
	}

	//отправка ПУИ
	public:		int socket_server::send_PUI() {
		/*if (sendto(server_socket2, (char*)&struPUI, (int)sizeof(struPUI), 0, (struct sockaddr *) &server_address2, sizeof(server_address2)) <= 0)
			return WSAGetLastError();//ошибка*/
		if (sendto(PUI_socket_1, (char*)&struPUI, (int)sizeof(struPUI), 0, (struct sockaddr *) &PUI_addr_1, sizeof(PUI_addr_1)) <= 0)
			return WSAGetLastError();//ошибка
		else
			if (sendto(PUI_socket_2, (char*)&struPUI, (int)sizeof(struPUI), 0, (struct sockaddr *) &PUI_addr_2, sizeof(PUI_addr_2)) <= 0)
				return WSAGetLastError();//ошибка
			else
				return 1;//хорошо
	}

	///ПРИЁМ
	//create rec from MFCI
	public:		int socket_server::create_rec()
	{
		WSADATA wsaData;
		WSAStartup(MAKEWORD(2, 2), &wsaData);

		ip = "";
		port = 0;

		//read xml
		System::Xml::XmlTextReader ^r = gcnew System::Xml::XmlTextReader(".\\MFCI_Controller_addresses.xml");
		while (r->Read()) {
			switch (r->NodeType)
			{
			case System::Xml::XmlNodeType::Element:
			{
				if (r->Name == "MFCI_OUT") {
					while (r->MoveToNextAttribute())
					{
						if (r->Name == "IP")	ip = (const char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(r->Value);
						if (r->Name == "PORT")	port = int::Parse(r->Value);
					}					
				}
			}
			break;
			}
		}

		//create socket
		if (ip != "" && port > 0)
		{
			MFCI_socket_out = socket(PF_INET, SOCK_DGRAM, 0);
			setsockopt(MFCI_socket_out, SOL_SOCKET, SO_RCVTIMEO, "1", 4);

			memset((char*)&MFCI_addr_out, 0, sizeof(MFCI_addr_out));
			MFCI_addr_out.sin_family = AF_INET;
			MFCI_addr_out.sin_port = htons(port);
			MFCI_addr_out.sin_addr.s_addr = inet_addr(ip);

			int recid = bind(MFCI_socket_out, (SOCKADDR *)& MFCI_addr_out, sizeof(MFCI_addr_out));
			if (recid != 0)	return WSAGetLastError();

			return 1;
		}
		else
			return 0;

		/*WSADATA wsaData;
		WSAStartup(MAKEWORD(2, 2), &wsaData);

		rec_socket = socket(PF_INET, SOCK_DGRAM, 0);
		if (rec_socket == -1)
			return WSAGetLastError();
		else
		{
			//read ini test
			GetPrivateProfileString(TEXT("Main"), TEXT("Recv_MFCI_port"), TEXT("error ini Tests"), read_ini, 20, TEXT(".\\MFCI_Controller_addresses.ini"));
			if (read_ini[0] == 'e')
				return 12;
			else
				port = _wtoi(read_ini);

			GetPrivateProfileString(TEXT("Main"), TEXT("Recv_MFCI_ip"), TEXT("error ini Tests"), read_ini, 20, TEXT(".\\MFCI_Controller_addresses.ini"));
			if (read_ini[0] == 'e')
				return 13;
			else
				wcstombs(ip, read_ini, 15);

			setsockopt(rec_socket, SOL_SOCKET, SO_RCVTIMEO, "1", 4);

			memset((char*)&rec_addr, 0, sizeof(rec_addr));
			rec_addr.sin_family = AF_INET;
			rec_addr.sin_port = htons(port);
			rec_addr.sin_addr.s_addr = inet_addr(ip);

			int recid = bind(rec_socket, (SOCKADDR *)& rec_addr, sizeof(rec_addr));
			if (recid != 0)
				return WSAGetLastError();

			return 1;
		}*/
	}

	//rec from MFCI
	public: int socket_server::rec() {
		int fromlen = sizeof(MFCI_addr_out);
		int strusize = sizeof(MFCI_struct_out);
		int recid = //recv(rec_socket, (char*)&MFCI_struct_out, strusize, 0);
			recvfrom(MFCI_socket_out, (char*)&MFCI_struct_out, strusize, 0, (struct sockaddr *) &MFCI_addr_out, &fromlen);
		if (recid < 0)
			return WSAGetLastError();//ошибка
		else
			return 1;//хорошо
	}

	//закрытие сокета
	public: int socket_server::close_server() {
			/*if (closesocket(server_socket) < 0)
				return 0;//ошибка*/
		if (closesocket(MFCI_socket_1) < 0 || closesocket(MFCI_socket_2) < 0 || closesocket(MFCI_socket_3) < 0 || 
			closesocket(MFCI_socket_4) < 0 || closesocket(MFCI_socket_5) < 0 || closesocket(MFCI_socket_6) < 0 || 
			closesocket(MFCI_socket_7) < 0 || closesocket(MFCI_socket_8) < 0 || closesocket(MFCI_socket_9) < 0 ||
			closesocket(PUI_socket_1) < 0 || closesocket(PUI_socket_2) < 0 ||
			closesocket(MFCI_socket_out) < 0)
			return WSAGetLastError();//ошибка
		else
			if (closesocket(rec_socket) < 0)
				return WSAGetLastError();//ошибка
			else
				return 1;//хорошо
		}

	};
}