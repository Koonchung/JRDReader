/*
   @File: JrdReader.cpp
   @Description: An Arduino Lirary used to read RFID code from baggage.
   @Author: elvin chan
   @CreatedTime: 2020-04-21
   @LastEditTime: 2020-05-04
*/

#include "Arduino.h"
#include "JrdReader.h"
#include "HardwareSerial.h"

/**
   read once HEX command
*/
char read_once_cmd[7] = {0xBB, 0x00, 0x22, 0x00, 0x00, 0x22, 0x7E};
/**
   stop reading HEX commamd
*/
char stop_read_cmd[7] = {0xBB, 0x00, 0x2B, 0x00, 0x00, 0x2B, 0x7E};

String comdata = "";

JrdReader::JrdReader() {

}

String JrdReader::readOnce() {

  String baggageCode = "";
  String comstr = "";

  // send read_once command
  Serial.write(read_once_cmd, 7);
  delay(50);
  while (Serial.available() > 0) {
    char data = Serial.read();
    comdata += String(data, HEX);
    delay(50);
  }

  if (comdata.length() > 0) {
    Serial.print("comdata: ");
    for (int i = 0; i < comdata.length(); i++) {
      comstr += String(comdata[i]);
      Serial.print(comdata[i]);
    }
    Serial.println();
  }

  // clear comdata in order to accept another one.
  comdata = "";

  // format comstr
  comstr.replace("ffff", "ss");
  comstr.replace("ff", "");
  comstr.replace("ss", "ff");

  Serial.println("comstr: " + comstr);

  if (comstr.length() > 13) {
    // read RFID code
    for (int i = 18; i < 28; i++) {
      baggageCode += comstr[i];
    }
  }
  else {
    baggageCode = "读取错误 (Unable to read)";
  }

  return baggageCode;

}

void JrdReader::stopRead() {

  String receiveCode = "";
  String comstr = "";

  // send stop reading command
  Serial.write(stop_read_cmd, 7);
  delay(50);
  while (Serial.available() > 0) {
    char data = Serial.read();
    comdata += String(data, HEX);
    delay(50);
  }

  if (comdata.length() > 0) {
    Serial.print("comdata: ");
    for (int i = 0; i < comdata.length(); i++) {
      comstr += String(comdata[i]);
      Serial.print(comdata[i]);
    }
    Serial.println();
  }

  // clear comdata in order to accept another one.
  comdata = "";

  // format comstr
  comstr.replace("ffff", "ss");
  comstr.replace("ff", "");
  comstr.replace("ss", "ff");

  Serial.println("comstr: " + comstr);

  if (comstr == "bb00f5000100f67e") {
    // read RFID code
    Serial.println("Multi-reading stopped.");
  }
  else {
    Serial.println("Failed to stop multi-reading. Received data:");
    Serial.println(comstr);
  }
}
