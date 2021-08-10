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

class TargetInfo {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.is_valid = null;
      this.id = null;
      this.bbox = null;
      this.pose = null;
      this.optical_flow = null;
    }
    else {
      if (initObj.hasOwnProperty('is_valid')) {
        this.is_valid = initObj.is_valid
      }
      else {
        this.is_valid = false;
      }
      if (initObj.hasOwnProperty('id')) {
        this.id = initObj.id
      }
      else {
        this.id = 0;
      }
      if (initObj.hasOwnProperty('bbox')) {
        this.bbox = initObj.bbox
      }
      else {
        this.bbox = [];
      }
      if (initObj.hasOwnProperty('pose')) {
        this.pose = initObj.pose
      }
      else {
        this.pose = [];
      }
      if (initObj.hasOwnProperty('optical_flow')) {
        this.optical_flow = initObj.optical_flow
      }
      else {
        this.optical_flow = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type TargetInfo
    // Serialize message field [is_valid]
    bufferOffset = _serializer.bool(obj.is_valid, buffer, bufferOffset);
    // Serialize message field [id]
    bufferOffset = _serializer.uint8(obj.id, buffer, bufferOffset);
    // Serialize message field [bbox]
    bufferOffset = _arraySerializer.float32(obj.bbox, buffer, bufferOffset, null);
    // Serialize message field [pose]
    bufferOffset = _arraySerializer.float32(obj.pose, buffer, bufferOffset, null);
    // Serialize message field [optical_flow]
    bufferOffset = _arraySerializer.float32(obj.optical_flow, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type TargetInfo
    let len;
    let data = new TargetInfo(null);
    // Deserialize message field [is_valid]
    data.is_valid = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [id]
    data.id = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [bbox]
    data.bbox = _arrayDeserializer.float32(buffer, bufferOffset, null)
    // Deserialize message field [pose]
    data.pose = _arrayDeserializer.float32(buffer, bufferOffset, null)
    // Deserialize message field [optical_flow]
    data.optical_flow = _arrayDeserializer.float32(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 4 * object.bbox.length;
    length += 4 * object.pose.length;
    length += 4 * object.optical_flow.length;
    return length + 14;
  }

  static datatype() {
    // Returns string type for a message object
    return 'roborts_msgs/TargetInfo';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '332308c6498382ae0ac339a429da4973';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool is_valid
    uint8 id
    float32[] bbox
    float32[] pose
    float32[] optical_flow
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new TargetInfo(null);
    if (msg.is_valid !== undefined) {
      resolved.is_valid = msg.is_valid;
    }
    else {
      resolved.is_valid = false
    }

    if (msg.id !== undefined) {
      resolved.id = msg.id;
    }
    else {
      resolved.id = 0
    }

    if (msg.bbox !== undefined) {
      resolved.bbox = msg.bbox;
    }
    else {
      resolved.bbox = []
    }

    if (msg.pose !== undefined) {
      resolved.pose = msg.pose;
    }
    else {
      resolved.pose = []
    }

    if (msg.optical_flow !== undefined) {
      resolved.optical_flow = msg.optical_flow;
    }
    else {
      resolved.optical_flow = []
    }

    return resolved;
    }
};

module.exports = TargetInfo;
