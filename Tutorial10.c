#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#define UART_BUFFER_SIZE 64
typedef struct {
    uint8_t buffer[UART_BUFFER_SIZE];
    int head;
    int tail;
    int count;
} UART_Buffer;
typedef struct {
    UART_Buffer txBuffer;
    UART_Buffer rxBuffer;
} UART_Device;
void UART_Buffer_Init(UART_Buffer *buf) {
    buf->head = 0;
    buf->tail = 0;
    buf->count = 0;
}
bool UART_Buffer_IsFull(UART_Buffer *buf) {
    return buf->count == UART_BUFFER_SIZE;
}
bool UART_Buffer_IsEmpty(UART_Buffer *buf) {
    return buf->count == 0;
}
bool UART_Buffer_Enqueue(UART_Buffer *buf, uint8_t data) {
    if (UART_Buffer_IsFull(buf)) return false;
    buf->buffer[buf->head] = data;
    buf->head = (buf->head + 1) % UART_BUFFER_SIZE;
    buf->count++;
    return true;
}
bool UART_Buffer_Dequeue(UART_Buffer *buf, uint8_t *data) {
    if (UART_Buffer_IsEmpty(buf)) return false;
    *data = buf->buffer[buf->tail];
    buf->tail = (buf->tail + 1) % UART_BUFFER_SIZE;
    buf->count--;
    return true;
}
void UART_Init(UART_Device *uart) {
    UART_Buffer_Init(&uart->txBuffer);
    UART_Buffer_Init(&uart->rxBuffer);
    printf("UART Initialized.\n");
}
void UART_SendByte(UART_Device *uart, uint8_t data) {
    if (UART_Buffer_Enqueue(&uart->txBuffer, data))
        printf("TX: '%c' enqueued\n", data);
    else
        printf("TX Buffer Full! Data lost.\n");
}
void UART_ReceiveByte(UART_Device *uart, uint8_t data) {
    if (UART_Buffer_Enqueue(&uart->rxBuffer, data))
        printf("RX: '%c' received\n", data);
    else
        printf("RX Buffer Full! Data lost.\n");
}
void UART_ProcessTransmit(UART_Device *uart) {
    uint8_t data;
    while (UART_Buffer_Dequeue(&uart->txBuffer, &data)) {
        printf("Transmitted: '%c'\n", data);
    }
}
void UART_ReadReceivedData(UART_Device *uart) {
    uint8_t data;
    while (UART_Buffer_Dequeue(&uart->rxBuffer, &data)) {
        printf("Read from RX: '%c'\n", data);
    }
}
int main() {
    UART_Device uart;
    UART_Init(&uart);
    UART_SendByte(&uart, 'H');
    UART_SendByte(&uart, 'E');
    UART_SendByte(&uart, 'L');
    UART_SendByte(&uart, 'L');
    UART_SendByte(&uart, 'O');
    UART_ProcessTransmit(&uart);
    UART_ReceiveByte(&uart, 'O');
    UART_ReceiveByte(&uart, 'K');
    UART_ReadReceivedData(&uart);
    return 0;
}
