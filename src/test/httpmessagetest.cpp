/**
 * @FilePath     : /my_rpc/src/test/httpmessagetest.cpp
 * @Description  :
 * @Author       : naonao
 * @Date         : 2025-05-01 15:09:12
 * @Version      : 0.0.1
 * @LastEditors  : naonao
 * @LastEditTime : 2025-05-01 15:09:12
 * @Copyright (c) 2025 by G, All Rights Reserved.
 **/
#include "../protocol/httpmessage.hpp"
#include "unittestcore.h"

TEST_CASE(HttpMessage_SetAndGetHeader)
{
    Protocol::HttpMessage httpMessage;
    httpMessage.SetHeader("Host", "127.0.0.1");
    ASSERT_EQ(httpMessage.GetHeader("Host"), "127.0.0.1");
    ASSERT_EQ(httpMessage.GetHeader("host"), "");
}

TEST_CASE(HttpMessage_SetBody)
{
    Protocol::HttpMessage httpMessage;
    httpMessage.SetBody(R"({"name":"test"})");
    ASSERT_EQ(httpMessage.GetHeader("Content-Type"), "application/json");
    ASSERT_EQ(httpMessage.GetHeader("Content-Length"), "15");
}

TEST_CASE(HttpMessage_SetStatusCode)
{
    Protocol::HttpMessage httpMessage;
    httpMessage.SetStatusCode(Protocol::OK);
    std::string method;
    std::string url;
    httpMessage.GetMethodAndUrl(method, url);
    ASSERT_EQ(method, "HTTP/1.1");
    ASSERT_EQ(url, "200");
}
