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

class BallCollision {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.collision_time = null;
      this.collision_1 = null;
      this.collision_2 = null;
      this.x = null;
      this.y = null;
      this.z = null;
    }
    else {
      if (initObj.hasOwnProperty('collision_time')) {
        this.collision_time = initObj.collision_time
      }
      else {
        this.collision_time = 0.0;
      }
      if (initObj.hasOwnProperty('collision_1')) {
        this.collision_1 = initObj.collision_1
      }
      else {
        this.collision_1 = '';
      }
      if (initObj.hasOwnProperty('collision_2')) {
        this.collision_2 = initObj.collision_2
      }
      else {
        this.collision_2 = '';
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
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type BallCollision
    // Serialize message field [collision_time]
    bufferOffset = _serializer.float64(obj.collision_time, buffer, bufferOffset);
    // Serialize message field [collision_1]
    bufferOffset = _serializer.string(obj.collision_1, buffer, bufferOffset);
    // Serialize message field [collision_2]
    bufferOffset = _serializer.string(obj.collision_2, buffer, bufferOffset);
    // Serialize message field [x]
    bufferOffset = _serializer.float32(obj.x, buffer, bufferOffset);
    // Serialize message field [y]
    bufferOffset = _serializer.float32(obj.y, buffer, bufferOffset);
    // Serialize message field [z]
    bufferOffset = _serializer.float32(obj.z, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type BallCollision
    let len;
    let data = new BallCollision(null);
    // Deserialize message field [collision_time]
    data.collision_time = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [collision_1]
    data.collision_1 = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [collision_2]
    data.collision_2 = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [x]
    data.x = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [y]
    data.y = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [z]
    data.z = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.collision_1.length;
    length += object.collision_2.length;
    return length + 28;
  }

  static datatype() {
    // Returns string type for a message object
    return 'roborts_msgs/BallCollision';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'b3495fecab5c6286c1b0aa9239dbe76b';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64 collision_time
    string collision_1
    string collision_2
    float32 x
    float32 y
    float32 z
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new BallCollision(null);
    if (msg.collision_time !== undefined) {
      resolved.collision_time = msg.collision_time;
    }
    else {
      resolved.collision_time = 0.0
    }

    if (msg.collision_1 !== undefined) {
      resolved.collision_1 = msg.collision_1;
    }
    else {
      resolved.collision_1 = ''
    }

    if (msg.collision_2 !== undefined) {
      resolved.collision_2 = msg.collision_2;
    }
    else {
      resolved.collision_2 = ''
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

    return resolved;
    }
};

module.exports = BallCollision;
