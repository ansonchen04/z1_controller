#ifndef CTRLCOMPONENTS_H
#define CTRLCOMPONENTS_H

#include <string>
#include <iostream>
#include "common/utilities/loop.h"
#include "message/arm_common.h"
#include "message/LowlevelCmd.h"
#include "message/LowlevelState.h"
#include "common/utilities/CSVTool.h"
#include "model/ArmModel.h"
#include "interface/IOUDP.h"
#include "interface/IOROS.h"
#include "control/armSDK.h"

using namespace std;

struct CtrlComponents{
public:
    CtrlComponents(int argc, char**argv);
    ~CtrlComponents();

    std::string armConfigPath;
    CmdPanel *cmdPanel;
    IOInterface *ioInter;
    ArmModel *armModel;
    CSVTool *stateCSV;

    SendCmd sendCmd; // cmd that receive from SDK 
    RecvState recvState;// state that send to SDK
    
    //config
    double dt;
    bool *running;
    Control ctrl;
    bool hasGripper;
    bool isCollisionOpen;
    double collisionTLimit;
    bool isPlot;
    int trajChoose = 1;
    size_t dogType = 1;//1:Aliengo 2:B1

    void geneObj();
    void writeData();
private:
    void inputProcess(int argc, char** argv);

    std::string ctrl_IP;
    uint ctrl_port;
    double _loadWeight;
};

#endif  // CTRLCOMPONENTS_H