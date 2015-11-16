#include <node.h>
#include <iostream>

#include "argon2_wrapper.h"

namespace argon2 {
    using v8::Exception;
    using v8::FunctionCallbackInfo;
    using v8::Isolate;
    using v8::Local;
    using v8::Number;
    using v8::Object;
    using v8::String;
    using v8::Value;

    void Hash(const FunctionCallbackInfo<Value> &args) {
        Isolate *isolate = args.GetIsolate();

        if (args.Length() != 1) {
            isolate->ThrowException(Exception::TypeError(
                    String::NewFromUtf8(isolate, "Wrong number of arguments")));
            return;
        }

        if (!args[0]->IsString()) {
            isolate->ThrowException(Exception::TypeError(
                    String::NewFromUtf8(isolate, "First argument should be string")));
            return;
        }

        std::string args0(*v8::String::Utf8Value(args[0]->ToString()));

        // Just testing:
        std::cout << "args0 = " << args0 << std::endl;
        argon2_wrapper::hash_string(args0.c_str());

        // Make the compiler happy:
        args.GetReturnValue().Set(Number::New(isolate, 5));
    }

    void Init(Local<Object> exports) {
        NODE_SET_METHOD(exports, "hash", Hash);
    }

    NODE_MODULE(addon, Init)
}
