#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){


    
    
    ofGLFWWindowSettings settings;
    settings.visible=false;
    settings.setSize(200, 200);
    settings.resizable = false;
    

    shared_ptr<ofAppBaseWindow> window = ofCreateWindow(settings);
    shared_ptr<ofApp> window_app(new ofApp);
    ofRunApp(window, window_app);


    
    ofRunMainLoop();

}
