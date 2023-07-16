#pragma once



#include<iostream>
#include<memory>
#include<thread>
#include<vector>
#include <map>
#include <mutex>

#include "CameraDivers.h"
#include "Singleton.h"

class FactoryManager
{
public:

    template<typename T>
    class Register_t {
    public:
        Register_t(const std::string& key) {

            FactoryManager::getInstance()->map_.emplace(key, new T());
        }
    };

    std::unique_ptr<BaseCameraDiver> GetUniqueDevice(const std::string& type);
    BaseCameraDiver* Produce(const std::string& type);



    static bool init();



private:

    
    static FactoryManager* m_pInstance;
    static std::mutex m_mutex;
    std::map<std::string, BaseCameraDiver*> map_; 
    DECLARE_SINGLETON(FactoryManager);
};
inline FactoryManager::FactoryManager() {}

#define MODE_FACTORY(T) v2xos_reg_func_str_##T##_

#define MODE_FACTORY_FACTORY(T, key) \
    static FactoryManager::Register_t<T> MODE_FACTORY(T)(key);
