//
//  WCMacroCompatibility.h
//  WCMacroKit
//
//  Created by wesley_chen on 15/11/2017.
//

#ifndef WCMacroCompatibility_h
#define WCMacroCompatibility_h

#if __has_include(<WCMacroKit/WCMacroVersion.h>)
#import <WCMacroKit/WCMacroVersion.h>
#else
#import "WCMacroVersion.h"
#endif

#pragma mark - Compatible with lower compiler iOS SDK

// NSAttributedStringKey available on iOS 11+
#if __IPHONE_OS_VERSION_MAX_ALLOWED < 110000
#define NSAttributedStringKey   (NSString *)
#endif

#pragma mark - Check Device Model

// http://stackoverflow.com/a/13156390/4794665
// UI_USER_INTERFACE_IDIOM() deprecated in iOS 13+, @see https://stackoverflow.com/questions/24059327/detect-current-device-with-ui-user-interface-idiom-in-swift
#define IS_IPAD             ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPad)
#define IS_IPHONE           ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone)
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

#pragma mark - Check Device Orientation

/**
 Check device current orientation if portrait
 @sa UIDeviceOrientationIsPortrait() which available on iOS 8.3+
*/
#define IS_ORIENTATION_PORTRAIT (([[UIDevice currentDevice] orientation]) == UIDeviceOrientationPortrait || ([[UIDevice currentDevice] orientation]) == UIDeviceOrientationPortraitUpsideDown)
/**
 Check device current orientation if landscape
 @sa UIDeviceOrientationIsLandscape() which available on iOS 8.3+
 */
#define IS_ORIENTATION_LANDSCAPE (([[UIDevice currentDevice] orientation]) == UIDeviceOrientationLandscapeLeft || ([[UIDevice currentDevice] orientation]) == UIDeviceOrientationLandscapeRight)

#pragma mark - Complie with lower Base SDK

// >= `14.0` Base SDK
#if defined(__IPHONE_14_0)
#define IOS14_SDK_OR_LATER_AVAILABLE 1
#else
#define IOS14_SDK_OR_LATER_AVAILABLE 0
#endif

// >= `13.0` Base SDK
#if defined(__IPHONE_13_0)
#define IOS13_SDK_OR_LATER_AVAILABLE 1
#else
#define IOS13_SDK_OR_LATER_AVAILABLE 0
#endif

// >= `12.0` Base SDK
#if defined(__IPHONE_12_0)
#define IOS12_SDK_OR_LATER_AVAILABLE 1
#else
#define IOS12_SDK_OR_LATER_AVAILABLE 0
#endif

// >= `11.0` Base SDK
#if defined(__IPHONE_11_0)
#define IOS11_SDK_OR_LATER_AVAILABLE 1
#else
#define IOS11_SDK_OR_LATER_AVAILABLE 0
#endif

// >= `10.0` Base SDK
#if defined(__IPHONE_10_0)
#define IOS10_SDK_OR_LATER_AVAILABLE 1
#else
#define IOS10_SDK_OR_LATER_AVAILABLE 0
#endif

// >= `9.0` Base SDK
#if defined(__IPHONE_9_0)
#define IOS9_SDK_OR_LATER_AVAILABLE 1
#else
#define IOS9_SDK_OR_LATER_AVAILABLE 0
#endif

// >= `8.0` Base SDK
#if defined(__IPHONE_8_0)
#define IOS8_SDK_OR_LATER_AVAILABLE 1
#else
#define IOS8_SDK_OR_LATER_AVAILABLE 0
#endif

#pragma mark - Counterpart of Swift clause

/**
 iflet macro which counterpart with Swift if-let clause
 
 @param var_decl declare a variable
 @param value a value or a clause which must not contain comma ','
 
 @code
 Swift:
 if let result = computeResult() {
     // do something with result
 }
 
 Objective-C:
 iflet(NSString *value, [self returnNil]) {
     NSString *newValue = [NSString stringWithFormat:@"%@", value];
     NSLog(@"%@", newValue);
 }
 else {
     NSLog(@"value is nil");
 }
 @endcode
 
 @discussion if value is nil, the body block will not execute
 @note see ifletwhere for more details
 */
#define iflet(var_decl, value) \
    ifletwhere(var_decl, value, YES)

/**
 iflet strengthened macro which counterpart with Swift if-let clause
 
 @param var_decl declare a variable
 @param value a value or a clause which must not contain comma ','
 @param where the condition clause which also determine body block if will be executed
 
 @code
 Objective-C:
 ifletwhere(NSString *value, [self maybeReturnNil], [value isKindOfClass:[NSString class]]) {
     NSString *newValue = [NSString stringWithFormat:@"%@", value];
     NSLog(@"%@", newValue);
 }
 else {
     NSLog(@"value is nil");
 }
 @endcode
 
 @discussion if value is nil, the body block will not execute
 @see simple version: http://blog.cristik.com/2016/01/if-let-statement-in-objective-c/
 @see https://gist.github.com/CraigSiemens/bcdefff3880c508ad2b1
 */
#define ifletwhere(var_decl, value, where) \
    for (BOOL b_ = YES; b_ != NO; b_ = NO) \
        for (id obj_ = (value); b_ != NO; b_ = NO) \
            for (var_decl = obj_; b_ != NO; b_ = NO) \
                if (obj_ != nil && (where))

#endif /* WCMacroCompatibility_h */
