//Dylan Bharrat
int mA = 9;
int input1 = 8;
int input2 = 7;

int mB = 3;
int input3 = 5;
int input4 = 4;


void setup()
{
  pinMode(mA, OUTPUT);		//settting all of the variables 
                            //to OUTPUT
  pinMode(mB, OUTPUT);
  pinMode(input1, OUTPUT);
  pinMode(input2, OUTPUT);
  pinMode(input3, OUTPUT);
  pinMode(input4, OUTPUT);
  
  digitalWrite(input1, LOW);	//settting all of the motors
                                //to OFF in beginning
  digitalWrite(input2, LOW);
  digitalWrite(input3, LOW);
  digitalWrite(input4, LOW);
  
  Serial.begin(9600);
  Serial.println("Speed 0 to 255");
}

void loop()
{
  int input=0;
  while(input == 0) 
  {
    input = Serial.parseInt();
  }

  if (input == 1)            //When the user inputs 1, the Motors coast
  {
    Coast();
    Serial.println("COAST");
  }


  if (input==2)              //When the user inputs 1, the Motors Braking
  { 
    Braking();
    Serial.println("BRAKING");
  }


  if (input==4)              //When the user inputs 1, the Motors Swing turn
  {
    Swing();
    Serial.println("SWING");
  }

  
  if (input == 3)            //When the user inputs 1, the Motors Point turn
  {
    Point();
    Serial.println("POINT");    
  }
 
  
}
void Coast()
{
  digitalWrite(mA, 255);
  digitalWrite(input1, HIGH);
  digitalWrite(input2, LOW);
  digitalWrite(mB, 255);			
  digitalWrite(input3, HIGH);
  digitalWrite(input4, LOW);    
}

void Swing()
{
  int sinput=0;
  while(sinput == 0)
  {
    sinput = Serial.parseInt();
  }
  MotorS1(sinput);
  MotorS2();

}

  void MotorS1(int s)
  {
    {
      digitalWrite(mA, 200);
      digitalWrite(input1, LOW);
      digitalWrite(input2, HIGH);
    }
  }


void MotorS2()
{
  digitalWrite(mB, 255);				
  digitalWrite(input3, HIGH);
  digitalWrite(input4, LOW);
}

void Point()
{
  int pinput=0;
  while(pinput == 0)
  {
    pinput = Serial.parseInt();
  }
  MotorP1(pinput);
  MotorP2();

}

void MotorP1(int p)
{

  {
    digitalWrite(mA, 0);
    digitalWrite(input1, LOW);
    digitalWrite(input2, LOW);
  }
}


void MotorP2()
{
  digitalWrite(mB, 255);				
  digitalWrite(input3, HIGH);
  digitalWrite(input4, LOW);
}


void Braking()
{
  MotorB1();
  MotorB2();

}

void MotorB1()
{
  {
    digitalWrite(mA, 100);
    digitalWrite(input1, LOW);
    digitalWrite(input2, HIGH);
  }
}


void MotorB2()
{

  {
    digitalWrite(mB, 100);
    digitalWrite(input3, LOW);
    digitalWrite(input4, HIGH);
  }
} 