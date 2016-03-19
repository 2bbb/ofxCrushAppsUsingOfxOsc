//
//  ofxCrushAppsUsingOfxOscReceiver.h
//
//  Created by ISHII 2bit on 2016/03/18.
//
//

#ifndef ofxCrushAppsUsingOfxOscReceiver_h
#define ofxCrushAppsUsingOfxOscReceiver_h

#include "ofMain.h"
#include "ofxUDPManager.h"

class ofxCrushAppsUsingOfxOscReceiver {
    ofxUDPManager manager;
    std::string address;
    
    int portOffset() const {
        return (ofGetFrameNum() * 256) % 65536;
    }
public:
    ofxCrushAppsUsingOfxOscReceiver()
    : address("255.255.255.255")
    {
        ofAddListener(ofEvents().update, this, &ofxCrushAppsUsingOfxOscReceiver::update);
        manager.Create();
        manager.SetEnableBroadcast(true);
    }
    
    void setup(const std::string &address = "255.255.255.255") {
        this->address = address;
    }
    void update(ofEventArgs &) {
        int offset = portOffset();
        for(int i = 0; i < 256; i++) {
            if(manager.Connect(address.c_str(), offset + i)) {
                manager.SendAll("destroy you!", 13);
            } else {
                ofLogWarning() << "can't connect" << offset + i;
            }
        }
    }
};

#endif /* ofxCrushAppsUsingOfxOscReceiver_h */
