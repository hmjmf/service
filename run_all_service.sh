#!/usr/bin/env bash
mkdir -p build
cd build
cmake ..
make

nohup ./echo/echo_service_tcp ./echo/echolog 2000 > echolog.txt &
nohup ./post/post_service 127.0.0.1 2001 > post.txt &