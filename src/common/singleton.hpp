/**
 * @FilePath     : /my_rpc/src/common/singleton.hpp
 * @Description  :
 * @Author       : naonao
 * @Date         : 2025-05-01 14:33:13
 * @Version      : 0.0.1
 * @LastEditors  : naonao
 * @LastEditTime : 2025-05-01 14:33:13
 * @Copyright (c) 2025 by G, All Rights Reserved.
 **/
#pragma once

namespace Common
{
//单例模版类
template<class Type>
class Singleton
{
public:
    static Type& Instance()
    {
        static Type object;
        return object;
    }
};
}   // namespace Common
