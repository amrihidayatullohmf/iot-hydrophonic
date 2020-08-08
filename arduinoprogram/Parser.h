#include <ArduinoJson.h>

JsonObject& decodeJson(char json[]) {
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(json);
  if(!root.success()) {
    Serial.println("parseObject() failed");
    return false;
  }
  return root;
}
