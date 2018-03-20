/*******************************************************
 *  connection
 *  My Website           https://zhangqixiang.cn
 *  My Github            https://github.com/hmjmf
 *  Email                zqx5449@gmail.com
 *
 *  Created by 启翔 张 (QiXiang Zhang) on 2018/3/20.
 *  Copyright (c) 2018 . All rights reserved.
 *******************************************************/



#include "connection.hpp"
#include "connection_manager.hpp"
namespace http {
namespace post {


connection::connection(tcp::socket socket, connection_manager& manager,
                       request_handler& handler)
    : socket_(std::move(socket)),
      connection_manager_(manager),
      request_handler_(handler){
}

void connection::start() {
  do_read();
}

void connection::stop() {
  socket_.close();
}

void connection::do_read() {
  auto self(shared_from_this());
  socket_.async_read_some(boost::asio::buffer(buffer_),
    [this,self](boost::system::error_code ec, size_t bytes_transferred) {
      cerr << buffer_.data() << endl;

      if (!ec){
        request_parser::result_type result;
        tie(result, ignore) = request_parser_.parse(
            request_, buffer_.data(), buffer_.data() + bytes_transferred);

        if (result == request_parser::good) {
          request_handler_.handle_request(request_, reply_);
          do_write();
        } else if (result == request_parser::bad) {
          reply_ = reply::stock_reply(reply::bad_request);
          do_write();
        } else {
          do_read();
        }

      } else if (ec != boost::asio::error::operation_aborted){
        connection_manager_.stop(shared_from_this());
      }
    });
}

void connection::do_write() {
  auto self(shared_from_this());

  boost::asio::async_write(socket_, reply_.to_buffers(),
    [this, self](boost::system::error_code ec, std::size_t){
      if (!ec){
        boost::system::error_code ignored_ec;
        socket_.shutdown(tcp::socket::shutdown_both,ignored_ec);
      }

      if (ec != boost::asio::error::operation_aborted){
        connection_manager_.stop(shared_from_this());
      }
    });
}


}}