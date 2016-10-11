/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_automatak_dnp3_impl_ChannelImpl */

#ifndef _Included_com_automatak_dnp3_impl_ChannelImpl
#define _Included_com_automatak_dnp3_impl_ChannelImpl
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_automatak_dnp3_impl_ChannelImpl
 * Method:    shutdown_native
 * Signature: (JZ)V
 */
JNIEXPORT void JNICALL Java_com_automatak_dnp3_impl_ChannelImpl_shutdown_1native
  (JNIEnv *, jobject, jlong, jboolean);

/*
 * Class:     com_automatak_dnp3_impl_ChannelImpl
 * Method:    get_native_master
 * Signature: (JLjava/lang/String;Lcom/automatak/dnp3/SOEHandler;Lcom/automatak/dnp3/MasterApplication;Lcom/automatak/dnp3/MasterStackConfig;)J
 */
JNIEXPORT jlong JNICALL Java_com_automatak_dnp3_impl_ChannelImpl_get_1native_1master
  (JNIEnv *, jobject, jlong, jstring, jobject, jobject, jobject);

/*
 * Class:     com_automatak_dnp3_impl_ChannelImpl
 * Method:    get_native_outstation
 * Signature: (JLjava/lang/String;Lcom/automatak/dnp3/CommandHandler;Lcom/automatak/dnp3/OutstationApplication;Lcom/automatak/dnp3/OutstationStackConfig;)J
 */
JNIEXPORT jlong JNICALL Java_com_automatak_dnp3_impl_ChannelImpl_get_1native_1outstation
  (JNIEnv *, jobject, jlong, jstring, jobject, jobject, jobject);

#ifdef __cplusplus
}
#endif
#endif
