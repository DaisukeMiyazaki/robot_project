// Auto-generated. Do not edit!

// (in-package arduino_pkg.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class Num {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.Control = null;
      this.Duration = null;
    }
    else {
      if (initObj.hasOwnProperty('Control')) {
        this.Control = initObj.Control
      }
      else {
        this.Control = 0;
      }
      if (initObj.hasOwnProperty('Duration')) {
        this.Duration = initObj.Duration
      }
      else {
        this.Duration = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Num
    // Serialize message field [Control]
    bufferOffset = _serializer.int16(obj.Control, buffer, bufferOffset);
    // Serialize message field [Duration]
    bufferOffset = _serializer.uint16(obj.Duration, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Num
    let len;
    let data = new Num(null);
    // Deserialize message field [Control]
    data.Control = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [Duration]
    data.Duration = _deserializer.uint16(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 4;
  }

  static datatype() {
    // Returns string type for a message object
    return 'arduino_pkg/Num';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '1a749a2ffb665f31b6ffb7a5a9db9bad';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int16 Control
    uint16 Duration 
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new Num(null);
    if (msg.Control !== undefined) {
      resolved.Control = msg.Control;
    }
    else {
      resolved.Control = 0
    }

    if (msg.Duration !== undefined) {
      resolved.Duration = msg.Duration;
    }
    else {
      resolved.Duration = 0
    }

    return resolved;
    }
};

module.exports = Num;
