/*******************************************************
 *  api_caller
 *  My Website           https://zhangqixiang.cn
 *  My Github            https://github.com/hmjmf
 *  Email                zqx5449@gmail.com
 * 
 *  Created by 启翔 张 (QiXiang Zhang) on 2018/3/21.
 *  Copyright (c) 2018 . All rights reserved.
 *******************************************************/



#include "api_caller.hpp"
namespace http {
namespace post {

api_caller* api_caller::instance_ = new api_caller;

void api_caller::register_api(const string& path,
                              function<string(map<string, string>)>& handler){
  register_api(path,std::move(handler));
}

void api_caller::register_api(const string& path,
                              function<string(map<string, string>)>&& handler){
  api_map_[path] = handler;
}

api_caller::state api_caller::call_api(const string& path,
                                       map<string,string>& arg,
                                       string& result)  {
  try {
    result = api_map_[path](arg);
    return success;
  } catch (exception e){
    cerr << e.what() << endl;
    return fail;
  }
}


}
}