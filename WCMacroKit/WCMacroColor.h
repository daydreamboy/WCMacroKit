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

// 0xRRGGBBAA
#define UICOLOR_R_COLOR(color) (((color) >> 24) & 0xFF)
#define UICOLOR_G_COLOR(color) (((color) >> 16) & 0xFF)
#define UICOLOR_B_COLOR(color) (((color) >> 8) & 0xFF)
#define UICOLOR_A_COLOR(color) ((color) & 0xFF)

// 0xRRGGBBAA
#ifndef UICOLOR_RGBA
#define UICOLOR_RGBA(color) ([UIColor colorWithRed: (((color) >> 24) & 0xFF) / 255.0 green: (((color) >> 16) & 0xFF) / 255.0 blue: (((color) >> 8) & 0xFF) / 255.0 alpha: ((color) & 0xFF) / 255.0])
#endif

// 0xRRGGBB
#ifndef UICOLOR_RGB
#define UICOLOR_RGB(color) ([UIColor colorWithRed: (((color) >> 16) & 0xFF) / 255.0 green: (((color) >> 8) & 0xFF) / 255.0 blue: ((color) & 0xFF) / 255.0 alpha: 1.0])
#endif

#ifndef UICOLOR_randomColor
#define UICOLOR_randomColor [UIColor colorWithRed:(arc4random() % 255 / 255.0f) green:(arc4random() % 255 / 255.0f) blue:(arc4random() % 255 / 255.0f) alpha:1]
#endif

#ifndef UICOLOR_randomRGBAColor
#define UICOLOR_randomRGBAColor [UIColor colorWithRed:(arc4random() % 255 / 255.0f) green:(arc4random() % 255 / 255.0f) blue:(arc4random() % 255 / 255.0f) alpha:(arc4random() % 10 / 10.0f)]
#endif

#endif /* WCMacroColor_h */
