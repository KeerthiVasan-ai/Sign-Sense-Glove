#define rxPin 1
#define txPin 0  

char c[20];
int s[4],sensorValue[4], sensorMax[4]={0}, sensorMin[4]={1023}, sensorAverage[4]={500,500,400,500}; //we can save sensorAverage according to the system or we calibrate sensor values. 
void setup() 
{
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(A3,INPUT);
  pinMode(A2,INPUT);
  pinMode(A1,INPUT);

  //sensorCalibrate(); //If u need to calibrate sensor values 
}

void wCase()
{
  if(s[0]==0 && s[1]==0 && s[2]==0 && s[3]==0)
  {
      strcpy(c,"HELP");
  }
  else if(s[0]==0 && s[1]==0 && s[2]==0 && s[3]==1)
  {
      strcpy(c,"HAPPY");
  }
  else if(s[0]==0 && s[1]==0 && s[2]==1 && s[3]==0)
  {
      strcpy(c,"NICE");
  }
  else if(s[0]==0 && s[1]==0 && s[2]==1 && s[3]==1)
  {
      strcpy(c,"VICTORY");
  }
  else if(s[0]==0 && s[1]==1 && s[2]==0 && s[3]==0)
  {
      strcpy(c,"PROPOSE");
  }
  else if(s[0]==0 && s[1]==1 && s[2]==0 && s[3]==1)
  {
      strcpy(c,"MOVIE");
  }
  else if(s[0]==0 && s[1]==1 && s[2]==1 && s[3]==0)
  {
      strcpy(c,"WORSHIP");
  }
  else if(s[0]==0 && s[1]==1 && s[2]==1 && s[3]==1)
  {
      strcpy(c,"DANGER");
  }
  else if(s[0]==1 && s[1]==0 && s[2]==0 && s[3]==0)
  {
      strcpy(c,"WORST");
  }
  else if(s[0]==1 && s[1]==0 && s[2]==0 && s[3]==1)
  {
      strcpy(c,"INTERESTING");
  }
  else if(s[0]==1 && s[1]==0 && s[2]==1 && s[3]==0)
  {
      strcpy(c,"PARTY");
  }
  else if(s[0]==1 && s[1]==0 && s[2]==1 && s[3]==1)
  {
      strcpy(c,"HUNGRY");
  }
  else if(s[0]==1 && s[1]==1 && s[2]==0 && s[3]==0)
  {
      strcpy(c,"FUN");
  }
  else if(s[0]==1 && s[1]==1 && s[2]==0 && s[3]==1)
  {
      strcpy(c,"MUSIC");
  }
  else if(s[0]==1 && s[1]==1 && s[2]==1 && s[3]==0)
  {
      strcpy(c,"MEDICINE");
  }
  else
  {
    strcpy(c,"BREAK");
  }         
    Serial.println(c);
    delay(1000);
}

void loop() 
{
  aRead();
  bAssign();
  wCase();
}
void aRead()
{
  sensorValue[0]=analogRead(A0);
  sensorValue[1]=analogRead(A1);
  sensorValue[2]=analogRead(A2);
  sensorValue[3]=analogRead(A3);
}
void bAssign()
{
  if(sensorValue[0]>sensorAverage[0])
  {
    s[0]=0;
    
  }
  else
  {
    s[0]=1;
   
  }
  if(sensorValue[1]>sensorAverage[1])
    {
      s[1]=0;
     
    }
  else
  {
    s[1]=1;
 
  }
  if(sensorValue[2]>sensorAverage[2])
    {
      s[2]=0;
     
    }
  else
    {
      s[2]=1;
    
    }
  if(sensorValue[3]>sensorAverage[3])
    {
      s[3]=0;
     
    }
  else
    {
      s[3]=1;
    
    }
}
void sensorCalibrate()
{
        Serial.println("Calibrating..");
        for(int i=0;i<1000;i++)
        {
          aRead(); 
          if(sensorValue[0]>sensorMax[0])
            sensorMax[0]=sensorValue[0];
          if(sensorValue[0]<sensorMin[0])
            sensorMin[0]=sensorValue[0];

          if(sensorValue[1]>sensorMax[1])
            sensorMax[1]=sensorValue[1];
          if(sensorValue[1]<sensorMin[1])
            sensorMin[1]=sensorValue[1];

          if(sensorValue[2]>sensorMax[2])
            sensorMax[2]=sensorValue[2];
          if(sensorValue[2]<sensorMin[2])
            sensorMin[2]=sensorValue[2];

          if(sensorValue[3]>sensorMax[3])
            sensorMax[3]=sensorValue[3];
          if(sensorValue[3]<sensorMin[3])
            sensorMin[3]=sensorValue[3];

          delay(5);
        }      
       sensorAverage[0]=(sensorMax[0]+sensorMin[0])/2;
       sensorAverage[1]=(sensorMax[1]+sensorMin[1])/2;
       sensorAverage[2]=(sensorMax[2]+sensorMin[2])/2;
       sensorAverage[3]=(sensorMax[3]+sensorMin[3])/2;
       Serial.println(sensorAverage[0]);
       Serial.println(sensorAverage[1]);
       Serial.println(sensorAverage[2]);
       Serial.println(sensorAverage[3]);
   }
