//
//  WCMacroTime.h
//  WCMacroKit
//
//  Created by wesley_chen on 2024/8/28.
//

#ifndef WCMacroTime_h
#define WCMacroTime_h

#pragma mark - Time

#define TIME_UNIX_TIMESTAMP ([NSString stringWithFormat:@"%f", [[NSDate date] timeIntervalSince1970]])

/**
 Get current file modification timestamp
 
 @return get a NSString. Return nil if any error occurred
 
 @note This timestamp only update after file modified
 */
#define MODIFY_TIME_FOR_CURRENT_FILE ({ \
    NSString *timestamp = nil; \
    const char *cString = __TIMESTAMP__; \
    if (cString != NULL) { \
        timestamp = [[NSString alloc] initWithUTF8String:cString]; \
    } \
    timestamp; \
})

/**
 Get current file build timestamp
 
 @return get a NSString
 
 @note This timestamp update after this file is compiled
 */
#define BUILD_TIME_FOR_CURRENT_FILE ({ \
    NSMutableString *timestamp = [NSMutableString string]; \
    const char *cString1 = __TIME__; \
    const char *cString2 = __DATE__; \
    if (cString1 != NULL) { \
        [timestamp appendString:[[NSString alloc] initWithUTF8String:cString1]]; \
    } \
    if (cString2 != NULL) { \
        [timestamp appendString:@"@"]; \
        [timestamp appendString:[[NSString alloc] initWithUTF8String:cString2]]; \
    } \
    timestamp; \
})

#pragma mark - Dispatch Time

#define DISPATCH_TIME_IN_SEC(seconds) (dispatch_time(DISPATCH_TIME_NOW, (int64_t)(seconds * NSEC_PER_SEC)))


#endif /* WCMacroTime_h */
