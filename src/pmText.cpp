#include "pmText.h"


pmText::pmText(){
}

void pmText::setup(){
    myFont.load("Inconsolata-Regular.ttf", 40);
    stringWidth = 0;
    lineCount = 0;
    myString = "";
    lines = ofSplitString(ofBufferFromFile("title.txt").getText(), "\n");   
    fadeTime = 4.0;
    duration = 1.0;
    white = ofFloatColor::white;
    black = ofFloatColor::black;
    elapsedTime = ofGetElapsedTimef();
    t0 = elapsedTime + 3.0;
    t1 = t0 + fadeTime;
    t2 = t1 + duration;
    t3 = t2 + fadeTime;
}

void pmText::update(){
    float fade1 = ofMap(elapsedTime, t0, t1, 0.0, 1.0);
    float fade2 = ofMap(elapsedTime, t2, t3, 0.0, 1.0);
    elapsedTime = ofGetElapsedTimef();
    myString = lines[lineCount];
    stringWidth = myFont.stringWidth(myString);

    if(lineCount < lines.size() - 1){
        if (elapsedTime < t0) {
            textColor = black;
        } else if (elapsedTime < t1) {
            textColor = black.getLerped(white, fade1);
        } else if (elapsedTime < t2){
            textColor = white;
        } else if (elapsedTime < t3){
            textColor = white.getLerped(black, fade2);
        } else {
            t0 = elapsedTime;
            t1 = t0 + fadeTime;
            t2 = t1 + duration;
            t3 = t2 + fadeTime;
            lineCount++;
        }
    } 
}

void pmText::draw(){
    ofEnableAlphaBlending();
    ofBackground(0);
    ofSetColor(textColor);
    ofPushMatrix();
    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
    for(int i=0; i<4; i++){
        myFont.drawString(
                myString, stringWidth * -0.5, ofGetHeight() * 0.4
                );
        ofRotateDeg(-90);
    };
    ofPopMatrix();
    // frameRateString = ofToString(ofGetFrameRate());
    // myFont.drawString(frameRateString, 100, 100);
}
