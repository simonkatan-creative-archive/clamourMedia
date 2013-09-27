#ifndef ZONE_H
#define ZONE_H


#include "clamourNode.h"
#include "baseZode.h"

struct zoneRule{

    zoneRule(){
        isEnabled = true;
    };

    string ruleType;
    bool isEnabled;

    int gtOccupants;
    int ltOccupants;

    vector<string> incDrawTypes;
    vector<string> excDrawTypes;

};

struct zoneEffect{

    //these relate to aspects which effect other nodes, zones, stages etc;
    string effectType;

    //closeOutZone, openOutZone, closeInZone, openInZone

    string trigType; //ON, OFF, ON_OFF

    vector<clamourNode> prevNodeStates; // easier just to store the whole node


};


class zone : public baseZode
{
public:
    zone();
    virtual ~zone();

    void addNode(ofPtr<clamourNode> p);
    void removeNode(ofPtr<clamourNode> p);

    //getters and setters

    map<string, ofPtr<clamourNode> > getCaptureNodes();

    void setShape_abs(ofVec2f p, float r); //a circle
    void setShape_abs(vector<ofVec2f> pps); //a poly
    void setShape_abs(ofRectangle r); //duh

    void setShape_rel(ofVec2f p, float r); //a circle
    void setShape_rel(vector<ofVec2f> pps); //a poly
    void setShape_rel(ofRectangle r); //duh

    void recalcAbsDims();

    string getShapeType();

    ofVec2f getPos_abs();
    float getRadius();

    vector<ofVec2f> getPoly_abs();
    ofRectangle getRect_abs();


    void setIsClosedOut(bool b);
    bool getIsClosedOut();

    void setIsClosedIn(bool b);
    bool getIsClosedIn();

    void setOnRule(zoneRule zr);
    zoneRule getOnRule();

    void setOffRule(zoneRule zr);
    zoneRule getOffRule();

    vector<ofPtr<zoneEffect> > getReactions();
    void addReaction(zoneEffect e);


private:


    //collision stuff
    bool isClosedOut, isClosedIn;
    ofVec2f pos_abs;
    ofVec2f pos_rel;
    float radius; //necessarily absolute

    string shapeType;
    vector <ofVec2f> polyPoints_abs;
    vector <ofVec2f> polyPoints_rel;
    ofRectangle rect_abs;
    ofRectangle rect_rel;

    //mechanics stuff
    map <string , ofPtr<clamourNode> > mCaptureNodes;

    zoneRule mOnRule;
    zoneRule mOffRule;

    vector<ofPtr<zoneEffect> > reactions;


};

#endif // ZONE_H
