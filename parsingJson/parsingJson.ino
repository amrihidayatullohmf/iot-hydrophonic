#include <ArduinoJson.h>

StaticJsonBuffer<200> jsonBuffer;
char json[] = "{\"status\":\"ok\",\"code\":200,\"actuators\":{\"led1\":1,\"led2\":0}}"; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  JsonObject& root = jsonBuffer.parseObject(json);
  if(!root.success()) {
    Serial.println("parseObject() failed");
    return false;
  }
  char *statusresponse = root["status"];
  char *coderesponse = root["code"];
  int actuator_led1 = root["actuators"]["led1"];
  int actuator_led2 = root["actuators"]["led2"];

  Serial.print("Code: ");
  Serial.println(coderesponse);
  Serial.print("Status: ");
  Serial.println(statusresponse);
  Serial.print("Led1: ");
  Serial.println(actuator_led1);
  Serial.print("Led2: ");
  Serial.println(actuator_led2);
}

void loop() {
  // put your main code here, to run repeatedly:

}
