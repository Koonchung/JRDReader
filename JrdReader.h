/*
 * @File: JrdReader.h
 * @Description: An Arduino Lirary used to read RFID code from baggage.
 * @Author: elvin chan
 * @CreatedTime: 2020-04-21
 * @LastEditTime: 2020-05-04
 */

#include "Arduino.h"

#ifndef _JRDREADER_H__
#define _JRDREADER_H__

class JrdReader {
  
  private:

  public:
    JrdReader();
    String readOnce();
    void stopRead();
};

#endif
