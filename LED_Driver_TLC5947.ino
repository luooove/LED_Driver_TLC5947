/*
LED_Driver_TLC5947
This is an sketch for LED Dirier Test. The chip is TLC5947


  modified 2014年10月6日
  by luo xiaoxiang
 */
int GS[48] = {0x000,0x1f0,0x1f0,0x1f0,0x1f0,0x1f0,  //Device1 LED23 -- LED18
              0x1f0,0x1f0,0x1f0,0x1f0,0x1f0,0x1f0,  //        LED17 -- LED12
              0x1f0,0x1f0,0x1f0,0x1f0,0x1f0,0x1f0,  //        LED11 -- LED6
              0x1f0,0x1f0,0x1f0,0x1f0,0x1f0,0x1f0,  //        LED5 -- LED0
              
              0x1f0,0x1f0,0x1f0,0x1f0,0x1f0,0x1f0,  //Device0 LED23 -- LED18
              0x1f0,0x1f0,0x1f0,0x1f0,0x1f0,0x1f0,  //        LED17 -- LED12
              0x1f0,0x1f0,0x1f0,0x1f0,0x1f0,0x1f0,  //        LED11 -- LED6          
              0x1f0,0x1f0,0x1f0,0x1f0,0x1f0,0x1f0   //        LED5 -- LED0
              };
int CLK = 7;
int Data = 6;
// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(CLK, OUTPUT);
  pinMode(Data, OUTPUT);
  digitalWrite(CLK, LOW);   // 
  digitalWrite(Data, LOW);   // 
}

// the loop function runs over and over again forever
void loop() {
  updata();
  delay(5000);              // wait for a second
  
}

void Write_12bit(int GSn)//写12个字节，把并行数据转换为串行
{
  int factor = 4096;
  int temp = 0; 
  digitalWrite(CLK, LOW);
  for(int i = 0;i<12;i++)
    {
      digitalWrite(CLK, HIGH);
      factor = factor/2;//转换成为二进制
      temp = GSn/factor;
      GSn = GSn%factor;
      Serial.print(temp);
      if(temp == 1)
      {
        digitalWrite(Data, HIGH);   // 
      }   
      else
      {
        digitalWrite(Data, LOW);   // 
      }
     digitalWrite(CLK, LOW);
    //  delay(10);              // wait for a second
    } 
  //   digitalWrite(CLK, HIGH);
 //    digitalWrite(CLK, LOW);
     Serial.println("");
}

void updata()//上传数据 把每一个比特位写入
{
  for(int j = 47;j>=0;j--)
  Write_12bit(GS[j]);
}

