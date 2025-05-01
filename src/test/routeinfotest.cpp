/**
 * @FilePath     : /my_rpc/src/test/routeinfotest.cpp
 * @Description  :
 * @Author       : naonao
 * @Date         : 2025-05-01 15:10:48
 * @Version      : 0.0.1
 * @LastEditors  : naonao
 * @LastEditTime : 2025-05-01 15:10:49
 * @Copyright (c) 2025 by G, All Rights Reserved.
 **/
#include "../core/routeinfo.hpp"
#include "unittestcore.h"

TEST_CASE(RouteInfo_All)
{
    Core::TimeOut   timeOut;
    Core::Route     route;
    Core::RouteInfo routeInfo;
    routeInfo.SetExpireTime(1);
    bool get = routeInfo.GetRoute("ECho", route, timeOut);
    ASSERT_TRUE(get);
    sleep(2);
    get = routeInfo.GetRoute("ECho", route, timeOut, 100);
    ASSERT_TRUE(get);
    get = routeInfo.GetRoute("ECho2", route, timeOut, 100);
    ASSERT_FALSE(get);
}