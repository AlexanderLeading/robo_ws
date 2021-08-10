// Auto-generated. Do not edit!

// (in-package roborts_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let Target = require('./Target.js');

//-----------------------------------------------------------

class FusionTarget {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.num_id_target = null;
      this.num_no_id_target = null;
      this.id_targets = null;
      this.no_id_targets = null;
    }
    else {
      if (initObj.hasOwnProperty('num_id_target')) {
        this.num_id_target = initObj.num_id_target
      }
      else {
        this.num_id_target = 0;
      }
      if (initObj.hasOwnProperty('num_no_id_target')) {
        this.num_no_id_target = initObj.num_no_id_target
      }
      else {
        this.num_no_id_target = 0;
      }
      if (initObj.hasOwnProperty('id_targets')) {
        this.id_targets = initObj.id_targets
      }
      else {
        this.id_targets = [];
      }
      if (initObj.hasOwnProperty('no_id_targets')) {
        this.no_id_targets = initObj.no_id_targets
      }
      else {
        this.no_id_targets = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type FusionTarget
    // Serialize message field [num_id_target]
    bufferOffset = _serializer.uint8(obj.num_id_target, buffer, bufferOffset);
    // Serialize message field [num_no_id_target]
    bufferOffset = _serializer.uint8(obj.num_no_id_target, buffer, bufferOffset);
    // Serialize message field [id_targets]
    // Serialize the length for message field [id_targets]
    bufferOffset = _serializer.uint32(obj.id_targets.length, buffer, bufferOffset);
    obj.id_targets.forEach((val) => {
      bufferOffset = Target.serialize(val, buffer, bufferOffset);
    });
    // Serialize message field [no_id_targets]
    // Serialize the length for message field [no_id_targets]
    bufferOffset = _serializer.uint32(obj.no_id_targets.length, buffer, bufferOffset);
    obj.no_id_targets.forEach((val) => {
      bufferOffset = Target.serialize(val, buffer, bufferOffset);
    });
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type FusionTarget
    let len;
    let data = new FusionTarget(null);
    // Deserialize message field [num_id_target]
    data.num_id_target = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [num_no_id_target]
    data.num_no_id_target = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [id_targets]
    // Deserialize array length for message field [id_targets]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.id_targets = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.id_targets[i] = Target.deserialize(buffer, bufferOffset)
    }
    // Deserialize message field [no_id_targets]
    // Deserialize array length for message field [no_id_targets]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.no_id_targets = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.no_id_targets[i] = Target.deserialize(buffer, bufferOffset)
    }
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 15 * object.id_targets.length;
    length += 15 * object.no_id_targets.length;
    return length + 10;
  }

  static datatype() {
    // Returns string type for a message object
    return 'roborts_msgs/FusionTarget';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '4b446fdc6c26040d3eceffafbf5e0975';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    uint8 num_id_target
    uint8 num_no_id_target
    Target[] id_targets
    Target[] no_id_targets
    
    ================================================================================
    MSG: roborts_msgs/Target
    uint8 id
    uint8 state
    uint8 sensor
    float32 x
    float32 y
    float32 confidence
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new FusionTarget(null);
    if (msg.num_id_target !== undefined) {
      resolved.num_id_target = msg.num_id_target;
    }
    else {
      resolved.num_id_target = 0
    }

    if (msg.num_no_id_target !== undefined) {
      resolved.num_no_id_target = msg.num_no_id_target;
    }
    else {
      resolved.num_no_id_target = 0
    }

    if (msg.id_targets !== undefined) {
      resolved.id_targets = new Array(msg.id_targets.length);
      for (let i = 0; i < resolved.id_targets.length; ++i) {
        resolved.id_targets[i] = Target.Resolve(msg.id_targets[i]);
      }
    }
    else {
      resolved.id_targets = []
    }

    if (msg.no_id_targets !== undefined) {
      resolved.no_id_targets = new Array(msg.no_id_targets.length);
      for (let i = 0; i < resolved.no_id_targets.length; ++i) {
        resolved.no_id_targets[i] = Target.Resolve(msg.no_id_targets[i]);
      }
    }
    else {
      resolved.no_id_targets = []
    }

    return resolved;
    }
};

module.exports = FusionTarget;
