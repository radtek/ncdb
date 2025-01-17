#pragma once
#include "PiTypeDef.h"
/************************************************************************
    fun:    实现单一程序
    author: liwanliang
    create time:    2013-7-10 11:14
    update time:    2013-7-11 15:33
    remark:     该对象的生存周期必须同应用程序的生存周期一致. 
                对象销毁了, 则占用的互斥对象也会销毁
************************************************************************/
class CSingleProcess
{
public:
    CSingleProcess(void);
    ~CSingleProcess(void);
public:
    

    /************************************************************************
		function：	创建互斥, 标识有程序实例在运行
		remark:		通过同一个互斥对象来达到判断程序是否已经启动
	/************************************************************************/
    bool CreateRunFlag(tcpchar szFlagName);

    /************************************************************************
		function：	判断在这之前是否已经有实例在运行
		remark:		
	/************************************************************************/
    bool IsExistInst();     
private:
    HANDLE      m_hMutex;
    bool        m_bExist;       //是否已有实例在运行
	bool		m_bLocal;		//名字是否在本地空间
};

