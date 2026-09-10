#ifndef LCD_H_
#define LCD_H_

#include <stdint.h>


/* --------------------------------------------------------------------------
 * LCD COMMANDS
 * -------------------------------------------------------------------------- */

/*
 * TODO:
 * Determine these values from the LCD instruction table.
 *
 * Avoid magic numbers in lcd.c and main.c.
 */

#define LCD_CLEAR_HOME       0x00U   /* TODO */
#define LCD_NEW_LINE         0x00U   /* TODO */
#define LCD_CURSOR_BLINK     0x00U   /* TODO */
#define LCD_FUNCTION_SET     0x00U   /* TODO */
#define LCD_ENTRY_MODE       0x00U   /* TODO */


/* --------------------------------------------------------------------------
 * LCD PIN DEFINITIONS
 * -------------------------------------------------------------------------- */

/*
 * TODO:
 * Fill these in AFTER drawing your wiring diagram.
 *
 * Example format:
 *
 * #define LCD_RS_PIN        GPIO_PIN_x
 * #define LCD_RW_PIN        GPIO_PIN_x
 * #define LCD_E_PIN         GPIO_PIN_x
 *
 * If your data lines are spread across multiple ports, define each
 * data pin separately:
 *
 * #define LCD_DB0_PIN       GPIO_PIN_x
 * ...
 * #define LCD_DB7_PIN       GPIO_PIN_x
 *
 * You may also define the GPIO ports here.
 */


/* --------------------------------------------------------------------------
 * PUBLIC FUNCTION DECLARATIONS
 * -------------------------------------------------------------------------- */

void LCD_init(void);
void LCD_command(uint8_t command);
void LCD_write_char(uint8_t letter);
void LCD_write_string(const char *string);


#endif /* LCD_H_ */