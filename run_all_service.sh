mkdir -p build
cd build
cmake ..
make

nohup ./echo/echo_service_tcp ./echo/echolog 2000 > echolog.txt &