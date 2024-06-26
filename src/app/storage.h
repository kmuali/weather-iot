/**
 * @file storage.h
 * @brief Functions of storage measurement.
 *
 * This file contains declarations for functions related to storage measurement
 * and management.
 * It stores any data along with current data and time automatically.
 * It uses circular queue to handle storage in EEPROM.
 *
 * @author Mahmoud Gamal
 * @date May 10 2024
 */

#ifndef STORAGE_H
#define STORAGE_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "../hal/ds1307.h"

/* The size is application dependent */
#define STORAGE_BLOCK_DATA_SIZE 3

// EEPROM base address
#define STORAGE_BASE_ADDRESS         0x0000

// EEPROM cursor address
#define STORAGE_CURSOR_ADDRESS         0x03ff

// EEPROM block size
#define STORAGE_BLOCK_SIZE (STORAGE_BLOCK_DATA_SIZE + sizeof(RTC_Time_t))

// EEPROM size 
#define EEPROM_SIZE 1024

// total number of blocks
#define TOTAL_BLOCKS ((EEPROM_SIZE - 1) / STORAGE_BLOCK_SIZE)

typedef enum {
  STORAGE_OK = 0,
  STORAGE_ERROR = 1,
} storage_status_t;

// Function to initialize storage system
storage_status_t storage_init(void);

// Function to add a block of data
storage_status_t storage_enqueue_block(const uint8_t *p_data);

// Function to get the number of blocks stored in circular queue
storage_status_t storage_get_length(uint8_t *p_length);

// Function to get block of data
storage_status_t storage_get_block(uint8_t index, uint8_t *p_data,
                                   RTC_Time_t *p_timestamp);

#endif /* STORAGE_H */
