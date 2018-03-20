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
#include <boost/asio.hpp>
#include "request_handler.hpp"
using boost::asio::ip::tcp;

namespace http {
namespace server {

class connection_manager;
class connection : public std::enable_shared_from_this<connection>{
public:
  explicit connection(tcp::socket socket, connection_manager& manager,
                      request_handler& handler);
};


}
}


#endif //SERVICE_CONNECTION_HPP
