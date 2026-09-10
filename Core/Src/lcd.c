#include "main.h"
#include "lcd.h"


/* --------------------------------------------------------------------------
 * PRIVATE DEFINITIONS
 * -------------------------------------------------------------------------- */

/*
 * HAL_Delay() works in milliseconds.
 *
 * TODO:
 * Select development delays based on the LCD datasheet.
 * The lab recommends initially using delays longer than the minimum.
 */

#define LCD_ENABLE_DELAY_MS      1U
#define LCD_COMMAND_DELAY_MS     1U
#define LCD_LONG_DELAY_MS        2U


/* --------------------------------------------------------------------------
 * PRIVATE FUNCTION DECLARATIONS
 * -------------------------------------------------------------------------- */

static void LCD_GPIO_init(void);
static void LCD_write_bus(uint8_t value);
static void LCD_pulse_enable(void);
static void LCD_write(uint8_t value, uint8_t mode);


/* --------------------------------------------------------------------------
 * LCD GPIO INITIALIZATION
 * -------------------------------------------------------------------------- */

static void LCD_GPIO_init(void)
{
    /*
     * TODO:
     *
     * 1. Enable the RCC clock for every GPIO port used by the LCD.
     *
     * Lecture-style example:
     *
     * RCC->AHB2ENR |= (...);
     *
     * 2. Configure:
     *
     *      DB0 - DB7
     *      RS
     *      R/W
     *      E
     *
     * as GPIO outputs.
     *
     * Registers to consider:
     *
     * GPIOx->MODER
     * GPIOx->OTYPER
     * GPIOx->PUPDR
     * GPIOx->OSPEEDR
     *
     * 3. Put all LCD control signals into known starting states.
     *
     * In particular:
     *
     *      E   = low
     *      R/W = low
     *      RS  = low
     *
     * Use BSRR / BRR rather than HAL_GPIO_WritePin().
     */
}


/* --------------------------------------------------------------------------
 * WRITE 8-BIT LCD DATA BUS
 * -------------------------------------------------------------------------- */

static void LCD_write_bus(uint8_t value)
{
    /*
     * TODO:
     *
     * Put bits value[7:0] onto:
     *
     *      DB7 ... DB0
     *
     * Your implementation depends directly on your wiring.
     *
     * For one example bit, the idea is:
     *
     * if (value & (1U << 0))
     * {
     *     GPIOx->BSRR = LCD_DB0_PIN;
     * }
     * else
     * {
     *     GPIOx->BRR = LCD_DB0_PIN;
     * }
     *
     * Then repeat the idea for DB1 ... DB7.
     *
     * There may be a cleaner way if all eight data pins occupy
     * convenient positions within one GPIO port.
     */

    (void)value;
}


/* --------------------------------------------------------------------------
 * LCD ENABLE PULSE
 * -------------------------------------------------------------------------- */

static void LCD_pulse_enable(void)
{
    /*
     * TODO:
     *
     * Create the E pulse using BSRR and BRR.
     *
     * Important sequence:
     *
     *      E = 1
     *      delay
     *      E = 0       <-- LCD latches on this falling edge
     *      delay
     *
     * Do not forget that the lab specifically warns about timing
     * while the signal is LOW as well as HIGH.
     */

    /*
     * Example structure:
     *
     * LCD_CONTROL_PORT->BSRR = LCD_E_PIN;
     * HAL_Delay(LCD_ENABLE_DELAY_MS);
     *
     * LCD_CONTROL_PORT->BRR = LCD_E_PIN;
     * HAL_Delay(LCD_ENABLE_DELAY_MS);
     */
}


/* --------------------------------------------------------------------------
 * GENERIC LCD WRITE
 * -------------------------------------------------------------------------- */

static void LCD_write(uint8_t value, uint8_t mode)
{
    /*
     * This worker function can contain the behavior common to both
     * commands and characters.
     *
     * TODO:
     *
     * 1. Set R/W for a WRITE.
     *
     * 2. Set RS according to mode:
     *
     *      command -> RS = ?
     *      data    -> RS = ?
     *
     * 3. Call LCD_write_bus(value).
     *
     * 4. Call LCD_pulse_enable().
     *
     * 5. Wait for the LCD operation to complete.
     */

    (void)value;
    (void)mode;
}


/* --------------------------------------------------------------------------
 * SEND LCD COMMAND
 * -------------------------------------------------------------------------- */

void LCD_command(uint8_t command)
{
    /*
     * TODO:
     *
     * Call the common LCD_write() worker function using whatever
     * value you decide represents COMMAND mode.
     */

    (void)command;
}


/* --------------------------------------------------------------------------
 * WRITE ONE CHARACTER
 * -------------------------------------------------------------------------- */

void LCD_write_char(uint8_t letter)
{
    /*
     * TODO:
     *
     * Call LCD_write() using DATA mode.
     */

    (void)letter;
}


/* --------------------------------------------------------------------------
 * WRITE STRING
 * -------------------------------------------------------------------------- */

void LCD_write_string(const char *string)
{
    while (*string != '\0')
    {
        LCD_write_char((uint8_t)*string);
        string++;
    }
}


/* --------------------------------------------------------------------------
 * LCD INITIALIZATION
 * -------------------------------------------------------------------------- */

void LCD_init(void)
{
    LCD_GPIO_init();

    /*
     * TODO:
     *
     * Follow the LCD DATASHEET initialization sequence exactly.
     *
     * Do not invent the order from memory.
     *
     * General organization:
     *
     *      1. Power-up delay
     *
     *      2. LCD wake-up sequence
     *
     *      3. Configure 8-bit interface
     *
     *      4. Configure number of display lines / character size
     *
     *      5. Configure display and cursor
     *
     *      6. Configure entry mode
     *
     *      7. Clear/home display
     *
     * Each LCD_command() automatically needs an E pulse.
     *
     * Start with generous delays during development as recommended
     * by the lab manual.
     */
}