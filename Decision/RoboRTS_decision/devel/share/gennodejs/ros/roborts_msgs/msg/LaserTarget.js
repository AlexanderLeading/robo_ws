// Auto-generated. Do not edit!

// (in-package roborts_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let FVector = require('./FVector.js');

//-----------------------------------------------------------

class LaserTarget {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.num_target = null;
      this.num_points = null;
      this.pose = null;
      this.confidence = null;
    }
    else {
      if (initObj.hasOwnProperty('num_target')) {
        this.num_target = initObj.num_target
      }
      else {
        this.num_target = 0;
      }
      if (initObj.hasOwnProperty('num_points')) {
        this.num_points = initObj.num_points
      }
      else {
        this.num_points = [];
      }
      if (initObj.hasOwnProperty('pose')) {
        this.pose = initObj.pose
      }
      else {
        this.pose = [];
      }
      if (initObj.hasOwnProperty('confidence')) {
        this.confidence = initObj.confidence
      }
      else {
        this.confidence = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type LaserTarget
    // Serialize message field [num_target]
    bufferOffset = _serializer.uint8(obj.num_target, buffer, bufferOffset);
    // Serialize message field [num_points]
    bufferOffset = _arraySerializer.uint8(obj.num_points, buffer, bufferOffset, null);
    // Serialize message field [pose]
    // Serialize the length for message field [pose]
    bufferOffset = _serializer.uint32(obj.pose.length, buffer, bufferOffset);
    obj.pose.forEach((val) => {
      bufferOffset = FVector.serialize(val, buffer, bufferOffset);
    });
    // Serialize message field [confidence]
    bufferOffset = _arraySerializer.float32(obj.confidence, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type LaserTarget
    let len;
    let data = new LaserTarget(null);
    // Deserialize message field [num_target]
    data.num_target = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [num_points]
    data.num_points = _arrayDeserializer.uint8(buffer, bufferOffset, null)
    // Deserialize message field [pose]
    // Deserialize array length for message field [pose]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.pose = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.pose[i] = FVector.deserialize(buffer, bufferOffset)
    }
    // Deserialize message field [confidence]
    data.confidence = _arrayDeserializer.float32(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.num_points.length;
    object.pose.forEach((val) => {
      length += FVector.getMessageSize(val);
    });
    length += 4 * object.confidence.length;
    return length + 13;
  }

  static datatype() {
    // Returns string type for a message object
    return 'roborts_msgs/LaserTarget';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'b7a891f119d989835596adf70e8ef67b';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    uint8 num_target
    uint8[] num_points
    FVector[] pose
    float32[] confidence
    
    ================================================================================
    MSG: roborts_msgs/FVector
    float32[] vector
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new LaserTarget(null);
    if (msg.num_target !== undefined) {
      resolved.num_target = msg.num_target;
    }
    else {
      resolved.num_target = 0
    }

    if (msg.num_points !== undefined) {
      resolved.num_points = msg.num_points;
    }
    else {
      resolved.num_points = []
    }

    if (msg.pose !== undefined) {
      resolved.pose = new Array(msg.pose.length);
      for (let i = 0; i < resolved.pose.length; ++i) {
        resolved.pose[i] = FVector.Resolve(msg.pose[i]);
      }
    }
    else {
      resolved.pose = []
    }

    if (msg.confidence !== undefined) {
      resolved.confidence = msg.confidence;
    }
    else {
      resolved.confidence = []
    }

    return resolved;
    }
};

module.exports = LaserTarget;
