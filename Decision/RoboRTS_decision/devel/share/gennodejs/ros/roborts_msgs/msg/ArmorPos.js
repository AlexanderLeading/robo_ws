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

class ArmorPos {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.is_valid = null;
      this.x = null;
      this.y = null;
      this.z = null;
      this.distance = null;
      this.pose_in_gimbal = null;
      this.vertex = null;
      this.motion_vec = null;
    }
    else {
      if (initObj.hasOwnProperty('is_valid')) {
        this.is_valid = initObj.is_valid
      }
      else {
        this.is_valid = false;
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
      if (initObj.hasOwnProperty('distance')) {
        this.distance = initObj.distance
      }
      else {
        this.distance = 0.0;
      }
      if (initObj.hasOwnProperty('pose_in_gimbal')) {
        this.pose_in_gimbal = initObj.pose_in_gimbal
      }
      else {
        this.pose_in_gimbal = [];
      }
      if (initObj.hasOwnProperty('vertex')) {
        this.vertex = initObj.vertex
      }
      else {
        this.vertex = [];
      }
      if (initObj.hasOwnProperty('motion_vec')) {
        this.motion_vec = initObj.motion_vec
      }
      else {
        this.motion_vec = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ArmorPos
    // Serialize message field [is_valid]
    bufferOffset = _serializer.bool(obj.is_valid, buffer, bufferOffset);
    // Serialize message field [x]
    bufferOffset = _serializer.float64(obj.x, buffer, bufferOffset);
    // Serialize message field [y]
    bufferOffset = _serializer.float64(obj.y, buffer, bufferOffset);
    // Serialize message field [z]
    bufferOffset = _serializer.float64(obj.z, buffer, bufferOffset);
    // Serialize message field [distance]
    bufferOffset = _serializer.float64(obj.distance, buffer, bufferOffset);
    // Serialize message field [pose_in_gimbal]
    bufferOffset = _arraySerializer.float64(obj.pose_in_gimbal, buffer, bufferOffset, null);
    // Serialize message field [vertex]
    bufferOffset = _arraySerializer.float64(obj.vertex, buffer, bufferOffset, null);
    // Serialize message field [motion_vec]
    bufferOffset = _arraySerializer.float64(obj.motion_vec, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ArmorPos
    let len;
    let data = new ArmorPos(null);
    // Deserialize message field [is_valid]
    data.is_valid = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [x]
    data.x = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [y]
    data.y = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [z]
    data.z = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [distance]
    data.distance = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [pose_in_gimbal]
    data.pose_in_gimbal = _arrayDeserializer.float64(buffer, bufferOffset, null)
    // Deserialize message field [vertex]
    data.vertex = _arrayDeserializer.float64(buffer, bufferOffset, null)
    // Deserialize message field [motion_vec]
    data.motion_vec = _arrayDeserializer.float64(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 8 * object.pose_in_gimbal.length;
    length += 8 * object.vertex.length;
    length += 8 * object.motion_vec.length;
    return length + 45;
  }

  static datatype() {
    // Returns string type for a message object
    return 'roborts_msgs/ArmorPos';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '7c1653860dd6778fef70d70be834958c';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool is_valid
    float64 x
    float64 y
    float64 z
    float64 distance
    float64[] pose_in_gimbal
    float64[] vertex
    float64[] motion_vec
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ArmorPos(null);
    if (msg.is_valid !== undefined) {
      resolved.is_valid = msg.is_valid;
    }
    else {
      resolved.is_valid = false
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

    if (msg.distance !== undefined) {
      resolved.distance = msg.distance;
    }
    else {
      resolved.distance = 0.0
    }

    if (msg.pose_in_gimbal !== undefined) {
      resolved.pose_in_gimbal = msg.pose_in_gimbal;
    }
    else {
      resolved.pose_in_gimbal = []
    }

    if (msg.vertex !== undefined) {
      resolved.vertex = msg.vertex;
    }
    else {
      resolved.vertex = []
    }

    if (msg.motion_vec !== undefined) {
      resolved.motion_vec = msg.motion_vec;
    }
    else {
      resolved.motion_vec = []
    }

    return resolved;
    }
};

module.exports = ArmorPos;
