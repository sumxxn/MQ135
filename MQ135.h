/**************************************************************************/
/*!
@file     MQ135.h
@author   G.Krocker (Mad Frog Labs)
@license  GNU GPLv3

First version of an Arduino Library for the MQ135 gas sensor
TODO: Review the correction factor calculation. This currently relies on
the datasheet but the information there seems to be wrong.

@section  HISTORY

v1.0 - First release
*/
/**************************************************************************/
#ifndef MQ135_H
#define MQ135_H
#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

/// The load resistance on the board
float RLOAD = 10.0;
/// Calibration resistance at atmospheric CO2 level
float RZERO = 76.63;
/// Parameters for calculating ppm of CO2 from sensor resistance
float PARA = 116.6020682;
float PARB = 2.769034857;

/// Parameters to model temperature and humidity dependence
float CORA = .00035;
float CORB = .02718;
float CORC = 1.39538;
float CORD = .0018;
float CORE = -.003333333;
float CORF = -.001923077;
float CORG = 1.130128205;

/// Atmospheric CO2 level for calibration purposes
float ATMOCO2 = 406.88;

class MQ135 {
 private:
  uint8_t _pin;

 public:
  MQ135(uint8_t pin);
  float getCorrectionFactor(float t, float h);
  float getResistance();
  float getCorrectedResistance(float t, float h);
  float getPPM();
  float getCorrectedPPM(float t, float h);
  float getRZero();
  float getCorrectedRZero(float t, float h);
};
#endif
