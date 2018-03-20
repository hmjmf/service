/*******************************************************
 *  connection
 *  My Website           https://zhangqixiang.cn
 *  My Github            https://github.com/hmjmf
 *  Email                zqx5449@gmail.com
 * 
 *  Created by 启翔 张 (QiXiang Zhang) on 2018/3/20.
 *  Copyright (c) 2018 . All rights reserved.
 *******************************************************/



#ifndef SERVICE_CONNECTION_HPP
#define SERVICE_CONNECTION_HPP

#include <memory>
#include <iostream>
#include <boost/asio.hpp>
#include <array>
#include "request_handler.hpp"
#include "request_parser.hpp"
#include "request.hpp"


using boost::asio::ip::tcp;
using namespace std;

namespace http {
namespace post {

class connection_manager;
class connection : public std::enable_shared_from_this<connection>{
public:
  connection& operator=(const connection&) = delete;
  connection(const connection&) = delete;

  explicit connection(tcp::socket socket, connection_manager& manager,
                      request_handler& handler);

  void start();

  void stop();

private:
  void do_read();

  void do_write();

  tcp::socket socket_;
  connection_manager& connection_manager_;
  request_handler& request_handler_;
  request_parser request_parser_;

  array<char, 8192> buffer_;

  request request_;

  reply reply_;

};

typedef std::shared_ptr<connection> connection_ptr;

}
}


#endif //SERVICE_CONNECTION_HPP
