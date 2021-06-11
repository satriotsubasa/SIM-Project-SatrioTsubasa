#include <TinyGPS++.h>
#include <SoftwareSerial.h>

//Variable_Declaration
int RXPin = 2;
int TXPin = 3;
int GPSBaud = 9600;

//Library_Setup
TinyGPSPlus gps;
SoftwareSerial gpsSerial(RXPin, TXPin);
TinyGPSCustom SatelliteStrength(gps, "GPGSV", 7);

void setup()
{
  //SerialComm_Setup
  Serial.begin(9600);
  gpsSerial.begin(GPSBaud);
}

//Get_GPS_Data_Continously
void loop()
{
  while (gpsSerial.available() > 0)
    if (gps.encode(gpsSerial.read()))
    {
      //Print_to_SerialMonitor_and_VisualStudioApp
      printSerMon();
      //sendSerial();
    }

  //When_No_GPS
  if (millis() > 5000 && gps.charsProcessed() < 10)
  {
    Serial.println("No GPS detected");
    while(true);
  }
}

//Print_To_Serial_Monitor
void printSerMon()
{
  if (gps.location.isValid())
  {
    Serial.print("Latitude           : "); Serial.println(gps.location.lat(), 6);
    Serial.print("Longitude          : "); Serial.println(gps.location.lng(), 6);
    Serial.print("Altitude           : "); Serial.println(gps.altitude.meters());
    Serial.print("Satellite Detected : "); Serial.println(gps.satellites.value());
    Serial.print("Strength Satellite : "); Serial.print(SatelliteStrength.value()); Serial.println(" db");
  }
  else
  {
    Serial.println("Location Not Available");
  }
  
  if (gps.date.isValid())
  {
    Serial.print("Date               : ");
    Serial.print(gps.date.month()); Serial.print("/");
    Serial.print(gps.date.day());   Serial.print("/");
    Serial.println(gps.date.year());
  }
  else
  {
    Serial.println("Date Not Available");
  }

  if (gps.time.isValid())
  {
    Serial.print("Time               : ");
    
    if ((gps.time.hour()+7) < 10)
    {
      Serial.print(F("0"));
    }
    Serial.print(gps.time.hour()+7); Serial.print(":");
    
    if (gps.time.minute() < 10)
    {
      Serial.print(F("0"));
    }
    Serial.print(gps.time.minute()); Serial.print(":");
    
    if (gps.time.second() < 10)
    {
      Serial.print(F("0"));
    }
    Serial.print(gps.time.second()); Serial.print(".");
    
    if (gps.time.centisecond() < 10)
    {
      Serial.print(F("0"));
    }
    Serial.println(gps.time.centisecond());
  }
  else
  {
    Serial.println("Time Not Available");
  }
  Serial.println();
  Serial.println();
  delay(1000);
}

//Send_Data_To_VisualStudio_Via_SerialComm
void sendSerial()
{
  Serial.print(gps.location.lat(), 6);
  Serial.print("#");
  Serial.print(gps.location.lng(), 6);
  Serial.print("#");
  Serial.print("34.3812");
  Serial.print("#");
  Serial.print(SatelliteStrength.value());
  Serial.print("#");
  Serial.print("2");
  Serial.print("#");
  if (gps.time.hour() < 10) Serial.print(F("0"));
  Serial.print(gps.time.hour()+7);
  Serial.print(":");
  if (gps.time.minute() < 10) Serial.print(F("0"));
  Serial.print(gps.time.minute());
  Serial.print(":");
  if (gps.time.second() < 10) Serial.print(F("0"));
  Serial.print(gps.time.second());
  Serial.print(".");
  if (gps.time.centisecond() < 10) Serial.print(F("0"));
  Serial.print(gps.time.centisecond());
  Serial.print("#");
  Serial.print(gps.date.month());
  Serial.print("/");
  Serial.print(gps.date.day());
  Serial.print("/");
  Serial.println(gps.date.year());
  delay(1000);
}
