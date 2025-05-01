/**
 * @FilePath     : /my_rpc/src/test/timertest.cpp
 * @Description  :
 * @Author       : naonao
 * @Date         : 2025-05-01 15:11:14
 * @Version      : 0.0.1
 * @LastEditors  : naonao
 * @LastEditTime : 2025-05-01 15:11:15
 * @Copyright (c) 2025 by G, All Rights Reserved.
 **/
#include <unistd.h>

#include <iostream>

#include "../core/timer.hpp"
#include "unittestcore.h"

void myTimer(void* data)
{
    *(bool*)data = true;
    std::cout << "timer call currentTime = " << time(nullptr) << std::endl;
}
void myTimer2(void* data)
{
    *(bool*)data = true;
    std::cout << "timer2 call currentTime = " << time(nullptr) << std::endl;
}
void myTimer3(void* data)
{
    *(bool*)data = true;
    std::cout << "timer3 call currentTime = " << time(nullptr) << std::endl;
}

TEST_CASE(Timer_Register)
{
    Core::Timer     timer;
    Core::TimerData timerData;
    bool            temp1 = false;
    bool            temp2 = false;
    bool            temp3 = false;
    uint64_t        id    = timer.Register(myTimer, &temp1, 1000);
    ASSERT_EQ(id, 1);
    id = timer.Register(myTimer2, &temp2, 3000);
    ASSERT_EQ(id, 2);
    id = timer.Register(myTimer3, &temp3, 4000);
    ASSERT_EQ(id, 3);
    std::cout << "begin time " << time(nullptr) << std::endl;
    while (true) {
        if (temp1 && temp2)
            break;
        bool get = timer.GetLastTimer(timerData);
        if (get) {
            int64_t temp = timer.TimeOutMs(timerData);
            usleep(temp * 1000);
            timer.Run(timerData);
        }
        if (temp2) {
            timer.Cancel(id);   // 取消myTimer3的执行。
        }
    }
    ASSERT_FALSE(temp3);
}