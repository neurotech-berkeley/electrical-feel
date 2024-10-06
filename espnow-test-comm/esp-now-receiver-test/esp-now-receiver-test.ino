//this code is for Conrad's ESP32 Feather

#include <esp_now.h>

//mac address of receiver
uint8_t broadcastAddress[] = {0x40, 0xE7, 0x29, 0x97, 0x18, 0x14};

char data = 'a';

void setup()  {
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  // Register peer
  memcpy(peerInfo.peer_addr, broadcastAddress, 6);
  peerInfo.channel = 0;
  peerInfo.encrypt = false;

  // Add peer
  if (esp_now_add_peer(&peerInfo) != ESP_OK){
    Serial.println("Failed to add peer");
    return;
  }

}

void loop() {

}