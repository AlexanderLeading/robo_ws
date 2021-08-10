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

class DodgeMode {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.is_dodge = null;
    }
    else {
      if (initObj.hasOwnProperty('is_dodge')) {
        this.is_dodge = initObj.is_dodge
      }
      else {
        this.is_dodge = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type DodgeMode
    // Serialize message field [is_dodge]
    bufferOffset = _serializer.bool(obj.is_dodge, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type DodgeMode
    let len;
    let data = new DodgeMode(null);
    // Deserialize message field [is_dodge]
    data.is_dodge = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 1;
  }

  static datatype() {
    // Returns string type for a message object
    return 'roborts_msgs/DodgeMode';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'e86a3c0123103abb455aca69f2a22f53';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool is_dodge
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new DodgeMode(null);
    if (msg.is_dodge !== undefined) {
      resolved.is_dodge = msg.is_dodge;
    }
    else {
      resolved.is_dodge = false
    }

    return resolved;
    }
};

module.exports = DodgeMode;
