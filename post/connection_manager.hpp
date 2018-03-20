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

#include <set>
#include "connection.hpp"

using namespace std;

namespace http {
namespace post {

class connection_manager {
public:

  connection_manager(const connection_manager&) = delete;
  connection_manager& operator=(const connection_manager&) = delete;

  connection_manager();


  void start(connection_ptr c);

  void stop(connection_ptr c);

  void stop_all();

private:
  set<connection_ptr> connections_;
};

}
}


#endif //SERVICE_CONNECTION_MANAGER_HPP
