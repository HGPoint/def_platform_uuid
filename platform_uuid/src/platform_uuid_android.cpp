#if defined(DM_PLATFORM_ANDROID)

#include <dmsdk/dlib/android.h>

#include <dmsdk/sdk.h>

struct AndroidGetPlatformUUID
{
    jobject         m_PlatformUUIDJNI;
    jmethodID       m_GetUUID;
};


static AndroidGetPlatformUUID g_get_platform_uuid;

static void InitJNIMethods(JNIEnv* env, jclass cls)
{
    g_get_platform_uuid.m_GetUUID = env->GetMethodID(cls, "getUUID", "()Ljava/lang/String;");
}

void Initialize_Ext()
{
    dmAndroid::ThreadAttacher threadAttacher;
    JNIEnv* env = threadAttacher.GetEnv();
    jclass cls = dmAndroid::LoadClass(env, "com.hgpoint.PlatformUUID");
    InitJNIMethods(env, cls);
    jmethodID jni_constructor = env->GetMethodID(cls, "<init>", "()V");
    g_get_platform_uuid.m_PlatformUUIDJNI = env->NewGlobalRef(env->NewObject(cls, jni_constructor, threadAttacher.GetActivity()->clazz));
}

int GetPlatformUUID(lua_State* L)
{
    dmAndroid::ThreadAttacher threadAttacher;
    JNIEnv* env = threadAttacher.GetEnv();
    jstring jni_device_uuid = (jstring)env->CallObjectMethod(g_get_platform_uuid.m_PlatformUUIDJNI, g_get_platform_uuid.m_GetUUID);
    lua_pushstring(L, env->GetStringUTFChars(jni_device_uuid, 0));
    env->DeleteLocalRef(jni_device_uuid);
    return 1;
}

#endif