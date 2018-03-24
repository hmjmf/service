/*******************************************************
 *  api_caller
 *  My Website           https://zhangqixiang.cn
 *  My Github            https://github.com/hmjmf
 *  Email                zqx5449@gmail.com
 * 
 *  Created by 启翔 张 (QiXiang Zhang) on 2018/3/21.
 *  Copyright (c) 2018 . All rights reserved.
 *******************************************************/



#ifndef SERVICE_API_CALLER_HPP
#define SERVICE_API_CALLER_HPP

#include <iostream>
#include <string>
#include <map>
#include <functional>

using namespace std;

namespace http {
namespace post {

class api_caller {
public:
  static api_caller* getInstance(){
    return instance_;
  }

  const api_caller& operator=(const api_caller &rhs) = delete;
  api_caller(const api_caller& rhs) = delete;

  typedef function<string(map<string,string>&)> handler_type;
  enum state { fail, success };


  void register_api(const string& path, handler_type&& handler);

  state call_api(const string& path, map<string,string>& arg,string& result);


  bool is_alive_api(string &path) const;


private:
  static api_caller* instance_;
  api_caller() = default;

  map<string, handler_type> api_map_;
};

}
}

#endif //SERVICE_API_CALLER_HPP
