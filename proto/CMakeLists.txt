include(FindProtobuf)
find_package(Protobuf REQUIRED)
message(STATUS "Using protobuf ${Protobuf_VERSION}")

find_package(gRPC REQUIRED)
message(STATUS "Using grpc ${gRPC_VERSION}")

set(PROTO_FILES
    test.proto)

add_library(proto ${PROTO_FILES})
target_link_libraries(proto
    PUBLIC
        protobuf::libprotobuf
        gRPC::grpc
        gRPC::grpc++
)

target_include_directories(proto PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${PROTO_SRC} ${PROTO_HDRS})
get_target_property(grpc_cpp_plugin_location gRPC::grpc_cpp_plugin LOCATION)
protobuf_generate(TARGET proto LANGUAGE cpp)
protobuf_generate(TARGET proto LANGUAGE grpc GENERATE_EXTENSIONS .grpc.pb.h .grpc.pb.cc PLUGIN "protoc-gen-grpc=${grpc_cpp_plugin_location}")