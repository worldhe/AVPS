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

extern "C"
JNIEXPORT void JNICALL
Java_com_whh_avps_MainActivity_printfInfo(JNIEnv *env, jobject thiz, jstring name) {
    // TODO: implement printfInfo()
//    char *rtn = NULL;
//    jclass clsstring  = env->FindClass("java/lang/String");
//    jstring strencode = env->NewStringUTF("GB2312");
//    jmethodID mid     =  env->GetMethodID(clsstring, "getBytes", "(Ljava/lang/String;)[B");
//    jbyteArray barr   = (jbyteArray)env->CallObjectMethod(name, mid, strencode);
//    jsize alen        = env->GetArrayLength(barr);
//    jbyte *ba         = env->GetByteArrayElements(barr,JNI_FALSE);
//    if(alen > 0)
//    {
//        rtn = (char*) malloc(alen+1);
//        memcpy(rtn, ba, alen);
//        rtn[alen] = 0;
//    }
//    env->ReleaseByteArrayElements(barr, ba,0);
//    std::string stemp(rtn);
//    PrintfInfo(rtn);
//    free(rtn);



    PrintfInfo();
}