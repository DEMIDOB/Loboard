//
//  Device.hpp
//  Loboard
//
//  Created by Dan Demidov on 03.11.22.
//

#ifndef Device_hpp
#define Device_hpp

#include <string>

#include "../LBVector.hpp"

#define DEVICE_ON  1
#define DEVICE_OFF 0

#define p_DW Wire*

//#include "Wire.hpp"
#include "../Logger.hpp"

typedef bool DeviceState;
class Wire;

class Device {
public:
    Device();
    Device(uint8_t id, uint8_t inputsCount);
    ~Device();
    
    friend class DirectionedWire;
    
    void         AssignID(uint8_t id);
    
    void         Move(LBVector to);
    virtual void Update();
    void         PropagateState();
    
    bool         IsBlocked();
    uint8_t      GetID();
    
    p_DW         GetOutput();
    
    // Inputs
    uint8_t      GetInputsCount();
    bool         DoesInputExist(uint8_t inputIdx);
    bool         IsInputWired(uint8_t inputIdx);
    bool         IsOutputWired();
//    bool         SetInput(uint8_t inputIdx, Device* device);
    bool         AllInputsWired();
    
    LBVector     GetPosition();
    DeviceState  GetState();
    
    std::string  GetName();
    
protected:
    void         setState(DeviceState);
    void         toggleState();
    void         block(bool req = true);
    void         unblock(bool req = true);
    
    Device*      getInputDevice(uint8_t inputIdx);
    
    void         setName(std::string);

private:
    void         initEmpty();
    
    uint8_t id = 0;
    std::string name;
    
    uint8_t inputsCount = 0;
    Wire** inputs;
    
    LBVector boxSize;
    LBVector position;
    
    DeviceState blocked;
    DeviceState state;
    
    Wire* output;
};

#endif /* Device_hpp */
