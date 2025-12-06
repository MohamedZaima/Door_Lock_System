#ifndef LCD_H
#define LCD_H

#include "../UTILS/std_types.h"

/* ================================================================= */
/* LCD COMMANDS                                                      */
/* ================================================================= */
#define LCD_CLEAR_COMMAND              0x01
#define LCD_GO_TO_HOME                 0x02
#define LCD_TWO_LINES_FOUR_BITS        0x28
#define LCD_CURSOR_OFF                 0x0C
#define LCD_CURSOR_ON                  0x0E
#define LCD_SET_CURSOR_LOCATION        0x80

/* ================================================================= */
/* FUNCTION PROTOTYPES                                               */
/* ================================================================= */

/* Initialize the LCD (starts I2C and sets up 4-bit mode) */
void Lcd_Init(void);

/* Send a raw command (e.g., clear screen, move cursor) */
void Lcd_SendCommand(u8 command);

/* Display a single character (e.g., 'A') */
void Lcd_DisplayCharacter(u8 data);

/* Display a full string (e.g., "Door Locked") */
void Lcd_DisplayString(char *Str);

/* Move cursor to specific position (Row: 0-1, Col: 0-15) */
void Lcd_GoToRowColumn(u8 row, u8 col);

/* Clear the screen */
void Lcd_Clear(void);

#endif