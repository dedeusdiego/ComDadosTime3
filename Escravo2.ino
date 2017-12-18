//escravo 2
int endereco = 2;
byte recByte;
const int LDR = A0;
uint8_t PinD1 = D4; 
int input_val = 0;

//pin configuration
void setup(){
  Serial.begin(9600);
  pinMode(PinD1, OUTPUT);
  pinMode(LED_BUILTIN,OUTPUT);
  digitalWrite(PinD1,HIGH);
}

void loop(){
 input_val  = analogRead(LDR);
 if(Serial.available()){
   recByte = Serial.read();
 }

 if(recByte == 1){ 
   if(digitalRead(LED_BUILTIN)==LOW){
  digitalWrite(LED_BUILTIN,HIGH);
  digitalWrite(PinD1,LOW);
   Serial.println("liguei o led");
   }
   else{
    digitalWrite(LED_BUILTIN,LOW);
    digitalWrite(PinD1,HIGH);
    Serial.println("desliguei o led");
   }
    recByte = 0;
 }

 if(recByte == 2){ 
  Serial.write(input_val);
 }
}


