// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//
 #include "stdafx.h"  
#include "SerialPort.h" 
#include <iostream>  

// win os  USB ��������������Ǽ򵥵ĳ���

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

