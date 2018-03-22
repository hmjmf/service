/*******************************************************
 *  post_server
 *  My Website           https://zhangqixiang.cn
 *  My Github            https://github.com/hmjmf
 *  Email                zqx5449@gmail.com
 * 
 *  Created by 启翔 张 (QiXiang Zhang) on 2018/3/20.
 *  Copyright (c) 2018 . All rights reserved.
 *******************************************************/



#include "post_server.hpp"
namespace http {
namespace post {

using boost::asio::ip::tcp;

server::server(const string& address, const string& port)
    : io_context_(1),
      signals_(io_context_),
      acceptor_(io_context_),
      connection_manager_(){

  signals_.add(SIGINT);
  signals_.add(SIGTERM);
  signals_.add(SIGQUIT);

  do_await_stop();

  tcp::resolver resolver(io_context_);
  tcp::endpoint endpoint =  *resolver.resolve(address, port).begin();

  acceptor_.open(endpoint.protocol());
  acceptor_.set_option(tcp::acceptor::reuse_address(true));
  acceptor_.bind(endpoint);
  acceptor_.listen();

  do_accept();
}

void server::run() {
  io_context_.run();
}

void server::do_await_stop() {
  signals_.async_wait(
      [this](boost::system::error_code ec, int signo){
        acceptor_.close();
        connection_manager_.stop_all();
      });
}

void server::do_accept() {
  acceptor_.async_accept(
      [this](boost::system::error_code ec,tcp::socket socket){
        if (!acceptor_.is_open()){
          return;
        }

        if (!ec){
          connection_manager_.start(std::make_shared<connection>(
              std::move(socket),connection_manager_, request_handler_));
        }

        do_accept();
      });
}


}
}

