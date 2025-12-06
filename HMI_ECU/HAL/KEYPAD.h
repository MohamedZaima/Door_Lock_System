
/*****************************************************************************
 * File: keypad.h
 * Description: Header for 4x4 Keypad Driver
 * Author: Ahmedhh
 * Date: November 27, 2025
 *****************************************************************************/

#ifndef KEYPAD_H
#define KEYPAD_H

#include <stdint.h>

/*
 * Keypad mapping array declaration.
 * Each element is a null-terminated string representing the key value
 * (some keys may map to multi-character strings).
 */
extern const char *keypad_codes[4][4];

/* Keypad dimensions */
#define KEYPAD_ROWS 4
#define KEYPAD_COLS 4

/*
 * Initializes the keypad GPIO pins.
 * Must be called before using Keypad_GetKey.
 */
void Keypad_Init(void);

/*
 * Scans the keypad and returns the string (null-terminated) of the pressed key.
 * Returns NULL if no key is pressed.
 */
const char *Keypad_GetKey(void);

#endif // KEYPAD_H
