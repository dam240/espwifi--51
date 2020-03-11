// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//
 #include "stdafx.h"  
#include "SerialPort.h" 
#include <iostream>  

// win os  USB 驱动基于这个就是简单的程序

int _tmain(int argc, _TCHAR* argv[])
{
	CSerialPort mySerialPort;  
 
    if (!mySerialPort.InitPort(8))  
    {  
        std::cout << "initPort fail !" << std::endl;  
    }  
    else 
    {  
        std::cout << "initPort success !" << std::endl;  
    }  
 
    if (!mySerialPort.OpenListenThread())  
    {  
        std::cout << "OpenListenThread fail !" << std::endl;  
    }  
    else 
    {  
        std::cout << "OpenListenThread success !" << std::endl;  
    }  
 
    int temp;  
    std::cin >> temp;  
 
    return 0;  

}

