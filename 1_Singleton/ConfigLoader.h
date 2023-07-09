#pragma once

#include <unordered_map>
#include <string>

const static std::string filePath = ".\\Config.ini";

namespace CppAtWork
{
	class ConfigLoader
	{
		public:

			ConfigLoader() :m_isInit(false) 
			{
				if (Init())
				{
					m_isInit = true;
				}
			}

			//Get Singleton Instance
			static ConfigLoader* GetInstance();

			//Get Config of Network
			const std::string GetIPAddress();
			const int GetImageDataPort();

			//Get Config of Application
			const int GetImageHeight();
			const int GetImageWidth();

			//Get Config of Log
			const bool GetErrorLog();

		private:
			//Singleton Instance
			static ConfigLoader* m_instance;

			//delete copy constructor
			ConfigLoader(const ConfigLoader&) = delete;

			//delete assignment operator 
			ConfigLoader& operator= (const ConfigLoader&) = delete;

			//Config data map
			std::unordered_map<std::string, std::string> m_configData;

			bool Init();
			bool m_isInit;

	};
}

//Interface
namespace CppAtWork
{
	//Get Config of Network
	const std::string GetIPAddress();
	const int GetImageDataPort();

	//Get Config of Application
	const int GetImageHeight();
	const int GetImageWidth();

	//Get Config of Log
	const bool GetErrorLog();

}