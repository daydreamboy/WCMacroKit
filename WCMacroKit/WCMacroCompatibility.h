//
//  WCMacroCompatibility.h
//  WCMacroKit
//
//  Created by wesley_chen on 15/11/2017.
//

#ifndef WCMacroCompatibility_h
#define WCMacroCompatibility_h

#pragma mark - Compatible with lower compiler iOS SDK

// NSAttributedStringKey available on iOS 11+
#if __IPHONE_OS_VERSION_MAX_ALLOWED < 110000
#define NSAttributedStringKey   (NSString *)
#endif

#pragma mark - Check Device Model

// http://stackoverflow.com/a/13156390/4794665
#define IS_IPAD             (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
#define IS_IPHONE           (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
#define IS_RETINA           ([[UIScreen mainScreen] scale] >= 2.0)
#define SCREEN_WIDTH        ([[UIScreen mainScreen] bounds].size.width)
#define SCREEN_HEIGHT       ([[UIScreen mainScreen] bounds].size.height)
#define SCREEN_MAX_LENGTH   (MAX(SCREEN_WIDTH, SCREEN_HEIGHT))
#define SCREEN_MIN_LENGTH   (MIN(SCREEN_WIDTH, SCREEN_HEIGHT))

// @see https://www.paintcodeapp.com/news/ultimate-guide-to-iphone-resolutions

// iPhone 3GS or iPhone 3G or iPhone 2G (@1x)
#define IS_IPHONE_3_OR_LESS   (IS_IPHONE && SCREEN_MAX_LENGTH == 480.0 && [UIScreen mainScreen].scale == 1.0)

// iPhone 4 or iPhone 4s (@2x)
#define IS_IPHONE_4_OR_4S   (IS_IPHONE && SCREEN_MAX_LENGTH == 480.0 && [UIScreen mainScreen].scale == 2.0)

// iPhone 4 or iPhone 4s (@2x)
// or
// iPhone 2G or iPhone 3G or iPhone 3GS (@1x)
#define IS_IPHONE_4_OR_LESS (IS_IPHONE && SCREEN_MAX_LENGTH < 568.0)

// iPhone 5 or iPhone 5s or iPhone 5c or iPhone SE (@2x)
#define IS_IPHONE_5_OR_5S_OR_5C_OR_SE   (IS_IPHONE && SCREEN_MAX_LENGTH == 568.0)

// iPhone 6 or iPhone 6s or iPhone 7 or iPhone 8 (@2x)
#define IS_IPHONE_6_OR_6S_OR_7_OR_8 (IS_IPHONE && SCREEN_MAX_LENGTH == 667.0)

// iPhone 6P or iPhone 6SP or iPhone 7P or iPhone 8P (@3x)
#define IS_IPHONE_6P_OR_6SP_OR_7P_OR_8P (IS_IPHONE && SCREEN_MAX_LENGTH == 736.0)

// iPhone X or iPhone Xs (@3x)
// @see https://stackoverflow.com/questions/46196964/detect-iphone-x-with-a-macro
#define IS_IPHONE_X_OR_XS   (IS_IPHONE && SCREEN_MAX_LENGTH == 812.0)

// iPhone Xr (@2x)
#define IS_IPHONE_XR    (IS_IPHONE && SCREEN_MAX_LENGTH == 896.0 && [UIScreen mainScreen].scale == 2.0)

// iPhone Xs Max (@3x)
#define IS_IPHONE_XS_MAX    (IS_IPHONE && SCREEN_MAX_LENGTH == 896.0 && [UIScreen mainScreen].scale == 3.0)

// iPad Pro
#define IS_IPAD_PRO         (IS_IPAD && SCREEN_MAX_LENGTH == 1366.0)

#endif /* WCMacroCompatibility_h */
