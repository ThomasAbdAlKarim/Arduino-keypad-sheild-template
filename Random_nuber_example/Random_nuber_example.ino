#include <LiquidCrystal.h>
const int pin_RS = 8; 
const int pin_EN = 9; 
const int pin_d4 = 4; 
const int pin_d5 = 5; 
const int pin_d6 = 6; 
const int pin_d7 = 7; 
const int pin_BL = 10;
String Up = "Up";
String Down = "Down";
String Left = "Left";
String Right = "Right";
String Any = "Any";
String Sel = "Sel";
//Objects number (Change Size Only)
#define Size 10
int Pos[2*Size];
String obj[Size]; 
//*********************************
int val = 1;
int val2 = 1;
int val3 = 1;
bool stat = false;
LiquidCrystal lcd( pin_RS,  pin_EN,  pin_d4,  pin_d5,  pin_d6,  pin_d7);
void setup() {
 Serial.begin(9600);
 lcd.begin(16, 2);
 lcd.clear();
 //Setup default Pos & Val
 obj[0] = "1";
 obj[1] = "1";
 obj[2] = "-";
 obj[3] = "1";
 obj[4] = "|";
 obj[5] = "|";
 obj[6] = "GO";
 obj[7] = "";
 obj[8] = "";
 obj[9] = "";
 Pos[0] = 0;
 Pos[1] = 0;
 Pos[2] = 3;
 Pos[3] = 0;
 Pos[4] = 0;
 Pos[5] = 1;
 Pos[6] = 6;
 Pos[7] = 0;
 Pos[8] = 7;
 Pos[9] = 0;
 Pos[10] = 7;
 Pos[11] = 1;
 Pos[12] = 8;
 Pos[13] = 0;
 Pos[14] = 11;
 Pos[15] = 0;
 Pos[16] = 14;
 Pos[17] = 0;
 Pos[18] = 11;
 Pos[19] = 1;
 lcd.clear();
 Draw(obj,Pos);
 //*****************
}
void loop() 
{
  if(GetKey(Up)and !stat)
  {
    if(Pos[4] == Pos[0])
    {
    val += 1;
    obj[0] = String(val);
    }
    else if(Pos[4] == Pos[2])
    {
    val2 += 1;
    obj[1] = String(val2);
    }
    else if(Pos[4] == Pos[6])
    {
    val3 += 1;
    obj[3] = String(val3);
    }
    Draw(obj,Pos);
    stat = GetKey(Up);
  }
  else if(GetKey(Down)and !stat)
  {
    if(Pos[4] == Pos[0])
    {
    val -= 1;
    obj[0] = String(val);
    }
    else if(Pos[4] == Pos[2])
    {
    val2 -= 1;
    obj[1] = String(val2);
    }
    else if(Pos[4] == Pos[6])
    {
    val3 -= 1;
    obj[3] = String(val3);
    }
    Draw(obj,Pos);
    stat = GetKey(Down);
  }
  else if(GetKey(Left)and !stat)
  {
    Pos[4] -=3;
    if(Pos[4] < 0)Pos[4] = 0;
    Draw(obj,Pos);
    stat = GetKey(Left);
  }
  else if(GetKey(Right)and !stat)
  {
    Pos[4] +=3;
    if(Pos[4] > 9)Pos[4] = 9;
    Draw(obj,Pos);
    stat = GetKey(Right);
  }
  else if(GetKey(Sel)and !stat)
  {
    if(Pos[4] == Pos[12]+1)
    {
      int ran = random(1,41);
      int ran2 = random(1,41);
      int ran3 = random(1,41);
      if(val == ran and val2 == ran2 and val3 == ran3)
      {
        obj[9] = "win";
      }
       else if(val == ran or val2 == ran2 or val3 == ran3)
      {
        int scr = 0;
        if(val == ran)scr+=1;
        if(val2 == ran2)scr+=1;
        if(val3 == ran3)scr+=1;
        obj[9] = "win"+String(scr);
      }
      else
      {
        obj[9] = "Loose";
      }
      obj[6] = String(ran);
      obj[7] = String(ran2);
      obj[8] = String(ran3);
      Draw(obj,Pos);
    }
    stat = GetKey(Sel);
  }
  else if(!GetKey(Any))
  { 
    stat = false;
  }
} 

void Draw(String obj[],int pos[])
{
  lcd.clear();
  int Pc = 0;
    for(int i = 0;i < Size ;i++)
    {
    lcd.setCursor(pos[Pc],pos[Pc+1]);
    lcd.print(obj[i]);
    Pc += 2;
    }
}


bool GetKey(String Key)
{
  if(Key == Up)
  {
    if(analogRead(A0) >= 130 and analogRead(A0) <= 134)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else if(Key == Sel)
  {
    if(analogRead(A0) > 718 and analogRead(A0) < 724 )
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else if(Key == Down)
  {
    if(analogRead(A0) > 300 and analogRead(A0) < 311 )
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else if(Key == Left)
  {
    if(analogRead(A0) > 474 and analogRead(A0) < 481 )
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else if(Key == Right)
  {
    if(analogRead(A0) >= 0 and analogRead(A0)<=5)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else if(Key == Any)
  {
    if(GetKey(Up)or GetKey(Down) or GetKey(Left) or GetKey(Right)or GetKey(Sel))
    {
      return true;
    }
    else
    {
      return false;
    }
   }
}
