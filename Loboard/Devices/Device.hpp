//
//  Device.hpp
//  Loboard
//
//  Created by Dan Demidov on 03.11.22.
//

#ifndef Device_hpp
#define Device_hpp

#include <string>
#include <unordered_map>

#define DEVICE_ON  1
#define DEVICE_OFF 0

#include "../Logger.hpp"

typedef bool DeviceState;
typedef uint8_t DeviceID;

class DirectionalWire;

class Device {
public:
    Device();
    Device(DeviceID id, uint8_t inputsCount);
    ~Device();
    
    friend class DirectionalWire;

    void         AssignID(DeviceID id);
    
    virtual void Update();
    void         PropagateState();
    
    bool         IsBlocked() const { return !ready; }

    uint8_t      GetID() const { return id; }
    int          GetNextInputID() const;
    DeviceState  GetState() const { return state; }
    std::string  GetName() const { return name; }
    
    // Inputs
    uint8_t      GetInputsCount() const { return inputsCount; }
    bool         DoesInputExist(uint8_t inputIdx) const;
    bool         IsInputWired(uint8_t inputIdx);
    bool         AllInputsWired();

    // Outputs
    inline bool  IsAnyOutputWired() const { return !outputs.empty(); }
    inline bool  HasOutputToDevice(const Device* device) const { return outputs.count(device->id) == 1; }

    explicit operator std::basic_string<char>() const;

protected:
    void         setName(std::string);
    void         setState(DeviceState);
    void         block(bool req = true);
    void         unblock(bool req = true);

    // Inputs
    Device*      getInputDevice(uint8_t inputIdx);
    void         unwireInputAtPort(uint8_t inputPort);

    // Outputs
    void         addOutput(DirectionalWire* newOutputWire);
    void         deleteOutput(DeviceID destID);
private:
    void         initEmpty();
    
    DeviceID id = 0;
    std::string name;
    
    uint8_t inputsCount = 0;
    DirectionalWire** inputs;
    
    DeviceState ready;
    DeviceState state;
    
    std::unordered_map<DeviceID, DirectionalWire*> outputs;
};

#endif /* Device_hpp */
