#include <VirtualWire.h>

int pino = A0;

byte message[VW_MAX_MESSAGE_LEN];    // Armazena as mensagens recebidas
byte msgLength = VW_MAX_MESSAGE_LEN; // Armazena o tamanho das mensagens


void setup()   {
  pinMode(pino, INPUT_PULLUP);
  Serial.begin(9600);
  vw_set_rx_pin(pino); // Define o pino do Arduino como entrada de dados do receptor
  vw_setup(2000);             // Bits por segundo
  vw_rx_start();              // Inicializa o receptor
  delay(2000);
}

void loop()
{
  uint8_t message[VW_MAX_MESSAGE_LEN];
  uint8_t msgLength = VW_MAX_MESSAGE_LEN;
  vw_get_message(message, &msgLength); // Non-blocking
  Serial.print("Recebido: ");
  for (int i = 0; i < msgLength; i++)
    Serial.print(message[i]);
  Serial.println();
  msgLength = 0;

}
