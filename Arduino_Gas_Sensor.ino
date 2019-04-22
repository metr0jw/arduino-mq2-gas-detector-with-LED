#define R 5
#define G 7
#define B 2
#define MQ2 A0  //아날로그 신호
#define buzzer A1 //아날로그 신호

unsigned int gaslevel=0;

void setup()
 {
  Serial.begin(9600);
    pinMode(MQ2,INPUT);
    pinMode(R,OUTPUT);
    pinMode(G,OUTPUT);
    pinMode(B,OUTPUT);
    pinMode(buzzer, OUTPUT);
 }
 
void loop()
{
  gaslevel=(analogRead(MQ2));
  gaslevel=map(gaslevel,0,1023,1,255);  //analogRead에서 반환한 0부터 1023의 값을를 0에서 255까지의 퍼센테이지로 매핑
    
 if(gaslevel > 0 && gaslevel <= 35){//가스 지수가 10 이상 35미만
    digitalWrite(R,HIGH);  //빨간불 켜짐
    digitalWrite(B,HIGH);  //파란불 켜짐
      delay(500); //딜레이 500ms
        digitalWrite(G,LOW); //초록불 ㄲㅓ짐
      delay(500); //딜레이 500ms, 버저 꺼짐
      noTone(buzzer);
      delay(1);
    }
  
  else if(gaslevel > 35 && gaslevel <= 37){//가스 지수가 30 이상 50미만
         digitalWrite(B,HIGH);  //파란불 꺼짐
          delay(500); //딜레이 500ms
         digitalWrite(R,LOW); //빨간불 켜짐
         digitalWrite(G,LOW); //초록불 켜짐(노란색 출력)
          delay(500); //딜레이 500ms, 버저 꺼짐
          noTone(buzzer);
          delay(1);
    }
      
       else if(gaslevel > 37 ){//가스 지수가 50 이상 90 미만
        digitalWrite(G,LOW);  //초록불 켜짐
        digitalWrite(B,LOW);  //파란불 켜짐
    tone(buzzer, 800); //버저 울림
          delay(600); //딜레이 300ms              
            digitalWrite(R,HIGH); //빨간불 꺼짐
    tone(buzzer, 500);  //버저 꺼짐
          delay(400); //딜레이 400ms
      }
  Serial.println(gaslevel); //모니터에 가스 레벨 프린트함, azure같은 서버에 데이터 전송 추가예정
  delay(100);
}
