//
// Created by qingw on 6/27/2025.
//

#ifndef WRAPPER_H
#define WRAPPER_H
#include <functional>
#include "winrt/windows.foundation.h"

struct IWrapper {

};

template <typename T>
struct Wrapper : IWrapper
{
    T value;
    Wrapper(T v) : value(v) {}
};

class JNIEnvWrapper
{
private:
    JavaVM* jvm;
public:
    JNIEnvWrapper(JNIEnv* env)
    {
        env->GetJavaVM(&jvm);
    }

protected:
    void context(const std::function<void(JNIEnv*)>& callback)
    {
        JNIEnv* env = nullptr;
        jint result = jvm->GetEnv((void**)&env, JNI_VERSION_1_6);

        if (result == JNI_EDETACHED) {
            if (jvm->AttachCurrentThread((void**)&env, nullptr) == 0) {
                callback(env);
                jvm->DetachCurrentThread();
                return;
            }
        } else if (result == JNI_OK) {
            callback(env);
            return;
        }

        std::cout << "Failed to get JNIEnv " << result << std::endl;
        throw std::runtime_error("Failed to get JNIEnv");
    }

};

using namespace  winrt::Windows::Foundation;

struct IOperationWrapper {
    virtual ~IOperationWrapper() = default;
    virtual jlong getResultAsJlong(JNIEnv* env) = 0;
};

template<typename T>
struct OperationWrapper : IOperationWrapper {
    IAsyncOperation<T> operation;

    OperationWrapper(IAsyncOperation<T> op) : operation(std::move(op)) {}

    jlong getResultAsJlong(JNIEnv* env) override {
        try {
            T result = operation.get();
            if (result == nullptr) {
                return 0;
            }
            auto* wrapper = new Wrapper<T>(result);
            return reinterpret_cast<jlong>(wrapper);
        } catch (const winrt::hresult_error& ex) {
            env->ThrowNew(env->FindClass("java/lang/RuntimeException"),
                        winrt::to_string(ex.message()).c_str());
            return 0;
        }
    }
};

#endif //WRAPPER_H
