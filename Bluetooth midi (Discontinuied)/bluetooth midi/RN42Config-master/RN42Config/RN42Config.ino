/*
 * Copyright (c) 2015 Evan Kale
 * Email: EvanKale91@gmail.com
 * Website: www.ISeeDeadPixel.com
 *          www.evankale.blogspot.ca
 *
 * This file is part of RN42Config.
 *
 * RN42Config is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <MIDI.h>



#include <SoftwareSerial.h>

SoftwareSerial bluetoothSerial(10, 11); //(RX, TX)
MIDI_CREATE_DEFAULT_INSTANCE();

static const unsigned ledPin = 13; 

void setup()
{
  Serial.begin(115200);
  bluetoothSerial.begin(115200);
      pinMode(ledPin, OUTPUT);
    MIDI.begin(4); 
}

void loop() {


        digitalWrite(ledPin, HIGH);
        MIDI.sendNoteOn(42, 127, 1);    // Send a Note (pitch 42, velo 127 on channel 1)
        delay(1000);   
          if (bluetoothSerial.available())
  {
    Serial.print((char)bluetoothSerial.read());
  }
  if (Serial.available())
  {
    bluetoothSerial.print((char)Serial.read());
  }// Wait for a second
        MIDI.sendNoteOff(42, 0, 1);     // Stop the note
        digitalWrite(ledPin, LOW);
          if (bluetoothSerial.available())
  {
    Serial.print((char)bluetoothSerial.read());
  }
  if (Serial.available())
  {
    bluetoothSerial.print((char)Serial.read());
  }
}




