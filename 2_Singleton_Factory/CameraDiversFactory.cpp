

#include <iostream>
#include <CameraDiversFactory.h>
#include "TypeTrait.h"

FactoryManager* FactoryManager::m_pInstance = nullptr;
std::mutex FactoryManager::m_mutex;


DEFINE_TYPE_TRAIT(HasAIMode, AIMode)
//If has AImode, Call AIMode
template <typename T>
typename std::enable_if<HasAIMode<T>::value>::type CallAIMode(T* instance) {
    instance->AIMode();
}

//Else do nothing
template <typename T>
typename std::enable_if<!HasAIMode<T>::value>::type CallAIMode(
    T* instance) {
    (void)instance;
}

bool FactoryManager::init()
{
    std::cout << "Factory init" << std::endl;
    return true;
}

std::unique_ptr<BaseCameraDiver> FactoryManager::GetUniqueDevice(const std::string& type)
{
    return std::unique_ptr<BaseCameraDiver>(Produce(type));
}

BaseCameraDiver* FactoryManager::Produce(const std::string& type)
{
    if (map_.find(type) == map_.end())
    {
        return nullptr;
    }
    return map_[type];
}


MODE_FACTORY_FACTORY(CanonCameraDiver, "CanonCamera");
MODE_FACTORY_FACTORY(FujifilmCameraDiver, "FujifilmCamera");
MODE_FACTORY_FACTORY(KodakCameraDiver, "KodakCamera");


int main()
{
    //Factor init
    FactoryManager::init();

    //Init cameras
    std::unique_ptr<BaseCameraDiver> camera_name_canon =
        FactoryManager::getInstance()->GetUniqueDevice("CanonCamera");
    std::unique_ptr<BaseCameraDiver> camera_name_fujifilm =
        FactoryManager::getInstance()->GetUniqueDevice("FujifilmCamera");
    std::unique_ptr<BaseCameraDiver> camera_name_kodak =
        FactoryManager::getInstance()->GetUniqueDevice("KodakCamera");

    camera_name_canon->init();
    camera_name_fujifilm->init();
    camera_name_kodak->init();

    CallAIMode(dynamic_cast<CanonCameraDiver*>(camera_name_canon.get()));
    CallAIMode(dynamic_cast<FujifilmCameraDiver*>(camera_name_fujifilm.get()));
    CallAIMode(dynamic_cast<KodakCameraDiver*>(camera_name_kodak.get()));

    
    return 0;
}

