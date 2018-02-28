/*******************************************************
 *  echo_service_tcp
 *  My Website           http://zhangqixiang.cn
 *  My Github            https://github.com/hmjmf
 *  Email                zqx5449@gmail.com
 * 
 *  Created by 启翔 张 (QiXiang Zhang) on 2018/2/28.
 *  Copyright (c) 2018 . All rights reserved.
 *******************************************************/



#include <iostream>
#include <glog/logging.h>
#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <string>

using boost::asio::ip::tcp;

class session: public std::enable_shared_from_this<session>{
public:
  session(tcp::socket socket):socket_(std::move(socket)){}

  void start(){
    do_read();
  }

private:
  typedef boost::system::error_code error_code;

  void do_read(){
    auto self(shared_from_this());
    socket_.async_read_some(boost::asio::buffer(data_, max_length),
        [this, self](error_code errorCode, std::size_t len){
          if(!errorCode){
            LOG(INFO) << "read : " << std::string(data_).substr(0,len - 1) + '\0';
            do_write(len);
          } else {
            LOG(ERROR) << "do_read error : " << errorCode.value();
          }
        }
    );
  }
  void do_write(std::size_t len){
    auto self(shared_from_this());
    boost::asio::async_write(socket_, boost::asio::buffer(data_, len),
        [this, self](error_code errorCode, std::size_t /*len*/){
          if(!errorCode){
            do_read();
          } else {
            LOG(ERROR) << "do_write error : " << errorCode.value();
          }
        }
    );
  }

  tcp::socket socket_;
  enum { max_length = 2048 };
  char data_[max_length];
};

class echo_service{
public:
  echo_service(boost::asio::io_context& context, short port):
      acceptor_(context, tcp::endpoint(tcp::v4(), port)) {
    do_accept();
  }
private:
  typedef boost::system::error_code error_code;
  void do_accept(){
    acceptor_.async_accept(
        [this](error_code errorCode, tcp::socket socket){
          if(!errorCode){
            std::make_shared<session>(std::move(socket))->start();
          } else {
            LOG(ERROR) << "do_accept error : " << errorCode.value();
          }
          do_accept();
    });
  }

  tcp::acceptor acceptor_;
};

int main(int argc, char* argv[]) {
  FLAGS_alsologtostderr = 1;
  google::InitGoogleLogging(argv[0]);


  try{
    if(argc != 3){
      LOG(ERROR) << "Usage echo_service_tcp <log_path> <port>";
      return 1;
    }
    google::SetLogDestination(google::GLOG_INFO, argv[1]);

    boost::asio::io_context context;
    echo_service s(context, std::atoi(argv[2]));
    context.run();

  } catch (std::exception& e){
    LOG(FATAL) <<"Exception: " << e.what();
  }
  boost::asio::io_service io;

  return 0;
}