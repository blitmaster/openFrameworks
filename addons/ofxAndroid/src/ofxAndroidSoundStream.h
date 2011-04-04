#pragma once

#include "ofConstants.h"
#include "ofBaseSoundStream.h"
#include <jni.h>

class ofxAndroidSoundStream : public ofBaseSoundStream{
	public:
		ofxAndroidSoundStream();
		~ofxAndroidSoundStream();
		
		void listDevices();
		void setDeviceID(int deviceID);

		void setInput(ofBaseSoundInput * soundInput);
		void setOutput(ofBaseSoundOutput * soundOutput);
		bool setup(int outChannels, int inChannels, int sampleRate, int bufferSize, int nBuffers);
		bool setup(ofBaseApp * app, int outChannels, int inChannels, int sampleRate, int bufferSize, int nBuffers);
		
		void start();
		void stop();
		void close();
		
		long unsigned long getTickCount();		
				
		int getNumInputChannels();
		int getNumOutputChannels();

		int androidInputAudioCallback(JNIEnv*  env, jobject  thiz,jshortArray array, jint numChannels, jint bufferSize);
		int androidOutputAudioCallback(JNIEnv*  env, jobject  thiz,jshortArray array, jint numChannels, jint bufferSize);
		
	private:
		long unsigned long	tickCount;
		int					sampleRate;
		ofBaseSoundInput *  soundInputPtr;
		ofBaseSoundOutput * soundOutputPtr;
		

		short * out_buffer, * in_buffer;
		float * out_float_buffer, * in_float_buffer;
		int outBufferSize, outChannels, inBufferSize, inChannels;
		int  requestedBufferSize;
		int  totalOutRequestedBufferSize;
		int  totalInRequestedBufferSize;
		jshortArray jInArray, jOutArray;


		friend void ofxAndroidSoundStreamPause();
		void pause();
};

