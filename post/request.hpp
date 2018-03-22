/*******************************************************
 *  request
 *  My Website           https://zhangqixiang.cn
 *  My Github            https://github.com/hmjmf
 *  Email                zqx5449@gmail.com
 * 
 *  Created by 启翔 张 (QiXiang Zhang) on 2018/3/20.
 *  Copyright (c) 2018 . All rights reserved.
 *******************************************************/



#ifndef SERVICE_REQUEST_HPP
#define SERVICE_REQUEST_HPP

#include <string>
#include <vector>
#include <map>
#include "header.hpp"


namespace http {
namespace post {

class request
{
public:
  std::string method;
  std::string uri;
  int http_version_major;
  int http_version_minor;
  std::vector<header> headers;
  std::map<std::string,std::string> bodys;
};

}
}
#endif //SERVICE_REQUEST_HPP
