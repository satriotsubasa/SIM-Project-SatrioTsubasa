#include <SoftwareSerial.h>
#define DEBUG true
#define MAX_WORD_COUNT 20 //MAX_WORD_PARSE
#define MIN_WORD_COUNT 2 //MIN_WORD_PARSE

//Variable_Declaration
char *Words[MAX_WORD_COUNT];
String TimeDateGPS,Latitude, Longitude, Altitude, TotalSatellite, SatelliteID, GPSStrength, IPAddr, IMEI;
int YearGPS, MonthGPS, DayGPS, HourGPS, MinuteGPS, SecondGPS, GSMStr;

//Software_SerialComm_Declaration(RX,TX)
SoftwareSerial mySerial(2,3); 
  
void setup()
{
  //Set_Baudrate
  Serial.begin(9600);
  mySerial.begin(9600); 

  //Setup_Device
  getgpsgsm();
}

//GET_Data_Continuously
void loop()
{
   //GPS_Data
   sendDataLoc("AT+CGNSINF",500,DEBUG); 
   sendDataSignal("AT+CGPSINF=16",500,DEBUG);
   
   //HTTP_INIT_and_GSM_GET_IP_Prep
   sendData("AT+HTTPACTION=0",5000,DEBUG);
   sendDataIP("AT+HTTPREAD=0,14",1000,DEBUG); //myIpv4

   //GSM_Data
   sendDataGSM("AT+CSQ",500,DEBUG);
   sendDataIMEI("AT+CGSN",1000,DEBUG);
   
   //Print_All_Data_and_Send_to_VisualStudio_App
   printSerMon();
   //sendSerial();  
}

void getgpsgsm(void)
{
   //Device_Setup
   sendData("AT+CGNSPWR=1",1000,DEBUG); 
   sendData("AT+CGPSINF=0",1000,DEBUG);
   sendData("AT+SAPBR=3,1,\"APN\",\"vodafone\"",1000,DEBUG);
   sendData("AT+SAPBR=1,1",1000,DEBUG);
   sendData("AT+HTTPINIT",1000,DEBUG);
   sendData("AT+HTTPPARA=\"URL\",\"http://ipv4bot.whatismyipaddress.com\"",1000,DEBUG);
   sendData("AT+HTTPPARA?",1000,DEBUG);
   
}

void printSerMon()
{
  //Print_To_Serial_Monitor
  Serial.print("Date               : "); Serial.print(YearGPS); Serial.print("/"); Serial.print(MonthGPS); Serial.print("/"); Serial.println(DayGPS);
  Serial.print("Time               : "); Serial.print(HourGPS); Serial.print(":"); Serial.print(MinuteGPS); Serial.print(":"); Serial.println(SecondGPS);
  Serial.print("Latitude           : "); Serial.println(Latitude);
  Serial.print("Longitude          : "); Serial.println(Longitude);
  Serial.print("Altitude           : "); Serial.println(Altitude);
  Serial.print("Satellite Detected : "); Serial.println(TotalSatellite);
  Serial.print("GPS Signel Strength: "); Serial.print(GPSStrength); Serial.println("dB");
  Serial.print("My IP Address      : "); Serial.println(IPAddr);
  Serial.print("GSM Signal Strength: "); Serial.print(GSMStr); Serial.println("dBm");
  Serial.print("Device IMEI        : "); Serial.println(IMEI);
  Serial.println(); 
}

void sendSerial()
{
  //Send_Data_To_VisualStudio_Via_SerialComm
  Serial.print(Latitude);
  Serial.print("#"); Serial.print(Longitude);
  Serial.print("#"); Serial.print(Altitude);
  Serial.print("#"); Serial.print(GPSStrength);
  Serial.print("#"); Serial.print(TotalSatellite);
  Serial.print("#"); Serial.print(HourGPS); Serial.print(":"); Serial.print(MinuteGPS); Serial.print(":"); Serial.print(SecondGPS);
  Serial.print("#"); Serial.print(YearGPS); Serial.print("/"); Serial.print(MonthGPS); Serial.print("/"); Serial.print(DayGPS);
  Serial.print("#"); Serial.print(IPAddr);
  Serial.print("#"); Serial.print(GSMStr);
  Serial.print("#"); Serial.println(IMEI);
}

//Parse_Process_GPS_Location_and_Time_Data
void sendDataLoc(String command, const int timeout, boolean debug)
{
    String response = "";    
    String GPSData = "";
    char c_GPSData[200];
    byte word_count;  
    
    mySerial.println(command); 
    delay(5);
    response = "";  
    if(debug){
    long int time = millis();   
    
    while( (time+timeout) > millis())
    {
      while(mySerial.available())
      {       
        response += char(mySerial.read());
      }  
    }    
      response.remove(0,23);
      GPSData = response;
      
      int str_len = GPSData.length() + 1; 
      GPSData.toCharArray(c_GPSData, str_len);
      word_count = split_message(c_GPSData);
      
      TimeDateGPS = String(Words[2]);
      YearGPS = TimeDateGPS.substring(0,4).toInt();
      MonthGPS = TimeDateGPS.substring(4,6).toInt();
      DayGPS = TimeDateGPS.substring(6,8).toInt();
      HourGPS = (TimeDateGPS.substring(8,10).toInt()) + 7;
      MinuteGPS = TimeDateGPS.substring(10,12).toInt();
      SecondGPS = TimeDateGPS.substring(12,14).toInt();
      
      Latitude = String(Words[3]);
      Longitude = String(Words[4]);
      Altitude = String(Words[5]);
    }    
}

//Parse_Process_GPS_Signal_Data
void sendDataSignal(String command, const int timeout, boolean debug)
{
    String response = "";    
    String GPSData = "";
    char c_GPSData[200];
    byte word_count;  
    
    mySerial.println(command); 
    delay(5);
    response = "";  
    if(debug){
    long int time = millis();   
    
    while( (time+timeout) > millis())
    {
      while(mySerial.available())
      {       
        response += char(mySerial.read());
      }  
    }    
      response.remove(0,26);
      response.remove(50);
      GPSData = response;
      //Serial.println(GPSData);
      
      int str_len = GPSData.length() + 1; 
      GPSData.toCharArray(c_GPSData, str_len);
      word_count = split_message(c_GPSData); 

      TotalSatellite = String(Words[3]);
      SatelliteID = String(Words[4]);
      GPSStrength = String(Words[7]);  
    }    
}

//Parse_Process_IP_Address_Data
void sendDataIP(String command, const int timeout, boolean debug)
{
    String response = "";    
    String GPSData = "";
    char c_GPSData[200];
    byte word_count;  
    
    mySerial.println(command); 
    delay(5);
    response = "";  
    if(debug){
    long int time = millis();   
    
    while( (time+timeout) > millis())
    {
      while(mySerial.available())
      {       
        response += char(mySerial.read());
      }  
    }    
      response.remove(0,34);
      response.remove(15);
      GPSData = response;
      IPAddr = GPSData;      
    }    
}

//Parse_Process_GSM_Signal_Data
void sendDataGSM(String command, const int timeout, boolean debug)
{
    String response = "";    
    String GPSData = "";
    char c_GPSData[200];
    byte word_count;  
    
    mySerial.println(command); 
    delay(5);
    response = "";  
    if(debug){
    long int time = millis();   
    
    while( (time+timeout) > millis())
    {
      while(mySerial.available())
      {       
        response += char(mySerial.read());
      }  
    }    
      response.remove(0,15);
      response.remove(2);
      GPSData = response;
      GSMStr = GPSData.toInt();
      GSMStr = map(GSMStr, 2, 30, -110, -54);
    }    
}

//Parse_Process_IMEI_Device
void sendDataIMEI(String command, const int timeout, boolean debug)
{
    String response = "";    
    String GPSData = "";
    char c_GPSData[200];
    byte word_count;  
    
    mySerial.println(command); 
    delay(5);
    response = "";  
    if(debug){
    long int time = millis();   
    
    while( (time+timeout) > millis())
    {
      while(mySerial.available())
      {       
        response += char(mySerial.read());
      }  
    }    
      response.remove(0,10);
      response.remove(15);
      GPSData = response;
      IMEI = GPSData;
      
    }    
}

//Parse_Process_Other_ATCommand
void sendData(String command, const int timeout, boolean debug)
{
    String response = "";

    mySerial.println(command); 
    delay(5);
    response = "";  
    if(debug){
    long int time = millis();   
    while( (time+timeout) > millis())
    {
      while(mySerial.available())
      {       
        response += char(mySerial.read());
      }  
    }    
      Serial.print(response);
    }    
}

//Split_Word_in_All_Parse_Process
byte split_message(char* str)
{
  byte word_count = 0; //number of words
  char * item = strtok (str, " ,"); //getting first word (uses space & comma as delimeter)

  while (item != NULL)
  {
    if (word_count >= MAX_WORD_COUNT)
    {
      break;
    }
    Words[word_count] = item;
    item = strtok (NULL, " ,"); //getting subsequence word
    word_count++;
  }
  return  word_count;
}
