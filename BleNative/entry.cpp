#include <iostream>
#include "jni.h"

JNIEXPORT jint JNICALL
        JNI_OnLoad(JavaVM *vm, void *reserved) {
    std::cout << "JNI_OnLoad" << std::endl;
    return JNI_VERSION_1_6;
}