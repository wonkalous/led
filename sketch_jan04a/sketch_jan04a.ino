
int switchState, tally;
boolean down;
boolean done;

void setup(){
  tally = 0;
  down = done = false;
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);  
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
   
}

void loop(){
  switchState = digitalRead(2);
  if (switchState == HIGH) {
   down = true;
   //if (! done) {
     delay(10*tally * random(10));
     tally++;
     done = true;
     if (tally & 1){ digitalWrite(3, HIGH);} else {digitalWrite(3, LOW);}
     if (tally & 2){ digitalWrite(4, HIGH);} else {digitalWrite(4, LOW);}
     if (tally & 4){ digitalWrite(5, HIGH);} else {digitalWrite(5, LOW);}
   //}
   
  }
  else {
    down = false;
    done = false;
    tally = tally & 7;
  }
  
  
}
