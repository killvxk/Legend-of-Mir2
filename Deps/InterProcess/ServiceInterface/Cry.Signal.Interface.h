#pragma once
#include <event2/event.h>
#include <evpp/tcp_conn.h>
#include <evpp/logging.h>
#include <google/protobuf/message.h>
#include <Action/Cry.Action.Interface.h>
namespace Cry
{
	namespace Signal
	{
		class ServiceInterface
		{
		public:
			ServiceInterface();
			~ServiceInterface();
		private:
			virtual bool CreateService() = 0;
			virtual bool CancelService() = 0;
		private:
			virtual void OnMessage(const evpp::TCPConnPtr & Conn, evpp::Buffer * Buffer) = 0;
			virtual void OnConnection(const evpp::TCPConnPtr & Conn) = 0;
		public:
			std::shared_ptr<Work> GetWork(const uint64_t uConn);
			std::shared_ptr<Work> GetWork(const std::string & Name);
			std::shared_ptr<Action::ObjectInterface> & GetObjectInterface() { return m_ObjectInterface; }
		protected:
			bool AddWork(const uint64_t uConn, std::shared_ptr<Work> WorkPtr);
			bool AddWork(const std::string & Name, std::shared_ptr<Work> WorkPtr);
			bool DelWork(const uint64_t uConn);
			bool DelWork(const std::string & Name);
			void ClearWork();
		private:
			std::shared_ptr<Action::ObjectInterface>							m_ObjectInterface;
		private:
			std::mutex															m_Mutex;
			std::mutex															m_Name_Mutex;
			// ���乤����
			std::unordered_map<uint64_t, std::shared_ptr<Work>>					m_Work;
			std::unordered_map<std::string, std::shared_ptr<Work>>				m_Name_Work;
		private:
			ServiceInterface(const ServiceInterface &) = default;
			ServiceInterface &operator=(const ServiceInterface &) = default;
		};
	};
};
