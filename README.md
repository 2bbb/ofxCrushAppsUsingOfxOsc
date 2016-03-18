# ofxCrushAppsUsingOfxOsc

if you wanna be no.1 in exhibition everyone use openFrameworks!

## Dependencies

* ofxNetwork

## Target

artwork using ~oF0.9.3 and ofxOsc

## Notice

**PLEASE USE AT YOUR OWN RISK.**

## How to use

```
class ofApp : public ofBaseApp {
    ofxCrushAppsUsingOfxOsc destroyer;
public:
    void setup() {
        destroyer.setup("127.0.0.1");
    }
};
```

## Update History

### 2016/03/18 ver 0.01 release

* initial

## License

MIT License.

## Author

* ISHII 2bit [bufferRenaiss co., ltd.]
* ishii[at]buffer-renaiss.com
