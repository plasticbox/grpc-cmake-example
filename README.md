# grpc-cmake-example
## test environment
- m1 macbook pro

## install protobuf, grpc, openssl
```shell
brew install protobuf
brew install grpc
brew install openssl
```

## build and run client
```shell
cd client_async
cmake .
make
./client_async
```

## build and run server
```shell
cd server
cmake .
make
./server
```