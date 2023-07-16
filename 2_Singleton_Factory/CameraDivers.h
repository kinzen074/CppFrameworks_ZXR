#pragma once
#include<iostream>
class BaseCameraDiver
{
public:
    virtual bool init() = 0;
    virtual ~BaseCameraDiver() {};
};

class CanonCameraDiver : public BaseCameraDiver
{
public:
    bool init()
    {
        std::cout << "This is Canon Camera" << std::endl;
        return true;
    }
    void AIMode()
    {
        std::cout << "Using AIMode(By Canon)" << std::endl;
    }
};

class FujifilmCameraDiver : public BaseCameraDiver
{
public:
    bool init()
    {
        std::cout << "This is Fujifilm Camera" << std::endl;
        return true;
    }
    void AIMode()
    {
        std::cout << "Using AIMode(By Fujifilm)" << std::endl;
    }
};

class KodakCameraDiver : public BaseCameraDiver
{
public:
    bool init()
    {
        std::cout << "This is Kodak Camera" << std::endl;
        return true;
    }

};