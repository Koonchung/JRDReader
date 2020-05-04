/*
 * @File: JrdReader.ino
 * @Description: A demo used to test the library.
 * @Author: elvin chan
 * @CreatedTime: 2020.5.3
 * @LastEditTime: 2020.5.3
 */

#include "JrdReader.h"

JrdReader reader;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);  
  
  String str = reader.readOnce();
  Serial.println(str);
  reader.stopRead();
}

void loop() {
  // put your main code here, to run repeatedly:
}
