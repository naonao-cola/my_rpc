/**
 * @FilePath     : /my_rpc/src/common/defer.hpp
 * @Description  :
 * @Author       : naonao
 * @Date         : 2025-05-01 14:28:09
 * @Version      : 0.0.1
 * @LastEditors  : naonao
 * @LastEditTime : 2025-05-01 14:28:09
 * @Copyright (c) 2025 by G, All Rights Reserved.
 **/
#pragma once

#include <functional>

namespace Common
{
class Defer
{
public:
    Defer(std::function<void(void)> func)
        : func_(func)
    {
    }
    ~Defer()
    {
        func_();
    }

private:
    std::function<void(void)> func_;
};
}   // namespace Common