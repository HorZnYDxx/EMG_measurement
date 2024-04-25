
#include <NewTone.h>

int v[20];
int del = 1;
int i = 0;
long sum = 0;
int avg;

void setup() {
  Serial.begin(115200);

  //R=肌肉中間,G=末端,Y=非此肌肉的地方
}

void loop() {
  v[i] = analogRead(3);
  sum += v[i] - v[del];
  i++;
  del++;

  if (i > 19) {
    i = 0;
  }
  if (del > 19) {
    del = 0;
  }
  avg = sum / 20;
  Serial.print("0,200,400,600,800,1000,");
  Serial.print(v[i]);
  Serial.print(",");
  Serial.println(avg);

  delay(25);
}
