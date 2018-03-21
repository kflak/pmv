#include "pmv.h"

//--------------------------------------------------------------
void pmv::setup(){
    receive.setup(PORT);
    // text.setup();
    // flare.setup();
    perlinCircle.setup();
}

//--------------------------------------------------------------
void pmv::update(){
    while (receive.hasWaitingMessages()) {
        ofxOscMessage m;
        receive.getNextMessage(m);
        if(m.getAddress() == "/text") {
            bool arg = m.getArgAsBool(0);
            text.setup();
            textState = arg;
        };
        if(m.getAddress() == "/flare") {
            bool arg = m.getArgAsBool(0);
            flare.setup();
            flareState = arg;
        };
    };
    if(textState) text.update();
    if(flareState) flare.update();
    perlinCircle.update();
}

//--------------------------------------------------------------
void pmv::draw(){
    ofBackground(0);
    if(textState) text.draw();
    if(flareState) flare.draw();
    perlinCircle.draw();
}

//--------------------------------------------------------------
void pmv::keyPressed(int key){

}

//--------------------------------------------------------------
void pmv::keyReleased(int key){

}

//--------------------------------------------------------------
void pmv::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void pmv::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void pmv::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void pmv::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void pmv::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void pmv::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void pmv::windowResized(int w, int h){

}

//--------------------------------------------------------------
void pmv::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void pmv::dragEvent(ofDragInfo dragInfo){ 

}
