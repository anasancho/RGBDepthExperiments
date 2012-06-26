/**
 * Example - Scene With Timeline
 * This example shows how to create a basic RGB+D scene
 * with a timeline to scrub through the video.
 *
 * It requires ofxGameCamera https://github.com/Flightphase/ofxGameCamera 
 * and ofxTimeline https://github.com/Flightphase/ofxTimeline in addition to ofxRGBDepth
 *
 * James George 2012 
 * Released under the MIT License
 *
 * The RGBDToolkit has been developed with support from the STUDIO for Creative Inquiry and Eyebeam
 */

#pragma once

#include "ofMain.h"
#include "ofxXmlSettings.h"
#include "ofxGameCamera.h"
#include "ofxRGBDPlayer.h"
#include "ofxRGBDMeshBuilder.h"
#include "ofxGui.h"
#include "ofxDelaunay.h"

class testApp : public ofBaseApp{
  public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    void exit();
    
    ofxRGBDPlayer player;
    ofxRGBDMeshBuilder meshBuilder;
    ofxGameCamera cam;
    
    ofxPanel gui;
    ofxFloatSlider xshift;
    ofxFloatSlider yshift;
    ofxFloatSlider farClip;

    ofxIntSlider maxFeatures;
    ofxFloatSlider featureQuality;
	ofxFloatSlider minDistance;
    ofxToggle renderMode;
    ofxFloatSlider lightX;
    ofxFloatSlider lightY;
    ofxFloatSlider lightZ;
    
    ofRectangle roi;
    ofFbo renderFBO;
    ofFbo previewFBO;
    
    ofMesh triangulatedMesh;
    ofMesh latticeMesh;
    
    vector<cv::Point2f> featurePoints;
    vector<ofVec3f> faceNormals;	
    vector<ofVec3f> faceCenters;
	vector<ofVec3f> innerPoints;
	vector<ofVec3f> backPoints;
    vector<ofVec3f> backInnerPoints;
    
    
    ofxButton loadNew;
    ofxDelaunay triangulate;

    ofRectangle meshRect;
    ofRectangle triangulatedRect;
    ofRectangle videoRect;
    void calculateRects();
    void createTriangulation();
    
    bool loadNewScene();
    bool loadDefaultScene();
    bool loadScene(string takeDirectory);
    int renderedVidoeFrame;
};
