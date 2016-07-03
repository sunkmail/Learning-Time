#include <Time.h>
#include <TimeLib.h>


unsigned long Time;
int dd, hh, mm, ss;
unsigned long MakeMillis;

const unsigned long OneDay = 86400000;
const unsigned long OneHour = 3600000;
const unsigned long OneMin = 60000;
const unsigned long OneSecond = 1000;


void setup() {
  Serial.begin(9600);      // open the serial port at 9600 bps:

  //setTime(hr,min,sec,day,month,yr);
  //setTime(0,0,0,1,1,2000); // Set Time to Jan 1, 2000 - For easy math!
  setTime(0);
}

void loop() {

  delay(3426);
  Time = now();       //Reads the milli sec from the setTime()
  Serial.print("Read Time in ms: ");
  Serial.print(Time);
  DoTime();
  ShowTime();
  MakeTime();
  Serial.print("Calculated time in ms: ");
  Serial.print(MakeMillis);
}

void DoTime(void)
{
  if (Time >= OneDay)
  {
    dd = Time / OneDay;         // determine how many full days in number
    Time = Time - (dd * OneDay); // Removes full days, so TIME is less than 1 Day
  }
  if (Time >= OneHour)
  {
    hh = Time / OneHour;         // determine how many full hours in number
    Time = Time - (dd * OneHour); // Removes full hours, so TIME is less than 1 Hour
  }
  if (Time >= OneMin)
  {
    mm = Time / OneMin;         // determine how many full mins in number
    Time = Time - (dd * OneMin); // Removes full mins, so TIME is less than 1 min
  }
  if (Time >= OneSecond)
  {
    ss = Time / OneSecond;         // determine how many full days in number
    // Less than full seconds not used on display, no more math needed
  }
}

void ShowTime(void)
{
  Serial.print("Runtime: ");
  Serial.print(dd);
  Serial.print(":");
  Serial.print(hh);
  Serial.print(":");
  Serial.print(mm);
  Serial.print(":");
  Serial.print(ss);
}

void MakeTime(void)
{
  MakeMillis = ((dd * OneDay) + (hh * OneHour) + (mm * OneMin) + (ss * OneSecond));
}
