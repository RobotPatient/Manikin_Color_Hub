#include "DFRobot_AS7341.h"
/*!
 * @brief Construct the function
 * @param pWire IC bus pointer object and construction device, can both pass or not pass parameters, Wire in default.
 */
DFRobot_AS7341 as7341;

void setup(void)
{
  Serial.begin(115200);
  as7341.enableLed(true);
  //Detect if IIC can communicate properly 
  while (as7341.begin() != 0) {
    Serial.println("IIC init failed, please check if the wire connection is correct");
    delay(1000);
  }
}
void loop(void)
{
  DFRobot_AS7341::sModeOneData_t data1;
  DFRobot_AS7341::sModeTwoData_t data2;

  //Start spectrum measurement 
  //Channel mapping mode: 1.eF1F4ClearNIR,2.eF5F8ClearNIR
  as7341.startMeasure(as7341.eF1F4ClearNIR);
  //Read the value of sensor data channel 0~5, under eF1F4ClearNIR
  data1 = as7341.readSpectralDataOne();
  
  // Serial.print("F1(405-425nm):");
  // Serial.println(data1.ADF1);
  // Serial.print("F2(435-455nm):");
  // Serial.println(data1.ADF2);
  // Serial.print("F3(470-490nm):");
  // Serial.println(data1.ADF3);
  // Serial.print("F4(505-525nm):");   
  // Serial.println(data1.ADF4);
  // //Serial.print("Clear:");
  // //Serial.println(data1.ADCLEAR);
  // //Serial.print("NIR:");
  // //Serial.println(data1.ADNIR);
  as7341.startMeasure(as7341.eF5F8ClearNIR);
  //Read the value of sensor data channel 0~5, under eF5F8ClearNIR
  data2 = as7341.readSpectralDataTwo();
  // Serial.print("F5(545-565nm):");
  // Serial.println(data2.ADF5);
  // Serial.print("F6(580-600nm):");
  // Serial.println(data2.ADF6);
  // Serial.print("F7(620-640nm):");
  // Serial.println(data2.ADF7);
  // Serial.print("F8(670-690nm):");
  // Serial.println(data2.ADF8);
  // Serial.print("Clear:");
  // Serial.println(data2.ADCLEAR);
  // Serial.print("NIR:");
  // Serial.println(data2.ADNIR);

  // fill an array with sensor data
  int data[8] = {data1.ADF1, data1.ADF2, data1.ADF3, data1.ADF4, data2.ADF5, data2.ADF6, data2.ADF7, data2.ADF8};
  int dataIndex = 0;
  int topVal = 0;

  for (int i = 0; i < 8; i++) {
    switch(i) {
      case 0:
        Serial.print("F1(405-425nm): ");
      break;
      case 1:
        Serial.print("F2(405-425nm): ");
      break;
      case 2:
        Serial.print("F3(405-425nm): ");
      break;
      case 3:
        Serial.print("F4(405-425nm): ");
      break;
      case 4:
        Serial.print("F5(405-425nm): ");
      break;
      case 5:
        Serial.print("F6(405-425nm): ");
      break;
      case 6:
        Serial.print("F7(405-425nm): ");
      break;
      case 7:
        Serial.print("F8(405-425nm): ");
      break;
    }
    
    int mapedVal = map(data[i], 0, 255, 0, 9);

    switch(mapedVal) {
      case 0:
        Serial.println("");
      break;
      case 1:
        Serial.println("##");
      break;
      case 2:
        Serial.println("####");
      break;
      case 3:
        Serial.println("######");
      break;
      case 4:
        Serial.println("########");
      break;
      case 5:
        Serial.println("##########");
      break;
      case 6:
        Serial.println("############");
      break;
      case 7:
        Serial.println("##############");
      break;
      case 8:
        Serial.println("################");
      break;
      case 9:
        Serial.println("##################");
      break;
      default:
        Serial.println("########MAX#######");
    }
  }  

  Serial.print("\n\n\n");

  delay(50);
}
