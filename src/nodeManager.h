//
//  nodeManager.h
//  clamourMedia
//
//  Created by Simon Katan on 06/09/2013.
//
//

#ifndef __clamourMedia__nodeManager__
#define __clamourMedia__nodeManager__

#include "ofMain.h"
#include "clamourNode.h"

class nodeManager{

    public:

    nodeManager();
    nodeManager(vector<string> indexes);

    void resetNodes();
    void updateNodes();

    void switchOnNode(string t_index);
    void switchOnNode(string t_index, float x, float y);

    void switchOffAllNodes();
    void switchOffNode(string t_index);
    void switchOffNodes(vector<string> v);

    void wakeupNode(string t_index);

    void beginShift(string t_index, float x, float y);
    void updateNodePosition(string t_index, float x, float y);
    void shiftNodePosition(string t_index, float x, float y);

    map<string, ofPtr<clamourNode> > getNodes();
    ofVec2f getNodePosition(string index, bool isRel);
    ofPtr<clamourNode> getNode(string index);

    void distributeNodes(vector<string> clients, string pattern, map<string, float> params, bool dimp, bool posp);

    void setNodeAttSecs(vector<string> indexes, float att);
    void setNodeDecSecs(vector<string> indexes, float dec);

    //add parameter versions for randomisation later

    void setNodeDrawType(vector<string> indexes, string dt);
    void setNodeDrawParam(vector<string> indexes, parameter p);
    void setNodeSoundType(vector<string> indexes, string st);
    void setNodeSoundParam(vector<string> indexes, parameter p);


    private:

    map< string, ofPtr<clamourNode> > mNodes;


};

#endif /* defined(__clamourMedia__nodeManager__) */
