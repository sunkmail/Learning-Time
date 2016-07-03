unsigned long Time;
unsigned long TimeStart;
int dd, hh, mm, ss, ms;
unsigned long MakeMillis=0;

const unsigned long OneDay = 86400000;
const unsigned long OneHour = 3600000;
const unsigned long OneMin = 60000;
const unsigned long OneSecond = 1000;

String DisplayTime; 


void setup() {
	Serial.begin(9600);      // open the serial port at 9600 bps:
	
	//setTime(hr,min,sec,day,month,yr);
	//setTime(0,0,0,1,1,2000); // Set Time to Jan 1, 2000 - For easy math!
	//  setTime(0);
	TimeStart= millis();
}

void loop() {
	
	delay(3426);
	//  Time = now();       //Reads the milli sec from the setTime()
	Time = (millis() - TimeStart);
	Serial.print("Read Time in ms, from start: ");
	Serial.println(Time);
	DoTime();
	ShowTime();
	MakeTime();
	Serial.print("Calculated time in ms: ");
	Serial.println(MakeMillis);
	Serial.println();
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
		Time = Time - (hh * OneHour); // Removes full hours, so TIME is less than 1 Hour
	}
	if (Time >= OneMin)
	{
		mm = Time / OneMin;         // determine how many full mins in number
		Time = Time - (mm * OneMin); // Removes full mins, so TIME is less than 1 min
	}
	if (Time >= OneSecond)
	{
		ss = Time / OneSecond;         // determine how many full days in number
		ms = Time - (ss * OneSecond); // Removes full mins, so TIME is less than 1 min
		// Less than full seconds not used on display, no more math needed
	}
}

void ShowTime(void)
{
	//	DisplayTime = String(("Runtime: ")+dd+(":")+hh+(":")+mm+(":")+ss);
	DisplayTime = String("Runtime: ");
	if(dd <10)
		DisplayTime += "0";
	DisplayTime += dd;
	DisplayTime += ":";
	if(hh <10)
		DisplayTime += "0";
	DisplayTime += hh;
	DisplayTime += ":";
	if(mm <10)
		DisplayTime += "0";
	DisplayTime += mm;
	DisplayTime += ":";
	if(ss <10)
		DisplayTime += "0";
	DisplayTime += ss;
	
	Serial.println(DisplayTime);
	
}

void MakeTime(void)
{
	MakeMillis = ((dd * OneDay) + (hh * OneHour) + (mm * OneMin) + (ss * OneSecond) + ms);
}
