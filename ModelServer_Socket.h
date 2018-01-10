#pragma once

#include <iostream>
#include "ModelServer_struct.h"
#include <WinSock2.h>
#include <ws2tcpip.h>

#define _AFXDLL

#pragma comment (lib, "ws2_32.lib")

#define MAGIC 0x12345678	//delete?


namespace soc
{
	class soc_protocol
	{

	public:
		bool send_socket_state;
		bool receive_socket_state;




		//объект структуры

		//прием
		1 stru_in;
		2 stru_in2;

		//отправка
		3 stru_out;

		//управление моделью
		4 stru_state;

		//
		5 stru_CabinIndicationState;

		//кнопки мфци
		6 stru_MFDIsState;
	private:
		////переменные
		int send_socket, rec_socket, rec_socket_cis, send_socketMFDI, rec_socket_visual;
		struct sockaddr_in send_addr, send_addr_state, send_addr_cis, send_addr_MFDI,
							rec_addr, rec_addr_state, rec_addr_cis, rec_addr_visual;

		////описания функций

		//создание сервера отправки структур
		public: int soc_protocol::create_send_soc(const char *ip, u_short port) {

			WSADATA wsaData;
			WSAStartup(MAKEWORD(2, 2), &wsaData);

			send_socket = socket(AF_INET, SOCK_DGRAM, 0);
			if (send_socket == -1)
				return 0;
			else
			{
				//структура состояния контроллеров обеих кабин
				if (ip == "") ip = DEFAULT_IP_SEND;
				if (port == 0) port = DEFAULT_PORT_SEND;
				memset((char*)&send_addr, 0, sizeof(send_addr));
				send_addr.sin_family = AF_INET;
				send_addr.sin_addr.s_addr = inet_addr(ip);// htonl(INADDR_ANY);
				send_addr.sin_port = htons(port);

				//для управления
				memset((char*)&send_addr_state, 0, sizeof(send_addr_state));
				send_addr_state.sin_family = AF_INET;
				send_addr_state.sin_addr.s_addr = inet_addr(ip);// htonl(INADDR_ANY);
				send_addr_state.sin_port = htons(DEFAULT_PORT_STATE);

				//для кнопок
				send_socketMFDI = socket(AF_INET, SOCK_DGRAM, 0);
				memset((char*)&send_addr_MFDI, 0, sizeof(send_addr_MFDI));
				send_addr_MFDI.sin_family = AF_INET;
				send_addr_MFDI.sin_addr.s_addr = inet_addr(ip);
				send_addr_MFDI.sin_port = htons(DEFAULT_PORT_MFDIsState);

				send_socket_state = true;
				return 1;
			}
		}

		//ОТПРАВКА СООБЩЕНИЯ В ДИНАМИКУ, 1 - хорошо, иначе - ошибка
		public: int soc_protocol::send()
		{
			stru_out.magic = MAGIC;
			if (sendto(send_socket, (char*)&stru_out, (int)sizeof(stru_out), 0,
				(struct sockaddr *) &send_addr, sizeof(send_addr)) <= 0)
				return WSAGetLastError();//ошибка
			else
				return 1;//хорошо
		}

		//отправка структуры управления
		public: int soc_protocol::send_state() {
				if (sendto(send_socket, (char*)&stru_state, (int)sizeof(stru_state), 0,//структура управления
					 (struct sockaddr *) &send_addr_state, sizeof(send_addr_state)) <= 0)
					return WSAGetLastError();//ошибка*/
				else
					return 1;//хорошо
		}

		//отправка структуры МФЦИ кнопок
		public: int soc_protocol::send_MFDIs()
		{
			if (sendto(send_socketMFDI, (char*)&stru_MFDIsState, (int)sizeof(stru_MFDIsState), 0, (struct sockaddr *) &send_addr_MFDI, sizeof(send_addr_MFDI)) <= 0)
				return WSAGetLastError();//ошибка
			else
				return 1;//хорошо
		}

		//создание сервера приемки
		public: int soc_protocol::create_rec_soc(const char *ip, u_short port)
		{
			WSADATA wsaData;
			WSAStartup(MAKEWORD(2, 2), &wsaData);

			rec_socket = socket(PF_INET, SOCK_DGRAM, 0);
			if (rec_socket == -1)
				return WSAGetLastError();
			else
			{
				if (ip == "") ip = DEFAULT_IP_REC;
				if (port == 0) port = DEFAULT_PORT_REC;

				if (setsockopt(rec_socket, SOL_SOCKET, SO_RCVTIMEO, "10", 4) < 0)
					return WSAGetLastError();
				memset((char*)&rec_addr, 0, sizeof(rec_addr));
				rec_addr.sin_family = AF_INET;
				rec_addr.sin_port = htons(port);
				rec_addr.sin_addr.s_addr = inet_addr(ip);

				int recid = bind(rec_socket, (SOCKADDR *)& rec_addr, sizeof(rec_addr));
				if (recid != 0)	return WSAGetLastError();

				//ModelState2
				rec_socket_cis = socket(PF_INET, SOCK_DGRAM, 0);
				if (setsockopt(rec_socket_cis, SOL_SOCKET, SO_RCVTIMEO, "10", 4) < 0) //const char *trueFlag = { "1" };
					return WSAGetLastError();
				memset((char*)&rec_addr_cis, 0, sizeof(rec_addr_cis));
				rec_addr_cis.sin_family = AF_INET;
				rec_addr_cis.sin_port = htons(DEFAULT_PORT_REC2);
				rec_addr_cis.sin_addr.s_addr = inet_addr(ip);

				recid = bind(rec_socket_cis, (SOCKADDR *)& rec_addr_cis, sizeof(rec_addr_cis));
				if (recid != 0) return WSAGetLastError();


				receive_socket_state = true;
				return 1;
			}
		}

		//прием сообщения
		public: int soc_protocol::rec()
		{
			int fromlen = sizeof(rec_addr);
			int strusize = sizeof(stru_in);
			int recid =
				//recvfrom(rec_socket, (char*)&stru_in, strusize, 0, (struct sockaddr *) &rec_addr, &fromlen);
				recv(rec_socket, (char*)&stru_in, strusize, 0);

			/*while (recid)
			{
				int recid = recvfrom(rec_socket, (char*)&stru_in, strusize, 0, (struct sockaddr *) &rec_addr, &fromlen);
				if (recid < 0)
					return WSAGetLastError();//ошибка
			}*/
			if (recid != strusize)
				return recid;// WSAGetLastError();//ошибка
			else
			return 1;//хорошо
			
			/*if (recid <= 0)
				return WSAGetLastError();//ошибка
			else
				return 1;//хорошо*/
		}

		//прием сообщения
		public: int soc_protocol::rec2()
		{
			int fromlen = sizeof(rec_addr_cis);
			int strusize = (int)sizeof(stru_in2);
			int recid = //recvfrom(rec_socket_cis, (char*)&stru_in2, strusize, 0, (struct sockaddr *) &rec_addr_cis, &fromlen);
				recv(rec_socket_cis, (char*)&stru_in2, strusize, 0);
			if (recid != strusize)
				return WSAGetLastError();//ошибка
			else
				return 1;//хорошо
		}


		//прием сообщения Visual
		/*public: int soc_protocol::rec_visual()
		{
			int fromlen = sizeof(rec_addr_visual);
			int strusize = (int)sizeof(PlaneNeTLocationData);
			int recid = recvfrom(rec_socket_visual,
				(char*)&PlaneNeTLocationData, strusize, 0,
				(struct sockaddr *) &rec_addr_visual, &fromlen);
			if (recid <= 0)
				return WSAGetLastError();//ошибка
			else
				return 1;//хорошо
		}*/

				//закрытие сокета
		public: int soc_protocol::close_soc() {// && 
			if ((closesocket(send_socket) < 0))
				return WSAGetLastError();//ошибка
			else
			{
				send_socket_state = false;
				return 1;//хорошо
			}
		}

				//
				//закрытие сокета
		public: int soc_protocol::close_soc_rec() {
			if (closesocket(rec_socket) < 0 && closesocket(rec_socket_cis) < 0)
				return WSAGetLastError();	//error
			else
			{
				receive_socket_state = false;
				return 1;//хорошо
			}
		}
	};
}