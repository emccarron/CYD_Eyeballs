#include <TFT_eSPI.h>                 // Include the graphics library (this includes the sprite functions)

TFT_eSPI    tft = TFT_eSPI();         // Create object "tft"

TFT_eSprite spr = TFT_eSprite(&tft);  // Create Sprite object "img" with pointer to "tft" object
                                      // the pointer is used by pushSprite() to push it onto the TFT

void setup(void) {
  Serial.begin(250000);

  tft.init();

  tft.setRotation(3);

    tft.fillScreen(TFT_BLACK);
    //tft.fillCircle(120, 120, 120, TFT_WHITE);
    tft.fillEllipse(160, 120, 160, 120, TFT_WHITE);
    spr.setColorDepth(8);
    spr.createSprite(150,150);
    spr.fillSprite(TFT_TRANSPARENT);
    spr.fillCircle(75,75,70, TFT_WHITE);
    spr.fillCircle(75,75,66, TFT_BLUE);
    spr.fillCircle(75,75,36, TFT_BLACK);
    //tft.fillCircle(160,120,66, TFT_BLUE);
    //tft.fillCircle(160,120,36, TFT_BLACK);
    spr.pushSprite(90,45 , TFT_TRANSPARENT);
    pinMode(TFT_BL, OUTPUT);



    
}
int eyex = 85;
int lidy = 0;
int pick;
void loop() {

  pick = random(10);

  switch (pick) {
  case 1:
    lookleft();
    break;
  case 2:
    lookright();
    break;
  case 3 ... 4:
    blink();
    break;  
  default:
    // statements
    break;
}
delay(1000);


  

}

void lookleft(){
  while (eyex>0){
    spr.pushSprite(eyex,45, TFT_TRANSPARENT);
        eyex=eyex-3;
    }

    delay(2000);

      while (eyex<=85){
    spr.pushSprite(eyex,45 , TFT_TRANSPARENT);
        eyex=eyex+3;
    }
}

void lookright(){
  while (eyex<170){
    spr.pushSprite(eyex,45, TFT_TRANSPARENT);
        eyex=eyex+3;
    }

    delay(2000);

      while (eyex>=85){
    spr.pushSprite(eyex,45, TFT_TRANSPARENT);
        eyex=eyex-3;
    }
}

void blink(){

 //  tft.fillEllipse(160, 120, 160, 120, TFT_BLACK);

digitalWrite(TFT_BL, LOW);
delay(500);
digitalWrite(TFT_BL, HIGH);

//   tft.fillEllipse(160, 120, 160, 120, TFT_WHITE);
//  tft.fillCircle(160,120,66, TFT_BLUE);
//  tft.fillCircle(160,120,36, TFT_BLACK);
}  

