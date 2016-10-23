// HOW TO:
//  	display.clearDisplay();
//  	car.show();
//  	display.display();  

#include <Door.h>
#include <Adafruit_SSD1306.h>
// ********************************************************************************
// class Car
// ********************************************************************************
class Car{  
  private:
    Door doorFrontLeft 	;
    Door doorFrontRight ;
    Door doorRearLeft 	;
    Door doorRearRight 	;
    Door doorHood 		;
    Door doorBack 		;
	bool isChanged = false;
  public:  
	void show(Adafruit_SSD1306 display);
	bool processCanMessage(long unsigned int messageType, unsigned char length, unsigned char data[8]);
};

// ********************************************************************************
void Car::show(Adafruit_SSD1306 display)
{
  // show car   
  display.drawRoundRect(95, 1, 20, 26, 4, WHITE);
  display.drawRoundRect(97, 8, 16, 16, 4, WHITE);
  
  // show lights
  display.drawLine(95, 5, 100, 2, WHITE);
  display.drawLine(110-1, 2, 115-1, 5, WHITE);	
  
  // show doors
  switch (doorFrontLeft.getState()){
	case true:
		display.drawLine(95, 8, 85, 14, WHITE);
	break;
	case false:
		display.drawLine(95, 8, 85, 14, BLACK);
	break;
  }
  switch (doorFrontRight.getState()){
	case true:
		display.drawLine(95, 14, 85, 20, WHITE););
	break;
	case false:
		display.drawLine(95, 14, 85, 20, WHITE);;
	break;
  }	
   switch (doorRearLeft.getState()){
	case true:
		display.drawLine(115, 8, 125, 14, WHITE);
	break;
	case false:
		display.drawLine(115, 8, 125, 14, BLACK);
	break;
  }	
  switch (doorRearRight.getState()){
	case true:
		display.drawLine(115, 14, 125, 20, WHITE);
	break;
	case false:
		display.drawLine(115, 14, 125, 20, BLACK);
	break;
  }	
  switch (doorHood.getState()){
	case true:
		// TBD: show opened hood
	break;
	case false:
		// TBD: show closed hood
	break;
  }	
  switch (doorBack.getState()){
	case true:
		// TBD: show opened back door
	break;
	case false:
		// TBD: show closed bakc door
	break;
  }	  
}

// ********************************************************************************
bool Car::processCanMessage(long unsigned int messageType, unsigned char length, unsigned char data[8]){
	
}
