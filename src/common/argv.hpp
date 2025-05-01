/**
 * @FilePath     : /my_rpc/src/common/argv.hpp
 * @Description  :
 * @Author       : naonao
 * @Date         : 2025-05-01 14:22:55
 * @Version      : 0.0.1
 * @LastEditors  : naonao
 * @LastEditTime : 2025-05-01 14:22:55
 * @Copyright (c) 2025 by G, All Rights Reserved.
 **/
#pragma once
#include <assert.h>

#include <unordered_map>

namespace Common
{
class Argv
{
public:
    Argv& Set(std::string name, void* arg)
    {
        argv_[name] = arg;
        return *this;
    }
    template<class Type>
    Type& Arg(std::string name)
    {
        auto iter = argv_.find(name);
        assert(iter != argv_.end());
        return *(Type*)iter->second;
    }

private:
    std::unordered_map<std::string, void*> argv_;   // 参数变量名到变量指针的映射
};
}   // namespace Common
