#include "Util.h"

winrt::hstring JStringToHString(JNIEnv* env, jstring javaString)
{
    if (!javaString) {
        return winrt::hstring();
    }
    const char* utfChars = env->GetStringUTFChars(javaString, nullptr);
    if (!utfChars) {
        return winrt::hstring();
    }
    winrt::hstring result = winrt::to_hstring(utfChars);
    env->ReleaseStringUTFChars(javaString, utfChars);
    return result;
}

jstring HStringToJString(JNIEnv* env, winrt::hstring hString)
{
    return env->NewStringUTF(to_string(hString).c_str());
}