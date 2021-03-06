/*******************************************************
 *  post_server
 *  My Website           https://zhangqixiang.cn
 *  My Github            https://github.com/hmjmf
 *  Email                zqx5449@gmail.com
 * 
 *  Created by 启翔 张 (QiXiang Zhang) on 2018/3/20.
 *  Copyright (c) 2018 . All rights reserved.
 *******************************************************/



#ifndef SERVICE_POST_SERVER_HPP
#define SERVICE_POST_SERVER_HPP

#include <iostream>
#include <boost/asio.hpp>
#include <string>
#include "connection_manager.hpp"
#include "request_handler.hpp"


using namespace std;

namespace http {
namespace post {

class server {
public:
  server(const server &) = delete;

  server &operator=(const server &) = delete;

  explicit server(const string &address, const string &port);

  void run();

private:

  void do_await_stop();

  void do_accept();


  boost::asio::io_context io_context_;
  boost::asio::signal_set signals_;
  boost::asio::ip::tcp::acceptor acceptor_;
  request_handler request_handler_;

  connection_manager connection_manager_;


};
}
}


#endif //SERVICE_POST_SERVER_HPP
