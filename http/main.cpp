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
#include "http_server.hpp"

using namespace std;



int main(int argc, char* argv[]) {
  try{
    if (argc != 4){
      std::cerr << "Usage: http_server <address> <port> <doc_root>\n";
      std::cerr << "  For IPv4, try:\n";
      std::cerr << "    receiver 0.0.0.0 80 .\n";
      std::cerr << "  For IPv6, try:\n";
      std::cerr << "    receiver 0::0 80 .\n";
      return 1;
    }

    http::server::server s(argv[1], argv[2], argv[3]);
    s.run();

  } catch (exception& e) {
    cerr << "Exception: " << e.what() << endl;
  }

  return 0;
}