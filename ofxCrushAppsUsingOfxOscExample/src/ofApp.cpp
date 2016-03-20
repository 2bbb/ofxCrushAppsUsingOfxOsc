#include "ofMain.h"
#include "ofxCrushAppsUsingOfxOscReceiver.h"

class ofApp : public ofBaseApp {
    ofxCrushAppsUsingOfxOscReceiver destroyer;
public:
    void setup() {
        ofBackground(0, 0, 0);
        ofSetColor(255, 255, 255);
    }
    
    void draw() {
        ofDrawBitmapString(ofToString(ofGetFrameNum()), 20, 20);
        ofDrawBitmapString(ofToString(ofGetFrameRate()), 20, 40);
    }
};

int main() {
    ofSetupOpenGL(100, 100, OF_WINDOW);
    ofRunApp(new ofApp);
}
