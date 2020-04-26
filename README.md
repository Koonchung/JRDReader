# JRDReader

## Introduction

An easy to use library for Arduino to read RFID code from baggage.

Works with:

 * [JRD-100](http://www.szjrddz.com/c2558.html)

## Installation

Download this library to `/libraries` and restart Arduino IDE.

## Usage

### readOnce():

```C++
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
```

### More methods are coming soon