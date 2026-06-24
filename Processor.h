#ifndef _Processor_H_
#define _Processor_H_

//
#include <util/tc_singleton.h>
#include "OrderServant.h"

//
using namespace tars;

/**
 *请求处理类
 *
 */
class Processor
{
public:
	/**
	 * 
	*/
	Processor();

	/**
	 * 
	*/
	~Processor();

public:
	//ORDER_IOS      = 87,  //tb_ios_order
	//查询
	int selectIOSOrder();
	//增加
	int UpdateIOSOrder();
};

//singleton
typedef TC_Singleton<Processor, CreateStatic, DefaultLifetime> ProcessorSingleton;

#endif

