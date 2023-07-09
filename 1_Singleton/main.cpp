#include <ConfigLoader.h>
#include <iostream>

int main()
{

    std::cout << CppAtWork::GetIPAddress() << std::endl;
    std::cout << CppAtWork::GetImageDataPort() << std::endl;
    std::cout << CppAtWork::GetImageHeight() << std::endl;
    std::cout << CppAtWork::GetImageWidth() << std::endl;
    std::cout << CppAtWork::GetErrorLog() << std::endl;

}