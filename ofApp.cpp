#include "ofApp.h"
#include "ofMain.h"

//--------------------------------------------------------------
void ofApp::setup(){
	// listen on the given port
	cout << "listening for osc messages on port " << PORT << "\n";
	receiver.setup(PORT);

	
	ofBackground(ofRandom(20,80), ofRandom(20,80), ofRandom(130,200));
    //countTest=winNum;

    
   // this->image.loadImage("mine.jpeg");
    
    this->screen_width = 2560;
    this->screen_height = 1600;
    this->window_width = ofGetWindowWidth();
    this->window_height = ofGetWindowHeight();
    this->noise_seed_x = ofRandom(100);
    this->noise_seed_y = ofRandom(100);
    this->getWord=int(ofRandom(0,pool.size()));
   

    
    settings2.setSize(200, 200);
    settings2.resizable = false;

    
    
    font1.load("font1.TTF", 20);
    messages.push_back("start");

    //winNum+=1;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    speed=ofMap(ofGetElapsedTimeMillis(),0,300000,0.001,0.0012,true);
    windowSize=ofMap(ofGetElapsedTimeMillis(),0,30000,25,200,true);


    
    this->position.x = ofMap(ofNoise(this->noise_seed_x + ofGetFrameNum() * speed), 0, 1, this->screen_width * -0.3, this->screen_width * 0.8) - this->window_width * 0.5;
     this->position.y = ofMap(ofNoise(this->noise_seed_y + ofGetFrameNum() * speed), 0, 1, this->screen_height * -0.3, this->screen_height * 0.8) - this->window_height * 0.5;
      
    ofSetWindowPosition(this->position.x, this->position.y);
  

    
    
    if(receiver.hasWaitingMessages()){
        // get the next message
        ofxOscMessage m;
        receiver.getNextMessage(m);
         winNum+=1;
        
        
        // check for mouse moved message
        if(m.getAddress() == "/test"){
            
            
            //settings2.setSize(windowSize*ofRandom(0.8,1.8), windowSize*ofRandom(0.8,1.8));
            settings2.setSize(windowSize, windowSize);
            shared_ptr<ofAppBaseWindow> window = ofCreateWindow(settings2);
            shared_ptr<ofApp> window_app(new ofApp);
            ofRunApp(window, window_app);
            
            this->myString=m.getArgAsString(0);
            
            //pop new window when receive osc message
            
            
            
            //settings2.se
            
            //            this->count=winNum;
            //
            //
            //            cout<<this->myString<<endl;
            
            

            
//            cout<<"time:"<<endl;
//            cout<<<<endl;
        }
        
        if(m.getAddress() == "/index"){
            this->count=m.getArgAsInt(0);
            
             updateWindow=true;
           
            
        }
        

        
    }
    
   

    
}


//--------------------------------------------------------------
void ofApp::draw(){
    
    //Target: Pop a new window showing the recrived message
    //so different window show different message
    
        //the number pop here is pretty weird
        //ofDrawBitmapString(num, 20, 100);

      // int num=this->count-1;
   // string num=ofToString(this->count);
   // cout<<"final count is :"<<endl;
    //cout<<num<<endl;
    
    //if(messages.size()>0){
    
    if(updateWindow==true){
        messages.push_back(this->myString);
        winNum+=1;
        this->count=winNum/3;
        
        
        cout<<"count is:"<<endl;
        cout<<this->count<<endl;
        
        
        
        string temp=messages[this->count];
        
        cout<<"message is:"<<endl;
        cout<<temp<<endl;

        thisText=temp;

       
        
        
        updateWindow=false;
        
    }
    
    
    ofPushMatrix();
    
    //ofSetColor(255);
      font1.drawString(pool[getWord], ofGetWidth()*0.2, ofGetHeight()/2);
    //ofDrawCircle(50, 50, 20);
    
    // cout<<"check count :"<<endl;
    // cout<<this->count<<endl;
    //string num=ofToString(this->count);
    
    //font1.drawString(num, 20, 100);
    
    // font1.drawString(messages[this->count], 20, 100);
    //        cout<<"size of messages :"<<endl;
    //        cout<<messages.size()<<endl;
    ofPopMatrix();
    
    
      }
