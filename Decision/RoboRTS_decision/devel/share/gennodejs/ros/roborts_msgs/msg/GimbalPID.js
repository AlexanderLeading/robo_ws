// Auto-generated. Do not edit!

// (in-package roborts_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class GimbalPID {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.is_valid = null;
      this.yaw_mode = null;
      this.pitch_mode = null;
      this.x = null;
      this.y = null;
      this.z = null;
      this.undetected_count_ = null;
    }
    else {
      if (initObj.hasOwnProperty('is_valid')) {
        this.is_valid = initObj.is_valid
      }
      else {
        this.is_valid = false;
      }
      if (initObj.hasOwnProperty('yaw_mode')) {
        this.yaw_mode = initObj.yaw_mode
      }
      else {
        this.yaw_mode = false;
      }
      if (initObj.hasOwnProperty('pitch_mode')) {
        this.pitch_mode = initObj.pitch_mode
      }
      else {
        this.pitch_mode = false;
      }
      if (initObj.hasOwnProperty('x')) {
        this.x = initObj.x
      }
      else {
        this.x = 0.0;
      }
      if (initObj.hasOwnProperty('y')) {
        this.y = initObj.y
      }
      else {
        this.y = 0.0;
      }
      if (initObj.hasOwnProperty('z')) {
        this.z = initObj.z
      }
      else {
        this.z = 0.0;
      }
      if (initObj.hasOwnProperty('undetected_count_')) {
        this.undetected_count_ = initObj.undetected_count_
      }
      else {
        this.undetected_count_ = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type GimbalPID
    // Serialize message field [is_valid]
    bufferOffset = _serializer.bool(obj.is_valid, buffer, bufferOffset);
    // Serialize message field [yaw_mode]
    bufferOffset = _serializer.bool(obj.yaw_mode, buffer, bufferOffset);
    // Serialize message field [pitch_mode]
    bufferOffset = _serializer.bool(obj.pitch_mode, buffer, bufferOffset);
    // Serialize message field [x]
    bufferOffset = _serializer.float64(obj.x, buffer, bufferOffset);
    // Serialize message field [y]
    bufferOffset = _serializer.float64(obj.y, buffer, bufferOffset);
    // Serialize message field [z]
    bufferOffset = _serializer.float64(obj.z, buffer, bufferOffset);
    // Serialize message field [undetected_count_]
    bufferOffset = _serializer.int32(obj.undetected_count_, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type GimbalPID
    let len;
    let data = new GimbalPID(null);
    // Deserialize message field [is_valid]
    data.is_valid = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [yaw_mode]
    data.yaw_mode = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [pitch_mode]
    data.pitch_mode = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [x]
    data.x = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [y]
    data.y = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [z]
    data.z = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [undetected_count_]
    data.undetected_count_ = _deserializer.int32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 31;
  }

  static datatype() {
    // Returns string type for a message object
    return 'roborts_msgs/GimbalPID';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '47363277c60e8bf4c4fc3528d560ba62';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    #detection to gimbal control
    bool is_valid
    bool yaw_mode
    bool pitch_mode
    float64 x
    float64 y
    float64 z
    int32 undetected_count_
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new GimbalPID(null);
    if (msg.is_valid !== undefined) {
      resolved.is_valid = msg.is_valid;
    }
    else {
      resolved.is_valid = false
    }

    if (msg.yaw_mode !== undefined) {
      resolved.yaw_mode = msg.yaw_mode;
    }
    else {
      resolved.yaw_mode = false
    }

    if (msg.pitch_mode !== undefined) {
      resolved.pitch_mode = msg.pitch_mode;
    }
    else {
      resolved.pitch_mode = false
    }

    if (msg.x !== undefined) {
      resolved.x = msg.x;
    }
    else {
      resolved.x = 0.0
    }

    if (msg.y !== undefined) {
      resolved.y = msg.y;
    }
    else {
      resolved.y = 0.0
    }

    if (msg.z !== undefined) {
      resolved.z = msg.z;
    }
    else {
      resolved.z = 0.0
    }

    if (msg.undetected_count_ !== undefined) {
      resolved.undetected_count_ = msg.undetected_count_;
    }
    else {
      resolved.undetected_count_ = 0
    }

    return resolved;
    }
};

module.exports = GimbalPID;
