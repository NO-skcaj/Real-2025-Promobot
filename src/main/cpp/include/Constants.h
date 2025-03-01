/* Constants are declared as defines, defines are NOT variables, just values that are filled in by compiler    */
/* This is because these constants NEVER change so it's possible and smart to keep them as compiler directives */


/* 
   We do the ifndef ${MACRO} as a header guard, this ensures
   that when we include this header in multiple files, the 
   code is only copied once. 
   This is recommended to do on all headers, and you should
   do as such!
   (Same thing as 'pragma once') 
*/

#ifndef CONSTANTS
#define CONSTANTS

/* I/O */
#define CONTROLLER_ID 0

/* WestCoast */
#define L_MASTER_ID 6
#define L_SLAVE_ID  7
#define R_MASTER_ID 1
#define R_SLAVE_ID  4
#define SAFETY_ENABLED false
#define RIGHT_INVERTED true
#define LEFT_INVERTED  false
#define INPUT_MULTIPLIER_Y 1
#define INPUT_MULTIPLIER_X 1

/* Axe */
#define AXE_MOTOR_ID 17
#define AXE_INPUT_MULTIPLIER .1

/* Pneumatics */
#define PNEUMATICS_ID 9

#endif