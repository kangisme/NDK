#include <jni.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <android/log.h>

//log定义

#define  LOG    "JNILOG" // 这个是自定义的LOG的TAG
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG,__VA_ARGS__) // 定义LOGD类型
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG,__VA_ARGS__) // 定义LOGI类型
#define  LOGW(...)  __android_log_print(ANDROID_LOG_WARN,LOG,__VA_ARGS__) // 定义LOGW类型
#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG,__VA_ARGS__) // 定义LOGE类型
#define LOGF(...)  __android_log_print(ANDROID_LOG_FATAL,LOG,__VA_ARGS__) // 定义LOGF类型

extern "C"
JNIEXPORT jstring JNICALL
Java_com_kang_ndk_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    int *p = NULL;
    *p = 100;
    return env->NewStringUTF(hello.c_str());
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_kang_ndk_MainActivity_myText(JNIEnv *env, jobject instance) {
    std::string hello = "Hello world from JNI";
    return env->NewStringUTF(hello.c_str());
}
extern "C"
JNIEXPORT void JNICALL
Java_com_kang_ndk_MainActivity_saveText(JNIEnv *env, jobject instance, jstring text_) {
    const char *filePath = env->GetStringUTFChars(text_, 0);
    FILE *file = fopen(filePath, "a");

    char date[] = "save text";
    int count = (int) fwrite(date, strlen(date), 1, file);
    if (file != NULL) {
        fclose(file);
    }
    env->ReleaseStringUTFChars(text_, filePath);
}
extern "C"
JNIEXPORT void JNICALL
Java_com_kang_ndk_MainActivity_operateArray(JNIEnv *env, jobject instance, jintArray array_) {
    //获取数据指针
    jint *array = env->GetIntArrayElements(array_, NULL);
    jint len = env->GetArrayLength(array_);
    for (int i = 0; i < len; ++i) {
        ++array[i];
    }

    //释放
    env->ReleaseIntArrayElements(array_, array, 0);
}