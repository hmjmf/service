/*******************************************************
 *  post_service
 *  My Website           https://zhangqixiang.cn
 *  My Github            https://github.com/hmjmf
 *  Email                zqx5449@gmail.com
 * 
 *  Created by 启翔 张 (QiXiang Zhang) on 2018/3/19.
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


int main(int argc, char* argv[]) {
  FLAGS_alsologtostderr = 1;
  google::InitGoogleLogging(argv[0]);


  //boost::asio::io_context::post()
//
//  try{
//    if(argc != 3){
//      LOG(ERROR) << "Usage echo_service_tcp <log_path> <port>";
//      return 1;
//    }
//    google::SetLogDestination(google::GLOG_INFO, argv[1]);
//
//    boost::asio::io_context context;
//    echo_service s(context, std::atoi(argv[2]));
//    context.run();
//
//  } catch (std::exception& e){
//    LOG(FATAL) <<"Exception: " << e.what();
//  }
//  boost::asio::io_service io;

  return 0;
}

