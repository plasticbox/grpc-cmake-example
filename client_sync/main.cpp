#include <iostream>
#include <memory>

#include <grpc/support/log.h>
#include <grpcpp/grpcpp.h>

#include "proto/test.pb.h"
#include "proto/test.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::ClientAsyncResponseReader;
using grpc::CompletionQueue;
using grpc::Status;
using test::Wire;

class WireClient {
public:
    explicit WireClient(std::shared_ptr<grpc::Channel> channel)
        : stub_(Wire::NewStub(channel)) { }

    std::string Hello(const std::string& msg) {
        test::Req req;
        req.set_msg("test");

        ClientContext context;
        CompletionQueue cq;
        Status status;

        auto rpc(stub_->PrepareAsyncHello(&context, req, &cq));
        rpc->StartCall();

        test::Ack ack;
        rpc->Finish(&ack, &status, (void*)1);

        return "";
    }
private:
    std::unique_ptr<Wire::Stub> stub_;
};

int main() {

    std::cout << "hello, world" << std::endl;

    test::Req req;
    req.set_msg("test");

    return 0;
}
