#include <jni.h>
#include <string>
#include "medium.h"

extern "C" JNIEXPORT jstring JNICALL
Java_com_whh_avps_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT void JNICALL
Java_com_whh_avps_MainActivity_printfVersion(JNIEnv *env, jobject thiz) {
    // TODO: implement printfVersion()
    PrintfVersion();
}