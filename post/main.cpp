/*******************************************************
 *  main
 *  My Website           http://zhangqixiang.cn
 *  My Github            https://github.com/hmjmf
 *  Email                zqx5449@gmail.com
 * 
 *  Created by 启翔 张 (QiXiang Zhang) on 2018/3/1.
 *  Copyright (c) 2018 . All rights reserved.
 *******************************************************/



#include <iostream>
#include <boost/asio.hpp>
#include "post_server.hpp"
#include "api_caller.hpp"
#include "api.hpp"
using namespace std;


int main(int argc, char* argv[]) {
  http::post::api_caller::getInstance()->register_api("to_json", to_json);
  try{
    if (argc != 3){
      std::cerr << "Usage: http_server <address> <port>\n";
      std::cerr << "  For IPv4, try:\n";
      std::cerr << "    receiver 0.0.0.0 80 \n";
      std::cerr << "  For IPv6, try:\n";
      std::cerr << "    receiver 0::0 80 \n";
      return 1;
    }

    http::post::server s(argv[1], argv[2]);
    s.run();

  } catch (exception& e) {
    cerr << "Exception: " << e.what() << endl;
  }

  return 0;
}