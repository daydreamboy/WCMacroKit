//
//  WCMacroColor.h
//  WCMacroKit
//
//  Created by wesley chen on 16/8/28.
//
//

#ifndef WCMacroColor_h
#define WCMacroColor_h

// Color
#pragma mark - Color

#define _A_COLOR(color)          (((color) >> 24) & 0xFF)
#define _R_COLOR(color)          (((color) >> 16) & 0xFF)
#define _G_COLOR(color)          (((color) >> 8) & 0xFF)
#define _B_COLOR(color)          ((color) & 0xFF)

#ifndef UICOLOR_ARGB
#define UICOLOR_ARGB(color)      [UIColor colorWithRed: (((color) >> 16) & 0xFF) / 255.0 green: (((color) >> 8) & 0xFF) / 255.0 blue: ((color) & 0xFF) / 255.0 alpha: (((color) >> 24) & 0xFF) / 255.0]
#endif

#ifndef UICOLOR_RGB
#define UICOLOR_RGB(color)       [UIColor colorWithRed: (((color) >> 16) & 0xFF) / 255.0 green: (((color) >> 8) & 0xFF) / 255.0 blue: ((color) & 0xFF) / 255.0 alpha: 1.0]
#endif

#endif /* WCMacroColor_h */
