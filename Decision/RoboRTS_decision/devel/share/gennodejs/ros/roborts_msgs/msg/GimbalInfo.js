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

class GimbalInfo {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.ecd_yaw = null;
      this.ecd_pitch = null;
      this.gyro_yaw = null;
      this.gyro_pitch = null;
      this.yaw_rate = null;
      this.pitch_rate = null;
    }
    else {
      if (initObj.hasOwnProperty('ecd_yaw')) {
        this.ecd_yaw = initObj.ecd_yaw
      }
      else {
        this.ecd_yaw = 0.0;
      }
      if (initObj.hasOwnProperty('ecd_pitch')) {
        this.ecd_pitch = initObj.ecd_pitch
      }
      else {
        this.ecd_pitch = 0.0;
      }
      if (initObj.hasOwnProperty('gyro_yaw')) {
        this.gyro_yaw = initObj.gyro_yaw
      }
      else {
        this.gyro_yaw = 0.0;
      }
      if (initObj.hasOwnProperty('gyro_pitch')) {
        this.gyro_pitch = initObj.gyro_pitch
      }
      else {
        this.gyro_pitch = 0.0;
      }
      if (initObj.hasOwnProperty('yaw_rate')) {
        this.yaw_rate = initObj.yaw_rate
      }
      else {
        this.yaw_rate = 0.0;
      }
      if (initObj.hasOwnProperty('pitch_rate')) {
        this.pitch_rate = initObj.pitch_rate
      }
      else {
        this.pitch_rate = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type GimbalInfo
    // Serialize message field [ecd_yaw]
    bufferOffset = _serializer.float64(obj.ecd_yaw, buffer, bufferOffset);
    // Serialize message field [ecd_pitch]
    bufferOffset = _serializer.float64(obj.ecd_pitch, buffer, bufferOffset);
    // Serialize message field [gyro_yaw]
    bufferOffset = _serializer.float64(obj.gyro_yaw, buffer, bufferOffset);
    // Serialize message field [gyro_pitch]
    bufferOffset = _serializer.float64(obj.gyro_pitch, buffer, bufferOffset);
    // Serialize message field [yaw_rate]
    bufferOffset = _serializer.float64(obj.yaw_rate, buffer, bufferOffset);
    // Serialize message field [pitch_rate]
    bufferOffset = _serializer.float64(obj.pitch_rate, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type GimbalInfo
    let len;
    let data = new GimbalInfo(null);
    // Deserialize message field [ecd_yaw]
    data.ecd_yaw = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [ecd_pitch]
    data.ecd_pitch = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [gyro_yaw]
    data.gyro_yaw = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [gyro_pitch]
    data.gyro_pitch = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [yaw_rate]
    data.yaw_rate = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [pitch_rate]
    data.pitch_rate = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 48;
  }

  static datatype() {
    // Returns string type for a message object
    return 'roborts_msgs/GimbalInfo';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'de1cd11d7e2cb10eb47cdbc531727f86';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64 ecd_yaw
    float64 ecd_pitch
    float64 gyro_yaw
    float64 gyro_pitch
    float64 yaw_rate
    float64 pitch_rate
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new GimbalInfo(null);
    if (msg.ecd_yaw !== undefined) {
      resolved.ecd_yaw = msg.ecd_yaw;
    }
    else {
      resolved.ecd_yaw = 0.0
    }

    if (msg.ecd_pitch !== undefined) {
      resolved.ecd_pitch = msg.ecd_pitch;
    }
    else {
      resolved.ecd_pitch = 0.0
    }

    if (msg.gyro_yaw !== undefined) {
      resolved.gyro_yaw = msg.gyro_yaw;
    }
    else {
      resolved.gyro_yaw = 0.0
    }

    if (msg.gyro_pitch !== undefined) {
      resolved.gyro_pitch = msg.gyro_pitch;
    }
    else {
      resolved.gyro_pitch = 0.0
    }

    if (msg.yaw_rate !== undefined) {
      resolved.yaw_rate = msg.yaw_rate;
    }
    else {
      resolved.yaw_rate = 0.0
    }

    if (msg.pitch_rate !== undefined) {
      resolved.pitch_rate = msg.pitch_rate;
    }
    else {
      resolved.pitch_rate = 0.0
    }

    return resolved;
    }
};

module.exports = GimbalInfo;
