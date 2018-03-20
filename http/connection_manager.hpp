/*******************************************************
 *  connection_manager
 *  My Website           https://zhangqixiang.cn
 *  My Github            https://github.com/hmjmf
 *  Email                zqx5449@gmail.com
 * 
 *  Created by 启翔 张 (QiXiang Zhang) on 2018/3/20.
 *  Copyright (c) 2018 . All rights reserved.
 *******************************************************/



#ifndef SERVICE_CONNECTION_MANAGER_HPP
#define SERVICE_CONNECTION_MANAGER_HPP

#include <memory>
#include "connection.hpp"

namespace http {
namespace server {


class connection_manager {
public:
  typedef std::shared_ptr<connection> connection_ptr;

  void stop_all();
  void start(connection_ptr c);
};

}
}


#endif //SERVICE_CONNECTION_MANAGER_HPP
