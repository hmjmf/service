/*******************************************************
 *  api
 *  My Website           https://zhangqixiang.cn
 *  My Github            https://github.com/hmjmf
 *  Email                zqx5449@gmail.com
 * 
 *  Created by 启翔 张 (QiXiang Zhang) on 2018/3/22.
 *  Copyright (c) 2018 . All rights reserved.
 *******************************************************/



#include "api.hpp"



using namespace boost::property_tree;
string to_json(map<string,string>& input){
  //http://einverne.github.io/post/2016/01/boost-learning-note-7.html
  ptree root;
  for (auto i: input){
    root.put(i.first, i.second);
  }
  stringstream s;
  write_json(s, root);
  return s.str();
}