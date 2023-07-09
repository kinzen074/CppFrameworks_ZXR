
#include <ConfigLoader.h>
#include <fstream>
#include <sstream>

#include <iostream>
using namespace CppAtWork;

//Init out of class
ConfigLoader* ConfigLoader::m_instance = new (std::nothrow) ConfigLoader();

ConfigLoader* ConfigLoader::GetInstance()
{
    return m_instance;
}

bool ConfigLoader::Init()
{
    
    std::ifstream file(filePath);
    if (!file.is_open())
    {
        return false;
    }

    std::string line;
    std::string currentSection;

    while (std::getline(file, line))
    {
        // delete spaces
        line.erase(line.find_last_not_of(" \t\r\n") + 1);

        if (!line.empty())
        {
            if (line[0] == ';')
            {
                // comment line
                continue;
            }
            else if (line[0] == '[' && line[line.size() - 1] == ']')
            {
                // section
                currentSection = line.substr(1, line.size() - 2);
            }
            else
            {
                // key value
                std::size_t equalsPos = line.find('=');
                if (equalsPos != std::string::npos)
                {
                    std::string key = line.substr(0, equalsPos);
                    std::string value = line.substr(equalsPos + 1);
                    m_configData[currentSection + key] = value;
                }
            }
        }
    }

    file.close();

    return true;

}

//Get Config of Network
const std::string CppAtWork::ConfigLoader::GetIPAddress()
{
    if (!m_isInit)
    {
        return "";
    }
    std::string section = "NetworkConfig";
    std::string key = "IPAddress";
    return  m_configData[section + key];
}
const int ConfigLoader::GetImageDataPort()
{
    if (!m_isInit)
    {
        return 1;
    }
    std::string section = "NetworkConfig";
    std::string key = "ImageDataPort";
    return std::stoi(m_configData[section + key]);
}

//Get Config of Application
const int ConfigLoader::GetImageHeight()
{
    if (!m_isInit)
    {
        return 1;
    }
    std::string section = "Application";
    std::string key = "ImageHeight";
    return std::stoi(m_configData[section + key]);
}
const int ConfigLoader::GetImageWidth()
{
    if (!m_isInit)
    {
        return 1;
    }
    std::string section = "Application";
    std::string key = "ImageWidth";
    return std::stoi(m_configData[section + key]);
}

//Get Config of Log
const bool ConfigLoader::GetErrorLog()
{
    if (!m_isInit)
    {
        return false;
    }
    std::string section = "Log";
    std::string key = "ErrorLogLevel";
    return std::stoi(m_configData[section + key]);
}

//Interface

//Get Config of Network
const std::string CppAtWork::GetIPAddress()
{
    return ConfigLoader::GetInstance()->GetIPAddress();
}
const int CppAtWork::GetImageDataPort()
{
    return ConfigLoader::GetInstance()->GetImageDataPort();
}

//Get Config of Application
const int CppAtWork::GetImageHeight()
{
    return ConfigLoader::GetInstance()->GetImageHeight();
}

const int CppAtWork::GetImageWidth()
{
    return ConfigLoader::GetInstance()->GetImageWidth();
}

//Get Config of Log
const bool CppAtWork::GetErrorLog()
{
    return ConfigLoader::GetInstance()->GetErrorLog();
}
