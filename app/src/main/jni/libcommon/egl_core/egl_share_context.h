#ifndef ANDROID_EGL_SHARE_CONTEXT_H_
#define ANDROID_EGL_SHARE_CONTEXT_H_

#include "egl_core.h"
#include "../../../../../../../../Library/Android/sdk/ndk/19.2.5345600/toolchains/llvm/prebuilt/darwin-x86_64/sysroot/usr/include/EGL/egl.h"
#include "../../../../../../../../Library/Android/sdk/ndk/19.2.5345600/toolchains/llvm/prebuilt/darwin-x86_64/sysroot/usr/include/EGL/eglplatform.h"

class EglShareContext {
public:
	~EglShareContext() {
	}
	static EGLContext getSharedContext() {
		if (instance_->sharedDisplay == EGL_NO_DISPLAY){
			instance_->init();
		}
		return instance_->sharedContext;
	}
protected:
	EglShareContext();
	void init();


private:
	static EglShareContext* instance_;
	EGLContext sharedContext;
	EGLDisplay sharedDisplay;
};

#endif
