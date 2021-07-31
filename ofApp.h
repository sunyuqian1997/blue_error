#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include "ofAppGLFWWindow.h"


#define PORT 12300
#define NUM_MSG_STRINGS 20

class ofApp : public ofBaseApp {
	public:

		void setup();
		void update();
		void draw();

		ofxOscReceiver receiver;
       		
        deque<string> messageBuffer;
    
        vector<string> pool= {"RNG"};
    
       
        string myString;
        float myTime;
   
    
       vector<string> messages;
       vector<int> index;

    
   // ofImage image;
    ofTrueTypeFont font1;
    
    int screen_width, screen_height;
    int window_width, window_height;
    float noise_seed_x, noise_seed_y;
    int getWord;
    ofPoint window_position;
    
    
    int winNum;
    int count;
    int countTest;
    int windowSize;
    
    bool updateWindow=false;
    
    float speed=0.001;

    string thisText;
    ofVec2f position;
    
    ofGLFWWindowSettings settings2;


};
