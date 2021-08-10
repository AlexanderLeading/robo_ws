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

class ShooterCmd {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.is_shoot = null;
      this.shoot_cmd = null;
      this.c_shoot_cmd = null;
      this.fric_wheel_run = null;
      this.shoot_freq = null;
    }
    else {
      if (initObj.hasOwnProperty('is_shoot')) {
        this.is_shoot = initObj.is_shoot
      }
      else {
        this.is_shoot = false;
      }
      if (initObj.hasOwnProperty('shoot_cmd')) {
        this.shoot_cmd = initObj.shoot_cmd
      }
      else {
        this.shoot_cmd = 0;
      }
      if (initObj.hasOwnProperty('c_shoot_cmd')) {
        this.c_shoot_cmd = initObj.c_shoot_cmd
      }
      else {
        this.c_shoot_cmd = 0;
      }
      if (initObj.hasOwnProperty('fric_wheel_run')) {
        this.fric_wheel_run = initObj.fric_wheel_run
      }
      else {
        this.fric_wheel_run = 0;
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
    // Serializes a message object of type ShooterCmd
    // Serialize message field [is_shoot]
    bufferOffset = _serializer.bool(obj.is_shoot, buffer, bufferOffset);
    // Serialize message field [shoot_cmd]
    bufferOffset = _serializer.uint8(obj.shoot_cmd, buffer, bufferOffset);
    // Serialize message field [c_shoot_cmd]
    bufferOffset = _serializer.uint8(obj.c_shoot_cmd, buffer, bufferOffset);
    // Serialize message field [fric_wheel_run]
    bufferOffset = _serializer.uint8(obj.fric_wheel_run, buffer, bufferOffset);
    // Serialize message field [shoot_freq]
    bufferOffset = _serializer.uint16(obj.shoot_freq, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ShooterCmd
    let len;
    let data = new ShooterCmd(null);
    // Deserialize message field [is_shoot]
    data.is_shoot = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [shoot_cmd]
    data.shoot_cmd = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [c_shoot_cmd]
    data.c_shoot_cmd = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [fric_wheel_run]
    data.fric_wheel_run = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [shoot_freq]
    data.shoot_freq = _deserializer.uint16(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 6;
  }

  static datatype() {
    // Returns string type for a message object
    return 'roborts_msgs/ShooterCmd';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '1ce874438e33b75dd468a5f9109af925';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool is_shoot
    uint8 shoot_cmd
    uint8 c_shoot_cmd
    uint8 fric_wheel_run
    uint16 shoot_freq
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ShooterCmd(null);
    if (msg.is_shoot !== undefined) {
      resolved.is_shoot = msg.is_shoot;
    }
    else {
      resolved.is_shoot = false
    }

    if (msg.shoot_cmd !== undefined) {
      resolved.shoot_cmd = msg.shoot_cmd;
    }
    else {
      resolved.shoot_cmd = 0
    }

    if (msg.c_shoot_cmd !== undefined) {
      resolved.c_shoot_cmd = msg.c_shoot_cmd;
    }
    else {
      resolved.c_shoot_cmd = 0
    }

    if (msg.fric_wheel_run !== undefined) {
      resolved.fric_wheel_run = msg.fric_wheel_run;
    }
    else {
      resolved.fric_wheel_run = 0
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

module.exports = ShooterCmd;
