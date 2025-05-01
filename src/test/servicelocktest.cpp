/**
 * @FilePath     : /my_rpc/src/test/servicelocktest.cpp
 * @Description  :
 * @Author       : naonao
 * @Date         : 2025-05-01 15:10:53
 * @Version      : 0.0.1
 * @LastEditors  : naonao
 * @LastEditTime : 2025-05-01 15:10:54
 * @Copyright (c) 2025 by G, All Rights Reserved.
 **/
#include "../common/servicelock.hpp"
#include "unittestcore.h"

TEST_CASE(ServiceLock_lock)
{
    bool result = Common::ServiceLock::lock("/home/backend/lock/subsys/" + Common::Utils::GetSelfName());
    ASSERT_TRUE(result);
    result = Common::ServiceLock::lock("/home/backend/lock/subsys/" + Common::Utils::GetSelfName());
    ASSERT_TRUE(result);
}