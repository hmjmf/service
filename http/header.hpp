/*******************************************************
 *  header
 *  My Website           https://zhangqixiang.cn
 *  My Github            https://github.com/hmjmf
 *  Email                zqx5449@gmail.com
 * 
 *  Created by 启翔 张 (QiXiang Zhang) on 2018/3/20.
 *  Copyright (c) 2018 . All rights reserved.
 *******************************************************/



#ifndef SERVICE_HEADER_HPP
#define SERVICE_HEADER_HPP

#include <string>

namespace http {
namespace web {

struct header
{
  std::string name;
  std::string value;
};

} // namespace web
} // namespace http

#endif //SERVICE_HEADER_HPP
