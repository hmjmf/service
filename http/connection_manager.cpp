/*******************************************************
 *  connection_manager
 *  My Website           https://zhangqixiang.cn
 *  My Github            https://github.com/hmjmf
 *  Email                zqx5449@gmail.com
 * 
 *  Created by 启翔 张 (QiXiang Zhang) on 2018/3/20.
 *  Copyright (c) 2018 . All rights reserved.
 *******************************************************/



#include "connection_manager.hpp"

namespace http {
namespace web {




void connection_manager::start(connection_ptr c) {
  connections_.insert(c);
  c->start();
}

void connection_manager::stop(connection_ptr c) {
  connections_.erase(c);
  c->stop();
}

void connection_manager::stop_all() {
  for (auto const & c: connections_){
    c->stop();
  }
  connections_.clear();
}






}
}