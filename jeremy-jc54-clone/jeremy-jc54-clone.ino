// -*- mode: c++ -*-

#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "jeremy@cowgar.com JC54 clone"
#endif

#include "Kaleidoscope.h"
#include "Kaleidoscope-Macros.h"
#include "Kaleidoscope-LEDControl.h"
#include "LED-Off.h"
#include "Kaleidoscope-LEDEffect-BootGreeting.h"
#include "Kaleidoscope-LEDEffect-SolidColor.h"
#include "Kaleidoscope-LEDEffect-Breathe.h"
#include "Kaleidoscope-LEDEffect-Chase.h"
#include "Kaleidoscope-LEDEffect-Rainbow.h"
#include "Kaleidoscope-LED-Stalker.h"
#include "Kaleidoscope-Model01-TestMode.h"
#include "Kaleidoscope-HostPowerManagement.h"
#include "Kaleidoscope-USB-Quirks.h"

#include <Kaleidoscope-Qukeys.h>

enum {
  MACRO_OPEN_ABOVE,
  MACRO_OPEN_BELOW,
  MACRO_OPEN_BRACE,
  MACRO_NOT_EQUAL,
  MACRO_NOT_EQUAL_EQUAL,
  MACRO_LESS_THAN_EQUAL,
  MACRO_GREATER_THAN_EQUAL,
  MACRO_EQUAL_GREATER_THAN,
  MACRO_EQUAL_GREATER_THAN_BRACE,
  MACRO_DOUBLE_AMP,
  MACRO_DOUBLE_PIPE,
  MACRO_DOUBLE_EQUAL,
  MACRO_TRIPLE_EQUAL,
  MACRO_PLUS_EQUAL,
  MACRO_MINUS_EQUAL
};

#define Mac_OpenAbove M(MACRO_OPEN_ABOVE)
#define Mac_OpenBelow M(MACRO_OPEN_BELOW)
#define Mac_OpenBrace M(MACRO_OPEN_BRACE)
#define Mac_NotEqual M(MACRO_NOT_EQUAL)
#define Mac_NotEqualEqual M(MACRO_NOT_EQUAL_EQUAL)
#define Mac_LessEqual M(MACRO_LESS_THAN_EQUAL)
#define Mac_GreaterEqual M(MACRO_GREATER_THAN_EQUAL)
#define Mac_EqualGreater M(MACRO_EQUAL_GREATER_THAN)
#define Mac_EqualGreaterBrace M(MACRO_EQUAL_GREATER_THAN_BRACE)
#define Mac_DoubleAmp M(MACRO_DOUBLE_AMP)
#define Mac_DoublePipe M(MACRO_DOUBLE_PIPE)
#define Mac_DoubleEqual M(MACRO_DOUBLE_EQUAL)
#define Mac_TripleEqual M(MACRO_TRIPLE_EQUAL)
#define Mac_PlusEqual M(MACRO_PLUS_EQUAL)
#define Mac_MinusEqual M(MACRO_MINUS_EQUAL)

enum { PRIMARY, FUNCTION }; // layers

// *INDENT-OFF*

KEYMAPS(
  [PRIMARY] = KEYMAP_STACKED(
    Key_Equals,        Key_1, Key_2, Key_3, Key_4, Key_5, Key_LEDEffectNext,
    Key_Tab,           Key_Q, Key_W, Key_E, Key_R, Key_T, Key_Home,
    Key_Backtick,      Key_A, Key_S, Key_D, Key_F, Key_G,
    Key_Backslash,     Key_Z, Key_X, Key_C, Key_V, Key_B, Key_Escape,
    Key_LeftShift, Key_Spacebar, Key_Backspace, Key_End,
    ShiftToLayer(FUNCTION),

    ___,               Key_6, Key_7, Key_8,     Key_9,         Key_0,         Key_Minus,
    Key_Enter,         Key_Y, Key_U, Key_I,     Key_O,         Key_P,         Key_LeftBracket,
                       Key_H, Key_J, Key_K,     Key_L,         Key_Semicolon, Key_Quote,
    Key_PageDown,      Key_N, Key_M, Key_Comma, Key_Period,    Key_Slash,     Key_RightBracket,
    Key_Home, Key_Delete, Key_Enter, Key_RightShift,
    ShiftToLayer(FUNCTION)),

  [FUNCTION] =  KEYMAP_STACKED(
    Key_F1,            Key_F2,          Key_F3,        Key_F4,            Key_F5,         Key_F6,           Key_CapsLock,
    Mac_DoubleEqual,   Mac_TripleEqual, Mac_NotEqual,  Mac_NotEqualEqual, Mac_LessEqual,  Mac_GreaterEqual, ___,
    Key_Escape,        Key_LeftControl, Key_LeftAlt,   Key_LeftGui,       Key_LeftShift,  Mac_PlusEqual,
    ___,               ___,             ___,           ___,               ___,            Mac_MinusEqual,   ___,
    ___, Key_Enter, Key_Delete, ___,
    ___,

    ___, Key_F7,                Key_F8,               Key_F9,                Key_F10,        Key_F11,                    Key_F12,
    ___, Mac_EqualGreater,      Key_LeftCurlyBracket, Key_RightCurlyBracket, Key_End,        Consumer_ScanPreviousTrack, Consumer_VolumeIncrement,
         Key_LeftArrow,         Key_DownArrow,        Key_UpArrow,           Key_RightArrow, Consumer_PlaySlashPause,    Consumer_VolumeDecrement,
    ___, Key_PageDown,          Mac_OpenAbove,        Mac_OpenBelow,         Mac_OpenBrace,  Consumer_ScanNextTrack,     Consumer_Mute,
    ___, Key_Backspace, Key_Spacebar, ___,  
    ___)
	)

// *INDENT-ON*

const macro_t *macroAction(uint8_t macroIndex, uint8_t keyState) {
  switch (macroIndex) {
  case MACRO_OPEN_ABOVE:
    return MACRODOWN(T(UpArrow), T(End), T(Enter));

  case MACRO_OPEN_BELOW:
    return MACRODOWN(T(End), T(Enter));
  
  case MACRO_OPEN_BRACE:
    return MACRODOWN(T(End), T(Space), D(LeftShift), T(LeftBracket), U(LeftShift), T(Enter));
   
  case MACRO_NOT_EQUAL:
    return MACRODOWN(D(LeftShift), T(1), U(LeftShift), T(Equals));
    
  case MACRO_NOT_EQUAL_EQUAL:
    return MACRODOWN(D(LeftShift), T(1), U(LeftShift), T(Equals), T(Equals));
  
  case MACRO_LESS_THAN_EQUAL:
    return MACRODOWN(D(LeftShift), T(Comma), U(LeftShift), T(Equals));
    
  case MACRO_GREATER_THAN_EQUAL:
    return MACRODOWN(D(LeftShift), T(Period), U(LeftShift), T(Equals));
    
  case MACRO_EQUAL_GREATER_THAN:
    return MACRODOWN(T(Equals), D(LeftShift), T(Period), U(LeftShift));
    
  case MACRO_EQUAL_GREATER_THAN_BRACE:
    return MACRODOWN(T(Equals), D(LeftShift), T(Period), U(LeftShift), T(Space), D(LeftShift), T(LeftBracket), U(LeftShift), T(Enter));
    
  case MACRO_DOUBLE_AMP:
    return MACRODOWN(D(LeftShift), T(7), T(7), U(LeftShift));
    
  case MACRO_DOUBLE_PIPE:
    return MACRODOWN(D(LeftShift), T(Backslash), T(Backslash), U(LeftShift));
  
  case MACRO_DOUBLE_EQUAL:
    return MACRODOWN(T(Equals), T(Equals));
    
  case MACRO_TRIPLE_EQUAL:
    return MACRODOWN(T(Equals), T(Equals), T(Equals));
    
  case MACRO_PLUS_EQUAL:
    return MACRODOWN(D(LeftShift), T(Equals), U(LeftShift), T(Equals));
    
  case MACRO_MINUS_EQUAL:
    return MACRODOWN(T(Minus), T(Equals));
  }
  
  return MACRO_NONE;
}

static kaleidoscope::LEDSolidColor solidRed(160, 0, 0);
static kaleidoscope::LEDSolidColor solidOrange(140, 70, 0);
static kaleidoscope::LEDSolidColor solidYellow(130, 100, 0);
static kaleidoscope::LEDSolidColor solidGreen(0, 160, 0);
static kaleidoscope::LEDSolidColor solidBlue(0, 70, 130);
static kaleidoscope::LEDSolidColor solidViolet(130, 0, 120);

void toggleLedsOnSuspendResume(kaleidoscope::HostPowerManagement::Event event) {
  switch (event) {
  case kaleidoscope::HostPowerManagement::Suspend:
    LEDControl.paused = true;
    LEDControl.set_all_leds_to({0, 0, 0});
    LEDControl.syncLeds();
    break;
  case kaleidoscope::HostPowerManagement::Resume:
    LEDControl.paused = false;
    LEDControl.refreshAll();
    break;
  case kaleidoscope::HostPowerManagement::Sleep:
    break;
  }
}

void hostPowerManagementEventHandler(kaleidoscope::HostPowerManagement::Event event) {
  toggleLedsOnSuspendResume(event);
}

KALEIDOSCOPE_INIT_PLUGINS(
  Qukeys,
  BootGreetingEffect,

  // The hardware test mode, which can be invoked by tapping Prog, LED and the left Fn button at the same time.
  TestMode,
  LEDControl,
  LEDOff,
  LEDRainbowEffect,
  LEDRainbowWaveEffect,
  LEDChaseEffect,
  solidRed, solidOrange, solidYellow, solidGreen, solidBlue, solidViolet,
  LEDBreatheEffect,
  StalkerEffect,
  Macros,
  HostPowerManagement,
  USBQuirks
);

/** The 'setup' function is one of the two standard Arduino sketch functions.
 * It's called when your keyboard first powers up. This is where you set up
 * Kaleidoscope and any plugins.
 */
void setup() {
  QUKEYS(
    kaleidoscope::Qukey(PRIMARY,  2,  0, Key_LeftControl),
    kaleidoscope::Qukey(PRIMARY,  3,  0, Key_LeftAlt),
    kaleidoscope::Qukey(PRIMARY,  3,  1, Key_LeftGui),
    kaleidoscope::Qukey(PRIMARY,  2, 15, Key_RightControl),
    kaleidoscope::Qukey(PRIMARY,  3, 15, Key_RightAlt),
    kaleidoscope::Qukey(PRIMARY,  3, 14, Key_RightGui)
  );
    
  // First, call Kaleidoscope's internal setup function
  Kaleidoscope.setup();

  // We set the brightness of the rainbow effects to 150 (on a scale of 0-255)
  // This draws more than 500mA, but looks much nicer than a dimmer effect
  LEDRainbowEffect.brightness(150);
  LEDRainbowWaveEffect.brightness(150);

  // The LED Stalker mode has a few effects. The one we like is
  // called 'BlazingTrail'. For details on other options,
  // see https://github.com/keyboardio/Kaleidoscope-LED-Stalker
  StalkerEffect.variant = STALKER(BlazingTrail);
  StalkerEffect.step_length = 100;

  // We want to make sure that the firmware starts with LED effects off
  // This avoids over-taxing devices that don't have a lot of power to share
  // with USB devices
  LEDOff.activate();
}

void loop() {
  Kaleidoscope.loop();
}
