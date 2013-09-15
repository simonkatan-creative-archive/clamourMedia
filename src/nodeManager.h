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
    void switchOffNode(string t_index);
    void beginShift(string t_index, float x, float y);
    void updateNodePosition(string t_index, float x, float y);
    void shiftNodePosition(string t_index, float x, float y);
    void updateOnlineClients(vector<string> v);
    vector<string> getOnlineClients();
    
    vector<string> getOnNodes();
    ofVec2f getNodePosition(string index);
    ofPtr<clamourNode> getNode(string index);
    
    void setNodeDrawType(vector<string> indexes, int dt);
    void setNodeDrawParam(vector<string> indexes, parameter p);
    void setNodeSoundType(vector<string> indexes, string st);
    void setNodeSoundParam(vector<string> indexes, parameter p);
    
    
    
    private:
    
    map< string, ofPtr<clamourNode> > mNodes;
    vector<string> onNodes;
    vector<string> mOnlineClients;
    
    soundDictionary mSoundDictionary;


};

#endif /* defined(__clamourMedia__nodeManager__) */
