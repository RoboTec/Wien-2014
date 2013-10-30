#include "NXCDefs.h"

#define SpeedNorm 100
#define Schwarzwert 50
#define stime 2000

//Variablen
long intzeroval;
int GreenAttempts;
int time;
bool DownFloor;
byte count;
bool DirectionRight;
byte SpeedLeft;
byte SpeedRight;
long sensorTime;

void InitSensors()
{
     SetSensorTouch(IN_1);
     SetSensorLight(IN_2);
     SetSensorLight(IN_3);
	 SetSensorColorFull(IN_4);

}

void StartTiming()
{
     intzeroval = CurrentTick();
}

void HandleCounting()
{
     ++count;
     if(count >= 50)
     {
         count = 0;
     }
}

long ReturnTime()
{
     return (CurrentTick() - intzeroval);
}

void TurnRight()
{
     SpeedLeft = -70;
     SpeedRight = 80;
     DirectionRight = true;
}

void TurnLeft()
{
     SpeedLeft = 80;
     SpeedRight = -70;
     DirectionRight = false;
}

void StartGreenLine()
{
     sensorTime = CurrentTick();
}

void CheckGreen()
{
     int color = SENSOR_4;
     switch(color)
     {
         case 3:
              PlayTone(3000, 20);

              GreenAttempts += 1;
              if(GreenAttempts > 8)
              {
                  StartGreenLine();
              }

         break;
         default:
              GreenAttempts = 0;
         break;
     }
}

long ReturnSensorTime()
{
     return (CurrentTick() - sensorTime);
}