/*
 * @File: JrdReadOnce.ino
 * @Description: An example to read the baggage code once by using readOnce().
 * @Author: elvin chan
 * @CreatedTime: 2020.4.21
 * @LastEditTime: 2020.4.26
 */

#include "JrdReader.h"

JrdReader reader;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  String str = reader.readOnce();
  Serial.println(str);
  delay(2000);
}
