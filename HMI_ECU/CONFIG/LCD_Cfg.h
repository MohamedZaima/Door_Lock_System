#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H

/* ================================================================= */
/* LCD I2C CONFIGURATION                                             */
/* ================================================================= */

/* I2C Hardware Module Selection */
/* Using I2C Module 0 (PB2 = SCL, PB3 = SDA) */
#define LCD_I2C_MODULE       0   // I2C0
#define LCD_I2C_PORT         1   // Port B (1 = Port B in many mappings)

/* I2C Address of the PCF8574 Backpack */
/* Common values: 0x27 (TI/NXP) or 0x3F (Others) */
/* Run an I2C scanner if unsure, but 0x27 is the most common default */

#endif /* LCD_CONFIG_H */