// Auto-generated. Do not edit!

// (in-package roborts_msgs.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------


//-----------------------------------------------------------

class ShootCmdRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.mode = null;
      this.number = null;
      this.shoot_freq = null;
    }
    else {
      if (initObj.hasOwnProperty('mode')) {
        this.mode = initObj.mode
      }
      else {
        this.mode = 0;
      }
      if (initObj.hasOwnProperty('number')) {
        this.number = initObj.number
      }
      else {
        this.number = 0;
      }
      if (initObj.hasOwnProperty('shoot_freq')) {
        this.shoot_freq = initObj.shoot_freq
      }
      else {
        this.shoot_freq = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ShootCmdRequest
    // Serialize message field [mode]
    bufferOffset = _serializer.uint8(obj.mode, buffer, bufferOffset);
    // Serialize message field [number]
    bufferOffset = _serializer.uint8(obj.number, buffer, bufferOffset);
    // Serialize message field [shoot_freq]
    bufferOffset = _serializer.uint8(obj.shoot_freq, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ShootCmdRequest
    let len;
    let data = new ShootCmdRequest(null);
    // Deserialize message field [mode]
    data.mode = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [number]
    data.number = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [shoot_freq]
    data.shoot_freq = _deserializer.uint8(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 3;
  }

  static datatype() {
    // Returns string type for a service object
    return 'roborts_msgs/ShootCmdRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '8a6fbabf4a81c5455c2d4486632e499e';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    uint8 mode
    uint8 number
    uint8 shoot_freq
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ShootCmdRequest(null);
    if (msg.mode !== undefined) {
      resolved.mode = msg.mode;
    }
    else {
      resolved.mode = 0
    }

    if (msg.number !== undefined) {
      resolved.number = msg.number;
    }
    else {
      resolved.number = 0
    }

    if (msg.shoot_freq !== undefined) {
      resolved.shoot_freq = msg.shoot_freq;
    }
    else {
      resolved.shoot_freq = 0
    }

    return resolved;
    }
};

class ShootCmdResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.received = null;
    }
    else {
      if (initObj.hasOwnProperty('received')) {
        this.received = initObj.received
      }
      else {
        this.received = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ShootCmdResponse
    // Serialize message field [received]
    bufferOffset = _serializer.bool(obj.received, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ShootCmdResponse
    let len;
    let data = new ShootCmdResponse(null);
    // Deserialize message field [received]
    data.received = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 1;
  }

  static datatype() {
    // Returns string type for a service object
    return 'roborts_msgs/ShootCmdResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'dd4152e077925db952c78baadb1e48b7';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool received
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ShootCmdResponse(null);
    if (msg.received !== undefined) {
      resolved.received = msg.received;
    }
    else {
      resolved.received = false
    }

    return resolved;
    }
};

module.exports = {
  Request: ShootCmdRequest,
  Response: ShootCmdResponse,
  md5sum() { return '0cea41595e9611589408ddc63a4bf8c3'; },
  datatype() { return 'roborts_msgs/ShootCmd'; }
};
